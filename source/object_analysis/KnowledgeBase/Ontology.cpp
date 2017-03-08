// AUTHOR: NA
// DATE: 03/07/17
// DESC: Implementation of knowledge base vocabulary
// FILE: Ontology.cpp

#include <set>
#include <utility>
#include <iostream>
#include "Ontology.h"

        // FUNCTION
	void Ontology::addFunction(Atom function)
        {
            all_function.second.insert(function);
        }

	bool Ontology::removeFunction(std::string name)
        {
            return true;
            //return all_function.second.end() == all_function.second.erase(all_function.second.find(name));
        }

	std::pair<AtomType, std::set<Atom> > Ontology::getAllFunction()
        {
            return all_function;
        }

	unsigned Ontology::priority(ObjectType obj)
        {
            // return ObjectType
            return 0;
        }

	unsigned Ontology::robustness(ObjectType obj)
        {
            // return ObjectType with rank ObjectType.len() - ObjectType
            return 0;
        }

        std::pair<int, int> Ontology::position(Atom constant)
        {
            return std::make_pair(0, 0);
        }

	// PREDICATE
	void Ontology::addPredicate(Atom predicate)
        {
            all_predicate.second.insert(predicate);
        }

	bool Ontology::removePredicate(std::string name)
        {
            return true;
            //return all_predicate.end() == all_predicate.erase(find(name));
        }

	std::pair<AtomType, std::set<Atom> > Ontology::getAllPredicate()
        {
            return all_predicate;
        }
/*
	bool hasPercept(ObjectType obj){}
	bool hasActuator(ObjectType obj){}

	// RELATION
	void addRelation(Atom predicate){}
	bool removeRelation(std::string name){}
	std::pair<AtomType, std::set<Atom> > getAllRelation(){}
	std::set<Atom> isNorth(ObjectType obj){}
	std::set<Atom> isEast(ObjectType obj){}
	std::set<Atom> isSouth(ObjectType obj){}
	std::set<Atom> isWest(ObjectType obj){}
	
	// OBJECT
	void addObject(Atom object){}
	bool removeObject(std::string name){}
	std::pair<AtomType, std::set<Atom> > getAllObject(){}

	// CONSTANT
	void addConstant(Atom constant){}
	bool removeConstant(std::string name){}
	std::pair<AtomType, std::set<Atom> > getAllConstant(){}
*/
