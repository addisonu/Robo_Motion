// AUTHOR: NA
// DATE: 03/09/17
// DESC: The definition for the inference engine which will entail new sentence from those in the knowledge repo
// FILE: Inference.h

#ifndef KNOWLEDGE_BASE_INFERENCE_ENGINE_H
#define KNOWLEDGE_BASE_INFERENCE_ENGINE_H

#include <vector>
#include <algorithm>
#include "../FOL/Sentence"

class Inference{
    public:

        // CONSTRUCTOR

        // MEMBER FUNCTIONS
        Sentence BackChaining();
        Sentence ForwardChaining();
        Unification(Sentence lhs, Sentence rhs)l;

    private:
};
#endif


