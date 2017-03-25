// AUTHOR: NA
// DATE: 02/27/17
// DESC: Definition for decision engine which determines the appropriate action depending on information stored in knowledge base and percepts
// FILE: DecisionEngine.h

#include <set>
#include <string>

#ifndef DECISION_ENGINE_H
#define DECISION_ENGINE_H

class DecisionEngine {
    public:
        DecisionEngine();
        std::string recommendAction();
        bool addHeuristic(std::string heuristic);
        bool removeHeuristic(unsigned index);

    private:
        std::list<std::string> heuristic_list;
};
#endif
