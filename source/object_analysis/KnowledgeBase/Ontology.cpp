// AUTHOR: NA
// DATE: 03/07/17
// DESC: Implementation of knowledge base vocabulary
// FILE: Ontology.cpp

#include <set>
#include <utility>
#include <iostream>
#include "Ontology.h"
#include "../FOL/Atom.h"

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

	bool Ontology::hasPercept(ObjectType obj)
	{
	    //return obj == ObjectType.AGENT || obj == ObjectType.DYNAMIC_MAMMAL;
		return true;
	}

	bool Ontology::hasActuator(ObjectType obj)
	{
		//return obj == AGENT || obj == DYNAMIC_MAMMAL;
		return true;
	}

	// RELATION
	void Ontology::addRelation(Atom relation)
	{
            all_relation.second.insert(relation);
	}

	bool Ontology::removeRelation(std::string name)
	{
		return true;	
	}

	std::pair<AtomType, std::set<Atom> > Ontology::getAllRelation()
	{
		return all_relation;
	}

	std::set<Atom> Ontology::isNorth(ObjectType obj)
	{
		//for(auto obj : all_object){
			// obj.y is above agent.y
			// add to set	
		//}
	}

	std::set<Atom> Ontology::isEast(ObjectType obj)
	{
		//for(auto obj : all_object){
			// obj.y is above agent.y
			// add to set	
		//}
	}

	std::set<Atom> Ontology::isSouth(ObjectType obj)
	{
		//for(auto obj : all_object){
			// obj.y is above agent.y
			// add to set	
		//}
	}

	std::set<Atom> Ontology::isWest(ObjectType obj)
	{
		//for(auto obj : all_object){
			// obj.y is above agent.y
			// add to set	
		//}
	}
	
	// OBJECT
	void Ontology::addObject(Atom object)
	{
            all_constant.second.insert(object);
	}

	bool Ontology::removeObject(std::string name)
	{
		return true;
	}

	std::pair<AtomType, std::set<Atom> > Ontology::getAllObject()
	{
		return all_object;
	}

	// CONSTANT
	void Ontology::addConstant(Atom constant)
	{
            all_constant.second.insert(constant);
	}

	bool Ontology::removeConstant(std::string name)
	{
		return true;
	}

	std::pair<AtomType, std::set<Atom> > Ontology::getAllConstant()
	{
		return all_constant;
	}
