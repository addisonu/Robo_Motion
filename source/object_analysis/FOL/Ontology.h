// AUTHOR: NA
// DATE: 03/07/17
// DESC: Definition of Sentence structure
// FILE: Ontology.h

#ifndef FOL_ONTOLOGY_H
#define FOL_ONTOLOGY_H

#include <set>
#include <iostream>
#include "Atom.h"

enum class ObjectType{
	AGENT = 0,
	DYNAMIC_MAMMAL,
	STATIC_MAMMAL,
	DYNAMIC_PLANT,
	STATIC_PLANT,
	DYNAMIC_INORGANIC_NATURAL,
	STATIC_INORGANIC_NATURAL,
	DYNAMIC_SYNTHETIC,
	STATIC_SYNTHETIC,
};

class Ontology{

	public:

	// CONSTRUCTOR
	
	// FUNCTION
	void addFunction(Atom function);
	bool removeFunction(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllFunction();

	// PREDICATE
	void addPredicate(Atom predicate);
	bool removePredicate(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllPredicate();

	// RELATION
	void addRelation(Atom predicate);
	bool removeRelation(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllRelation();
	

	// OBJECT
	void addObject(Atom object);
	bool removeObject(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllObject();

	// CONSTANT
	void addConstant(Atom constant);
	bool removeConstant(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllConstant();

	private:
	std::pair<AtomType, std::set<Atom> > all_object;
	std::pair<AtomType, std::set<Atom> > all_constant;
	std::pair<AtomType, std::set<Atom> > all_predicate;
	std::pair<AtomType, std::set<Atom> > all_function;
	std::pair<AtomType, std::set<Atom> > all_relation;
	
};

#endif
