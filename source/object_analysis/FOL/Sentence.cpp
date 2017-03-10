// AUTHOR: NA
// DATE: 02/13/17
// DESC: Implementation of Sentence structure
// FILE: Sentence.cpp

#include <iostream>
#include <list>
#include <string>
#include "../FOL/Sentence.h"

bool Sentence::operator<(Sentence rhs) const
{
    if(sen.size() != rhs.sen.size()){
        return sen.size() < rhs.sen.size();
    }
    //for(unsigned i = 0; i != sen.size(); ++i){
    auto it = sen.cbegin(), rhs_it = rhs.sen.cbegin();
    while(it != sen.cend() && rhs_it != rhs.sen.cend() ){
        if(it->name != rhs_it->name){
                return it->name < rhs_it->name;
        }
        else if(it->type != rhs_it->type){
            return it->type < rhs_it->type;
        }
        ++it;
        ++rhs_it;
    }
    return false;
}

std::list<Atom> Sentence::getSen()
{
    return sen;
}

void Sentence::addAtom(Atom term, long index)
{
	if(index >= sen.size()){
		sen.push_back(term);
	}
	else if(index <= 0){
		sen.push_front(term);
	}
	else{
		auto sen_it = sen.begin();
		for(auto i = 0; i < index; ++i){
			++sen_it;
		}
		sen.insert(sen_it, term);
	}
}

void Sentence::removeAtom(Atom term, long index)
{
	if(index >= sen.size()){
		sen.pop_back();
	}
	else if(index <= 0){
		sen.pop_front();
	}
	else{
		auto sen_it = sen.begin();
		for(auto i = 0; i < index; ++i){
			++sen_it;
		}
		sen.erase(sen_it);
	}
}

bool Sentence:: isSentence()
{
	return isAtomic() || isComplex();
}

bool Sentence::isAtomic()
{
	
	if(sen.size() == 1 && sen.begin()->type != AtomType::OPERATOR){
		return true;
	}
	return false;
}

bool Sentence::isComplex()
{
	if(sen.size() > 1){
		auto sen_it = sen.begin();
		while(++sen_it != sen.end()){
			if(sen_it->type != AtomType::OPERATOR){
			return true;
			}
		}
	}
	return false;
}
