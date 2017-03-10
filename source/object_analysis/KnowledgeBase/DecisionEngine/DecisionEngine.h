// AUTHOR: NA
// DATE: 03/09/17
// DESC: The definition for the decision engine which will return a recommendation based on some heuristics
// FILE: DecisionEngine.h


#ifndef KNOWLEDGE_BASE_DECISION_ENGINE_H
#define KNOWLEDGE_BASE_DECISION_ENGINE_H

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include "../../FOL/Sentence.h"

class DecisionEngine{
    public:

    // CONSTRUCTOR

    // MEMBER FUNCTIONS
    void addHeuristic(Sentence val);
    void removeHeuristic(unsigned index);
    std::set<Sentence>  getAllHeuristic();

    private:
        std::set<Sentence> heurisitic;
};
#endif


