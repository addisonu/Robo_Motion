// AUTHOR: NA
// DATE: 03/07/17
// DESC: The basic unit of first-order logic
// FILE: Atom.h


#ifndef FOL_ATOM_H
#define FOL_ATOM_H

#include<vector>
#include <string>
#include<iostream>

enum class AtomType{
    FUNCTION = 0,
    PREDICATE,
    OPERATOR,
    RELATION,
    CONSTANT,
    OBJECT,
};

class Atom{
    public:

        // CONSTRUCTOR
        
    private:

        // DATA MEMBERS
        std::string name;
        AtomType type;
};

#endif


