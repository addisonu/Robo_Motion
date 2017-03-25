// AUTHOR: NA
// DATE: 02/27/17
// DESC: Definition of inference engine which entails sentences from sentences in the knowledge repo
// FILE: InferenceEngine.h

#include <set>
#include <string>

#ifndef INFERENCE_ENGINE_H
#define INFERENCE_ENGINE_H

class InferenceEngine {
    public:
        InferenceEngine();
        bool isAEntailB(std::string A, std::string B);
        bool doEntailment();
        bool truthValue(std::string sentence);
        unsigned truthValueDegree(std::string sentence);

    private:

};
#endif
