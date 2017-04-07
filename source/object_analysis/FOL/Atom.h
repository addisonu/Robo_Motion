// AUTHOR: NA
// DATE: 03/07/17
// DESC: The basic unit of first-order logic
// FILE: Atom.h


#ifndef FOL_ATOM_H
#define FOL_ATOM_H

#include <vector>
#include <sstream>
#include <string>
#include <iostream>

enum class AtomType{
    FUNCTION = 0,
    PREDICATE,
    OPERATOR,
    RELATION,
    CONSTANT,
    OBJECT,// is an identifier or variable
    LHS_PAREN,
    RHS_PAREN,
    NONE,
};

struct Atom{

	// CONSTRUCTOR
	Atom()
        {
            name = "null_name";
            type = AtomType::NONE;
        }

	Atom(std::string name_arg, AtomType type_arg): name(name_arg), type(type_arg){ }

	bool operator<(Atom rhs) const
	{
		return name < rhs.name;
	}

	bool operator==(Atom rhs) const
	{
		return (name == rhs.name) && (type == rhs.type);
	}

	bool operator!=(Atom rhs) const
	{
		return !(*this == rhs);
	}

	void incrementObjectName()
	{
		// Find first digit of identifier
		std::stringstream name_dig, name_next_dig;
		std::size_t first_dig = name.find_first_of("0123456789");
		name_dig << name.substr(first_dig);
		long dig;
		name_dig >> dig ;
		++dig;
		name_next_dig << dig;
		
		name = name.substr(0, first_dig + 1) + name_next_dig.str();
	}

	// DATA MEMBERS
	std::string name;
	AtomType type;

};

struct ComplexAtom : public Atom{
	
	// CONSTRUCTOR
	
	// DATA MEMBERS
	std::vector<Atom> arg;
	unsigned arity;
};
#endif


