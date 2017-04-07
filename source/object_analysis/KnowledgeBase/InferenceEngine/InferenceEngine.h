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
#include "../Ontology.h"

class InferenceEngine{
    public:

        // CONSTRUCTOR

        // MEMBER FUNCTIONS
        std::pair<Atom, Atom> backChaining(Sentence query);
        std::pair<Atom, Atom> forwardChaining(Sentence query);
        Sentence makeDefiniteClause(Sentence alpha);
        std::set<std::pair<Atom, Atom> > unify(Sentence lhs, Sentence rhs);
        Sentence standardizeRule(Sentence rule);
        bool substitution(std::set<std::pair<Atom, Atom> > &theta, ComplexAtom alpha, unsigned arg_index);
        std::set<Sentence> universalInstatiation(Sentence alpha);
        Sentence existentialInstatiation(std::set<std::pair<std::string, Sentence> > theta, Sentence alpha);

    private:
		
        std::set<Sentence> kb;
        Ontology ontology;
        std::string new_constant; // holds identifier of last new constant created
};
#endif


