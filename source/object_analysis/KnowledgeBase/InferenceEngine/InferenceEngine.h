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

class InferenceEngine{
    public:

        // CONSTRUCTOR

        // MEMBER FUNCTIONS
        Sentence backChaining(std::set<Sentence> kb);
        std::pair<Sentence, bool> forwardChaining(std::set<Sentence> kb);
        std::set<Sentence> makeDefiniteClauseKB(std::set<Sentence> kb, Atom query);
        bool unify(Sentence lhs, Sentence rhs);
		Sentence standardizeRule(Sentence rule);
		bool substitution(std::set<std::pair<Atom, Atom> > &theta, ComplexAtom alpha, unsigned arg_index);
		std::set<Sentence> universalInstatiation(Sentence alpha);
		Sentence existentialInstatiation(std::set<std::pair<std::string, Sentence> > theta, Sentence alpha);

    private:
		
		std::set<Sentence> kb;
};
#endif


