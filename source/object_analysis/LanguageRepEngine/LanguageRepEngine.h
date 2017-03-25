// AUTHOR: NA
// DATE: 02/26/17
// DESC: Definition of lanugage reprentation engine. A file that converts string queries and statements to first-order logice
// FILE: LanguageRepEngine.h

#include <set>
#include <string>

#ifndef LANGUAGE_REP_ENGINE_H
#define LANGUAGE_REP_ENGINE_H

struct object{};
struct relation{};
struct function_rel{};
struct context{};
struct ontology_obj{
    object obj;
    relation rel;
    function_rel funct;
    context cntxt;
};

class LanguageRepEngine{
    public:
        LanguageRepEngine();
        bool MakeKBSentence(std::string sentence);
        bool MakeSentence(std::string sentence);

    private:
        ontology_obj model_obj;
};

#endif
