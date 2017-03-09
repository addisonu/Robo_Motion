// AUTHOR: NA
// DATE: 03/07/17
// DESC: Definition of knowledge base vocabulary
// FILE: Ontology.h

#ifndef FOL_ONTOLOGY_H
#define FOL_ONTOLOGY_H

#include <set>
#include <iostream>
#include "../FOL/Atom.h"

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
	unsigned priority(ObjectType obj);
	unsigned robustness(ObjectType obj);
        std::pair<int, int> position(Atom constant);

	// PREDICATE
	void addPredicate(Atom predicate);
	bool removePredicate(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllPredicate();
	bool hasPercept(ObjectType obj);
	bool hasActuator(ObjectType obj);

	// RELATION
	void addRelation(Atom predicate);
	bool removeRelation(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllRelation();
	std::set<Atom> isNorth(ObjectType obj);
	std::set<Atom> isEast(ObjectType obj);
	std::set<Atom> isSouth(ObjectType obj);
	std::set<Atom> isWest(ObjectType obj);
	
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
