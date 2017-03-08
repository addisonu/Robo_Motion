// AUTHOR: NA
// DATE: 03/07/17
// DESC: Definition for operator class.
// FILE: Operator.h

#ifndef FOL_OPERATOR_H
#define FOL_OPERATOR_H

#include <vector>

class Operator{
    public:

        // CONSTRUCTOR

        // MEMBER FUNCTIONS
        bool NOT(bool truth_val)
        {
            return !truth_val;
        }

        bool AND(bool lhs_truth_val, bool rhs_truth_val)
        {
            return lhs_truth_val && rhs_truth_val;
        }

        bool OR(bool lhs_truth_val, bool rhs_truth_val)
        {
            return lhs_truth_val || rhs_truth_val;
        }

        bool EQUAL(bool lhs_truth_val, bool rhs_truth_val)
        {
            return lhs_truth_val == rhs_truth_val;
        }

        bool IMPLY(std::vector<bool> lhs_truth_tbl, std::vector<bool> rhs_truth_tbl)
        {
            for(unsigned i = 0; i != lhs_truth_tbl.size(); ++i){
                if(lhs_truth_tbl[i] == true && rhs_truth_tbl[i] == false){
                    return false;
                }
            }
            return true;
        }

        // DATA MEMBERS
};
#endif


