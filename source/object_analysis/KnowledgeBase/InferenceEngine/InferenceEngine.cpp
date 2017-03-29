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

Sentence InferenceEngine::backChaining(std::set<Sentence> kb)
{
	Sentence s;
	return s;

}

std::pair<Sentence, bool> InferenceEngine::forwardChaining(std::set<Sentence> kb)
{
	std::pair<Sentence, bool> s;
	std::set<Sentence> all_entailed, new_sen;
	// while there are new sentences entailed
	do{
	// for each rule in the KB	
	for(auto sent : kb){
		// standardize rule variables
		// for each successful substituion of constant theta
		//for(auto theta : /*all constants*/){
			// add element to KB
			// if rho and alpha unify return rho
	// add all new to KB
		//}		
	
	}
	}while(new_sen.size() > 0);	
	 return s;
}

std::set<Sentence> InferenceEngine::makeDefiniteClauseKB(std::set<Sentence> kb, Atom query)
{
	std::set<Sentence> s;
	return s;
}

bool InferenceEngine::unify(Sentence lhs, Sentence rhs)
{
	return true;
}

bool InferenceEngine::substitution(std::set<std::pair<Atom, Atom> > &theta, ComplexAtom alpha, unsigned arg_index)
{
	// Check argument types
	if(alpha.arity < arg_index/*theta.first.AtomType != AtomType::OBJECT && theta.second.AtomType != AtomType::VARIABLE*/){
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

Sentence InferenceEngine::universalInstatiation(std::set<std::pair<std::string, Sentence> > theta, Sentence alpha)
{
	Sentence s;
	return s;

}

Sentence InferenceEngine::existentialInstatiation(std::set<std::pair<std::string, Sentence> > theta, Sentence alpha)
{
	Sentence s;
	return s;
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
