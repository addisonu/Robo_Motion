// AUTHOR: NA
// DATE: 03/09/17
// DESC: The implementation for the decision engine which will return a recommendation based on some heuristics
// FILE: DecisionEngine.cpp

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include "../../FOL/Sentence.h"
#include "../../FOL/Atom.h"
#include "DecisionEngine.h"

DecisionEngine::DecisionEngine(std::string path_to_heuristic_arg): path_to_heuristic(path_to_heuristic_arg)
{
	// Load heuristics from file
	try{
		std::ifstream ifs;
		ifs.open(path_to_heuristic, std::ifstream::in);
		if(ifs.is_open()){
			char crule[500];
			while(ifs.good()){
				ifs.getline(crule, 500);
				Sentence rule;
				rule.sen.push_back(Atom(std::string(crule), AtomType::NONE));			
				heuristic.insert(rule);
			}
		}
	}
	catch(std::exception &e){
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}
}

void DecisionEngine::addHeuristic(Sentence val)
{
    heuristic.insert(val);
}

bool DecisionEngine::removeHeuristic(Sentence val)
{
    bool same = true;
    auto it = heuristic.begin();
    while(it != heuristic.end()){
        if(it->sen.size() == val.sen.size()){
            auto it_sen = it->sen.begin();
            auto val_sen = val.sen.begin();
            while(it_sen != it->sen.end() || val_sen != val.sen.end()){
                if(it_sen->type != val_sen->type || it_sen->name == val_sen->name){
                    same = false;
                    break;
                }
            }
            if(same){
                heuristic.erase(it);
                return it == heuristic.end();
            }
        }
    }
    return false;
}

std::set<Sentence>  DecisionEngine::getAllHeuristic()
{
    return heuristic;
}

bool DecisionEngine::writeToKB()
{
	try{
		std::ofstream ofs;
		ofs.open(path_to_heuristic, std::ios::out | std::ios::app);
		if(ofs.is_open()){
			auto heur_it = heuristic.begin();
			while(heur_it++ != heuristic.end()){	
				for(auto term : heur_it->sen){
					ofs << term.name << '\n';
					}
				}
			}
	}
	catch(std::exception &e){
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}	
}
	
