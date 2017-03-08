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

class Sentence{
	public:

	// CONSTRUCTOR


	// MEMBER FUNCTIONS
	void addAtom(Atom term, long index = std::string::npos);
	void removeAtom(Atom term, long index = std::string::npos);
	bool isSentence();
	bool isAtomic();
	bool isComplex();

	private:

	// DATA MEMBERS
	std::list<Atom> sen;
};
#endif
