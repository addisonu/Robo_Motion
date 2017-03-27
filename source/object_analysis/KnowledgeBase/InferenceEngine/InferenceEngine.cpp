// DATE: 03/25/17
// DESC: The implementation for the inference engine which will entail new sentences from those in the knowledge repo
// FILE: Inference.cpp

#include <vector>
#include <set>
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

Sentence InferenceEngine::subst(std::set<std::pair<std::string, Sentence> > theta, Sentence alpha)
{
	Sentence s;
	return s;

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
}
