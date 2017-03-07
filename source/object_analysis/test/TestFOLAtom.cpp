// AUTHOR: NA
// DATE: 02/13/17
// DESC: Unit testing template file
// FILE: unit_test_template.cpp


#include <iostream>

#include "gtest/gtest.h"

using namespace ::testing;

class TestFOLAtom : public ::testing::Test{
        protected:
            virtual void SetUp(){
                std::vector<AtomType> at{FUNCTION};
            }
            virtual void TearDown(){

            }                                              }
};

// Tests are detected
TEST_F(TestFOLAtom, Detected){
    std::cout << "TestFOLAtom suite detected" << std::endl;
}

// Tests are completed
TEST_F(TestFOLAtom, Completed){
    std::cout << "TestFOLAtom suite completed" << std::endl;
}

// Test template
TEST_F(TestFOLAtom, Template){

}

