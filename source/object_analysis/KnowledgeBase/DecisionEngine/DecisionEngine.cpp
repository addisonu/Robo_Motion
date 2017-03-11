// AUTHOR: NA
// DATE: 03/09/17
// DESC: The implementation for the decision engine which will return a recommendation based on some heuristics
// FILE: DecisionEngine.cpp

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include "../../FOL/Sentence.h"
#include "../../FOL/Atom.h"
#include "DecisionEngine.h"

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
            /*std::list<Atom>::iterator*/ auto it_sen = it->sen.begin();
            auto val_sen = val.sen.begin();
            while(it_sen != it->sen.end() || val_sen != val.sen.end()){
            //for(unsigned i =  0; i != val.sen.size(); ++i){
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

