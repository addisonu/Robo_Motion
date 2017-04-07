// AUTHOR: NA
// DATE: 03/07/17
// DESC: Definition of Sentence structure
// FILE: Sentence.h

#ifndef FOL_SENTENCE_H
#define FOL_SENTENCE_H

#include <iostream>
#include <list>
#include <string>
#include "../FOL/Atom.h"

struct Sentence{
	//public:

	// CONSTRUCTOR


	// MEMBER FUNCTIONS
        bool operator<(Sentence rhs) const
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
	
	bool operator==(Sentence rhs) const
	{
		if(sen.size() != rhs.sen.size()){
			return false;
		}	
		auto sen_it = sen.cbegin();
		auto rhs_sen_it = rhs.sen.cbegin();
		for(; sen_it != sen.cend() && rhs_sen_it != rhs.sen.cend(); ++sen_it, ++rhs_sen_it){
			if(*sen_it != *rhs_sen_it){
				return false;
			}
		}
		return true;
	}

	std::list<Atom>::iterator begin()
	{
		return sen.begin();
	}

	std::list<Atom>::const_iterator cbegin()
	{
		return sen.cbegin();
	}

	std::list<Atom>::iterator end()
	{
		return sen.end();
	}

	std::list<Atom>::const_iterator cend()
	{
		return sen.cend();
	}

	std::list<Atom> getSen();
	void addAtom(Atom term, long index = std::string::npos);
	void removeAtom(Atom term, long index = std::string::npos);
	bool isSentence();
	bool isAtomic();
	bool isComplex();

	//private:

	// DATA MEMBERS
	std::list<Atom> sen;
};
#endif
