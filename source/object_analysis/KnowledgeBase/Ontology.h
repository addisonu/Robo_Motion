// AUTHOR: NA
// DATE: 03/07/17
// DESC: Definition of knowledge base vocabulary
// FILE: Ontology.h

#ifndef FOL_ONTOLOGY_H
#define FOL_ONTOLOGY_H

#include <set>
#include <iostream>
#include "../FOL/Atom.h"
#include "../FOL/Object.h"

class Ontology{

	public:

	// CONSTRUCTOR
	
	// FUNCTION
	void addFunction(Atom function);
	bool removeFunction(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllFunction();
	unsigned priority(ObjectType obj);
	unsigned robustness(ObjectType obj);
	void setPosition(Atom object, int x_coor, int y_coor);
	std::pair<int, int> getPosition(Atom object);

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
	std::set<Atom> isNorth(Atom obj, std::set<Atom> all_obj);
	std::set<Atom> isEast(Atom obj, std::set<Atom> all_obj);
	std::set<Atom> isSouth(Atom obj, std::set<Atom> all_obj);
	std::set<Atom> isWest(Atom obj, std::set<Atom> all_obj);
	
	// OBJECT
	void addObject(Atom object);
	bool removeObject(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllObject();

	// CONSTANT
	void addConstant(Atom constant);
	bool removeConstant(std::string name);
	std::pair<AtomType, std::set<Atom> > getAllConstant();

	// OTHER
	std::string recommendAction(std::pair<double, double> agent_location, double agent_step_size, std::pair<double, double> object_location, double obj_dim[3], Object obj);
	bool canStepOver(std::pair<double, double> agent_location, std::pair<double, double> object_location, double obj_height, double step_height);
	std::string evade(std::pair<double, double> agent_location, std::pair<double, double> object_location, double obj_xwid, double obj_ywid);
	std::string walkOn(std::pair<double, double> agent_location, std::pair<double, double> object_location);

	private:
	std::pair<AtomType, std::set<Atom> > all_object;
	std::pair<AtomType, std::set<Atom> > all_constant;
	std::pair<AtomType, std::set<Atom> > all_predicate;
	std::pair<AtomType, std::set<Atom> > all_function;
	std::pair<AtomType, std::set<Atom> > all_relation;
};

#endif
