// AUTHOR: NA
// DATE: 03/07/17
// DESC: The basic unit of first-order logic
// FILE: Atom.h


#ifndef FOL_ATOM_H
#define FOL_ATOM_H

#include <vector>
#include <string>
#include <iostream>

enum class AtomType{
    FUNCTION = 0,
    PREDICATE,
    OPERATOR,
    RELATION,
    CONSTANT,
    OBJECT,
    NONE,
};

struct Atom{
    public:

        // CONSTRUCTOR
	//Atom(){ }

	Atom(std::string name_arg, AtomType type_arg): name(name_arg), type(type_arg){ }

        bool operator<(Atom rhs)
        {
            return name < rhs.name;
        }

        // DATA MEMBERS
        std::string name;
        AtomType type;
};
#endif


