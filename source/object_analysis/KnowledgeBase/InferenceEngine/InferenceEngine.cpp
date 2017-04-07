// AUTHOR: NA
// DATE: 03/25/17
// DESC: The implementation for the inference engine which will entail new sentences from those in the knowledge repo
// FILE: Inference.cpp

#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include "InferenceEngine.h"
#include "../../FOL/Sentence.h"
#include "../Ontology.h"

std::pair<Atom, Atom> InferenceEngine::backChaining(Sentence query)
{
    std::pair<Atom, Atom> sub;
    for(auto sen : kb){
        Sentence std_sen = standardizeRule(sen);
        auto result = unify(query, std_sen);
        for(auto std_ele : std_sen){
            if(result.size() == 0){
                break;
            }
        }
    }
    return sub;
}

std::pair<Atom, Atom> InferenceEngine::forwardChaining(Sentence query)
{
    bool unified = true;
    std::pair<Atom, Atom> sub = std::make_pair(Atom("var", AtomType::OBJECT), Atom("constant", AtomType::CONSTANT));
    std::set<Sentence> infer_set;
    do{
        for(auto sen : kb){
            Sentence std_sen = standardizeRule(sen);
            if(std_sen.sen.size() != 0){
                auto result = unify(query, std_sen);
                for(auto result_ele : result){
                    auto query_it = query.end();
                    Sentence q;
                    q.sen.push_back(*(--query_it));
                    std::set<std::pair<Atom, Atom> > unify_q;
                    for(auto sen : kb){
                        std::set<std::pair<Atom, Atom> > tmp_unify = unify(q, sen);
                        for(auto sub : tmp_unify){
                            unify_q.insert(sub);
                        }
                        if(unify_q.size() == 0){
                            infer_set.insert(q);
                        }
                        else{
                            unified = false;
                            break;
                        }
                    }
                }
            }
        }
    }while(unified);

    return sub;
}

/* put a sentence in definite clause form
 * as a disjuntion of literals of which one is postive
 * or as an imlplication with a premise of conjunctions of positive literals and positive result
*/
Sentence InferenceEngine::makeDefiniteClause(Sentence alpha)
{	
	// check if Sentence is an implication
	std::list<Atom>::iterator sen_it = alpha.sen.begin();

	for(; sen_it != alpha.sen.end(); ++sen_it){
		if(sen_it->type == AtomType::OPERATOR && sen_it->name == "IMPLY"){
			if(++sen_it != alpha.sen.end()){
				if(++sen_it != alpha.sen.end()){
					Sentence first_part, last_part;
					std::list<Atom> first(alpha.begin(), sen_it);
					std::list<Atom> last(sen_it, alpha.end());
					
					// place iterator back to where imply operator was found
					--sen_it;
					--sen_it;
					
					// merger partial sentences and append consequent
					first_part.sen.merge(last_part.sen);
					Sentence definite_clause(first_part);
					definite_clause.sen.push_back(*sen_it);
					definite_clause.sen.push_back(*(++sen_it));
					return definite_clause;
				}			
			}
		}
	}
	
	// if not an implication, convert to group of literal disjuntions with single positive term

	// make last term positive
	std::list<Atom>::reverse_iterator sen_rit = alpha.sen.rbegin();

	if(sen_rit->name[0] == '-'){
		sen_rit->name = sen_rit->name.substr(1);
	}

	// make all preceding terms negative disjunctions
	for(; sen_rit != alpha.sen.rend(); ++sen_rit){
		if(sen_rit->type == AtomType::OPERATOR && sen_rit->name == "AND"){
			sen_rit->name = "OR";
		}
		else if(sen_rit->type == AtomType::PREDICATE || sen_rit->type == AtomType::OBJECT ||sen_rit->type == AtomType::CONSTANT){ 
			if(sen_rit->name[0] != '-'){
				sen_rit->name = std::string('-' + sen_rit->name);
			}
		}
	}
	return alpha;
}

// Entail senences from those in kb
std::set<std::pair<Atom, Atom> > InferenceEngine::unify(Sentence lhs, Sentence rhs)
{
	std::set<std::pair<Atom, Atom> > sub_result;
	Atom variable("var", AtomType::OBJECT);

	for(auto constant : ontology.getAllConstant().second){
		for(auto &lhs_ele : lhs){
			if(lhs_ele.type == AtomType::OBJECT){
				lhs_ele = constant;
			}
		}
		for(auto &rhs_ele : rhs){
			if(rhs_ele.type == AtomType::OBJECT){
				rhs_ele = constant;
			}
		}
		for(auto sen : kb){
			if(sen == rhs || sen == lhs){
				variable.incrementObjectName();
				sub_result.insert(std::make_pair(variable, constant));
			}
		}
	}

	return sub_result;
}

// return a true if constants have been found that make the argument sentence true
bool InferenceEngine::substitution(std::set<std::pair<Atom, Atom> > &theta, ComplexAtom alpha, unsigned arg_index)
{
	if(alpha.arity < arg_index){
		return false;
	}
	// Check all sentences in knowledge base for match
	for(auto fact : kb){
		for(auto part : fact){
			if((alpha.type == AtomType::OBJECT || alpha.type == AtomType::PREDICATE || alpha.type == AtomType::FUNCTION) && part.type == alpha.type && part.name == alpha.name){
				
				Atom first("x", AtomType::OBJECT);
				
				if(theta.size() > 0){
					first.name = theta.rend()->first.name;
					first.incrementObjectName();
				}
				Atom second(part);
				theta.insert(std::make_pair(first, second));
			}
		}
	}
	
	return theta.size();
}

// return a set of sentences inferred by substituting all kb constants into the argument sentence
std::set<Sentence> InferenceEngine::universalInstatiation(Sentence alpha)
{
	std::set<Sentence> all_infer_sen;
	for(auto sent : kb){
		for(auto ele : sent){
			if(ele.type == AtomType::CONSTANT){
				Sentence tmp(alpha);
				for(auto &tmp_ele : tmp){
					if(tmp_ele.type == AtomType::OBJECT){
						tmp_ele = ele;
					}
				}
				all_infer_sen.insert(tmp);
			}
		}
	}	
	
	return all_infer_sen;
}

// return a copy of the argument sentence for which the variable has been substituted by a new constant symbol
Sentence InferenceEngine::existentialInstatiation(std::set<std::pair<std::string, Sentence> > theta, Sentence alpha)
{
	Atom tmp_atom(new_constant, AtomType::CONSTANT);
	tmp_atom.incrementObjectName();
	Sentence tmp(alpha);

	for(auto &tmp_ele : tmp){
		if(tmp_ele.type == AtomType::OBJECT){
			tmp_ele = tmp_atom;
		}
	}
	return tmp;
}

Sentence InferenceEngine::standardizeRule(Sentence rule)
{
	std::vector<std::string> all_obj_name;
	// iterate through all sentence Atom, change the name of any object so that it has a unique name

	for(auto atom_obj : rule){
		if(atom_obj.type == AtomType::OBJECT){
			if(!all_obj_name.empty()){
				for(auto name : all_obj_name){
					if(atom_obj.name == name){
						atom_obj.incrementObjectName();
					}
				}
			}
			all_obj_name.push_back(atom_obj.name);
		}
	}
	return rule;
}
