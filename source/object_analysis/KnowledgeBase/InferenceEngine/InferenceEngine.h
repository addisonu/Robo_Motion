// AUTHOR: NA
// DATE: 03/09/17
// DESC: The definition for the inference engine which will entail new sentences from those in the knowledge repo
// FILE: Inference.h

#ifndef KNOWLEDGE_BASE_INFERENCE_ENGINE_H
#define KNOWLEDGE_BASE_INFERENCE_ENGINE_H

#include <vector>
#include <algorithm>
#include <set>
#include "../../FOL/Sentence.h"

class Inference{
    public:

        // CONSTRUCTOR

        // MEMBER FUNCTIONS
        std::set<Sentence> makeDefiniteClauseKB(std::set<Sentence> kb);
        Sentence backChaining();
        std::pair<Sentence, bool> forwardChaining();
        bool unification(Sentence lhs, Sentence rhs);

    private:
};
#endif


