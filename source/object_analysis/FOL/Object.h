// AUTHOR: NA
// DATE: 04/13/17
// DESC: Definition of the object class
// FILE: Object.h

#ifndef FOL_OBJECT_H
#define FOL_OBJECT_H

#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../FOL/Atom.h"

enum class ObjectType{
	AGENT = 0,
	DYNAMIC_MAMMAL,
	STATIC_MAMMAL,
	DYNAMIC_PLANT,
	STATIC_PLANT,
	DYNAMIC_INORGANIC_NATURAL,
	STATIC_INORGANIC_NATURAL,
	DYNAMIC_SYNTHETIC,
	STATIC_SYNTHETIC,
	NONE,
};

static const std::string OBJECT_TYPE = "object_type";
static const std::string PRIORITY = "priority";

class Object : public Atom{

    public:

        // CONSTRUCTOR //
        Object(std::string name_arg, std::string path_to_object_type_file_arg) : Atom(name_arg, AtomType::OBJECT), path_to_object_type_file(path_to_object_type_file_arg)
        {
            auto type_result = determineObjectType();
            object_type = type_result.first;
            priority = type_result.second;
        }

        // MEMBER FUNCTIONS //
        std::pair<ObjectType, unsigned> determineObjectType()
        {
            std::ifstream otf(path_to_object_type_file);

            char buffer[500];
            otf.getline(buffer, 500);

            std::string o_type;
            unsigned o_priority;

            while(otf.good()){
                std::string tmp_str(buffer);
                auto beg_pos = tmp_str.find(name);
                decltype(beg_pos) end_pos;// search each line for object name
                if(beg_pos != std::string::npos){
                    beg_pos = tmp_str.find(OBJECT_TYPE);
                    end_pos = tmp_str.find(':', beg_pos);
                    if(beg_pos != std::string::npos && end_pos != std::string::npos){
                        // get object type
                        o_type = "";
                        o_type = tmp_str.substr(beg_pos + OBJECT_TYPE.length() + 1, end_pos);

                        // get object priority
                        beg_pos = tmp_str.find(PRIORITY);
                        end_pos = tmp_str.find('.', beg_pos);
                        o_priority = 0;
                        std::stringstream ss( tmp_str.substr(beg_pos + PRIORITY.length() + 1, end_pos));
                        ss >> o_priority;

                        // if the ObjectType and priority found exite while loop
                        if(!o_type.empty() && o_priority != 0){
                            break;
                        }
                    }
                }
                otf.getline(buffer, 500);
            }
            std::pair<ObjectType, unsigned> result(std::make_pair(getObjectTypeFromString(o_type), o_priority));
            return result;
        }

        ObjectType getObjectTypeFromString(std::string type)
        {
            if(type == "AGENT"){
                return ObjectType::AGENT;
            }
            else if(type == "DYNAMIC_MAMMAL"){
                return ObjectType::DYNAMIC_MAMMAL;
            }
            else if(type == "STATIC_MAMMAL"){
                return ObjectType::STATIC_MAMMAL;
            }
            else if(type == "DYNAMIC_PLANT"){
                return ObjectType::DYNAMIC_PLANT;
            }
            else if(type == "STATIC_PLANT"){
                return ObjectType::STATIC_PLANT;
            }
            else if(type == "DYNAMIC_INORGANIC_NATURAL"){
                return ObjectType::DYNAMIC_INORGANIC_NATURAL;
            }
            else if(type == "STATIC_INORGANIC_NATURAL"){
                return ObjectType::STATIC_INORGANIC_NATURAL;
            }
            else if(type == "DYNAMIC_SYNTHETIC"){
                return ObjectType::DYNAMIC_SYNTHETIC;
            }
            else if(type == "STATIC_SYNTHETIC"){
                return ObjectType::STATIC_SYNTHETIC;
            }
            return ObjectType::NONE;
        }

        ObjectType getObjectType()
        {
            return object_type;
        }

        void setObjectType(ObjectType type_arg)
        {
            object_type = type_arg;
        }

        unsigned getPriority()
        {
            return priority;
        }

        void setPriority(unsigned priority_arg)
        {
            priority = priority_arg;
        }

        std::string getPathToObjectTypeFile()
        {
            return path_to_object_type_file;
        }

        void setPathToObjectTypeFile(std::string path_arg)
        {
            path_to_object_type_file = path_arg;
        }

    private:

        ObjectType object_type;
        unsigned priority;
        std::string path_to_object_type_file;
};
#endif
