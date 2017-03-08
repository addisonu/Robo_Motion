// AUTHOR: NA
// DATE: 03/07/17
// DESC: The definition for logic quantifiers
// FILE: Quantifier.h

#ifndef FOL_QUANTIFIER_H
#define FOL_QUANTIFIER_H

#include <set>
#include "Atom.h"

template <typename T, typename F> class Quantifier{
	public:

	// CONSTRUCTOR
	
	// MEMBERS
	bool forAll(const std::set<T> &object_set, F *function);

	bool thereExists(const std::set<T> &object_set, F *function);
};

// make more general, possible using vardiac templates
template <typename T, typename F> bool Quantifier<T, F>::forAll(const std::set<T> &object_set, F *function)
{
	for(unsigned i = 0; i != object_set.size(); ++i){
		if(!function(object_set[i])){
			return false;
		}
	}	
	return true;
}

// make more general, possible using vardiac templates
template <typename T, typename F> bool Quantifier<T, F>::thereExists(std::set<T> const &object_set, F *function)
{
	for(unsigned i = 0; i != object_set.size(); ++i){
		if(function(object_set[i])){
			return true;
		}	
	}
	false;
}

#endif
