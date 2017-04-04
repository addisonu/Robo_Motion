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
        // add a function to set of all functions
	void Ontology::addFunction(Atom function)
        {
            all_function.second.insert(function);
        }

        // remove function from set of all functions
	bool Ontology::removeFunction(std::string name)
        {
            auto function_it = all_function.second.begin();
            while(function_it != all_function.second.end()){
                if(function_it->name == name){
                    all_function.second.erase(function_it);
                    return function_it != all_function.second.end();
                }
            }
            return false;
        }

	std::pair<AtomType, std::set<Atom> > Ontology::getAllFunction()
        {
            return all_function;
        }

        // return priority of object type
	unsigned Ontology::priority(ObjectType obj)
        {
            switch(obj){
                case ObjectType::AGENT:
                    {
                        return 7;
                    }
                case ObjectType::DYNAMIC_MAMMAL:
                    {
                        return 9;
                    }
                case ObjectType::STATIC_MAMMAL:
                    {
                        return 9;
                    }
                case ObjectType::DYNAMIC_PLANT:
                    {
                        return 7;
                    }
                case ObjectType::STATIC_PLANT:
                    {
                        return 7;
                    }
                case ObjectType::DYNAMIC_INORGANIC_NATURAL:
                    {
                        return 6;
                    }
                case ObjectType::STATIC_INORGANIC_NATURAL:
                    {
                        return 7;
                    }
                case ObjectType::DYNAMIC_SYNTHETIC:
                    {
                        return 4;
                    }
                case ObjectType::STATIC_SYNTHETIC:
                    {
                        return 5;
                    }
                default:
                    {
                        return 0;
                    }
            }
            return 0;
        }

        // return fragility of object arg
	unsigned Ontology::robustness(ObjectType obj)
        {
            switch(obj){
                case ObjectType::AGENT:
                    {
                        return 9;
                    }
                case ObjectType::DYNAMIC_MAMMAL:
                    {
                        return 2;
                    }
                case ObjectType::STATIC_MAMMAL:
                    {
                        return 2;
                    }
                case ObjectType::DYNAMIC_PLANT:
                    {
                        return 4;
                    }
                case ObjectType::STATIC_PLANT:
                    {
                        return 4;
                    }
                case ObjectType::DYNAMIC_INORGANIC_NATURAL:
                    {
                        return 3;
                    }
                case ObjectType::STATIC_INORGANIC_NATURAL:
                    {
                        return 7;
                    }
                case ObjectType::DYNAMIC_SYNTHETIC:
                    {
                        return 5;
                    }
                case ObjectType::STATIC_SYNTHETIC:
                    {
                        return 5;
                    }
                default:
                    {
                        return 0;
                    }
            }
            return 0;
        }

        // REMOVE
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
            auto predicate_it = all_predicate.second.begin();
            while(predicate_it != all_predicate.second.end()){
                if(predicate_it->name == name){
                    all_predicate.second.erase(predicate_it);
                    return predicate_it != all_predicate.second.end();
                }
            }
            return false;
         }

	std::pair<AtomType, std::set<Atom> > Ontology::getAllPredicate()
        {
            return all_predicate;
        }

        // return true is the object perceives it's environment, false otherwise
	bool Ontology::hasPercept(ObjectType obj)
	{
	    if(obj == ObjectType::AGENT
                    || obj == ObjectType::DYNAMIC_MAMMAL
                    || obj == ObjectType::STATIC_MAMMAL
                    || obj == ObjectType::DYNAMIC_INORGANIC_NATURAL
                    ||obj == ObjectType::DYNAMIC_SYNTHETIC){
		return true;
            }
            return false;
	}

	bool Ontology::hasActuator(ObjectType obj)
	{
	if(obj == ObjectType::AGENT
                    || obj == ObjectType::DYNAMIC_MAMMAL
                    || obj == ObjectType::DYNAMIC_PLANT
                    || obj == ObjectType::DYNAMIC_INORGANIC_NATURAL
                    ||obj == ObjectType::DYNAMIC_SYNTHETIC){
		return true;
            }
            return false;
	}

	// RELATION
	void Ontology::addRelation(Atom relation)
	{
            all_relation.second.insert(relation);
	}

	bool Ontology::removeRelation(std::string name)
	{
            auto relation_it = all_relation.second.begin();
            while(relation_it != all_relation.second.end()){
                if(relation_it->name == name){
                    all_relation.second.erase(relation_it);
                    return relation_it != all_relation.second.end();
                }
            }
            return false;
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
            auto object_it = all_object.second.begin();
            while(object_it != all_object.second.end()){
                if(object_it->name == name){
                    all_object.second.erase(object_it);
                    return object_it != all_object.second.end();
                }
            }
            return false;
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
