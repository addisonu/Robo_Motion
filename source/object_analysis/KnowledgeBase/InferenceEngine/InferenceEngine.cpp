// DATE: 03/25/17
// DESC: The implementation for the inference engine which will entail new sentences from those in the knowledge repo
// FILE: Inference.cpp

#include <vector>
#include <algorithm>
#include "InferenceEngine.h"

std::set<Sentence> InferenceEngine::makeDefiniteClauseKB(std::set<Sentence> kb, Atom query)
{
	
}

Sentence InferenceEngine::backChaining()
{

}

std::pair<Sentence, bool> InferenceEngine::forwardChaining()
{
	std::set<Sentence> all_entailed, new_sen;
	// while there are new sentences entailed
	do{
	// for each rule in the KB	
	for(auto sent : kb){
		// standardize rule variables
		// for each successful substituion of constant theta
		for(auto theta : /*all constants*/){
			// add element to KB
			// if rho and alpha unify return rho
	// add all new to KB
		}		
	
	}
	}while(new_sen.size() > 0);	
	// return false;
}

bool InferenceEngine::unification(Sentence lhs, Sentence rhs)
{

}
