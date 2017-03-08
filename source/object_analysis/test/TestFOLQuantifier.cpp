// AUTHOR: NA
// DATE: 02/13/17
// DESC: Test Quantifier class 
// FILE: TestFOLQuantifier.cpp

#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "../FOL/Quantifier.h"

using namespace ::testing;

class TestFOLQuantifier : public ::testing::Test{
        protected:
            virtual void SetUp(){
            }
            virtual void TearDown(){
            }                                              
};

// Tests are detected
TEST_F(TestFOLQuantifier, Detected){
    std::cout << "TestFOLQuantifier suite detected" << std::endl;
}

// Tests are completed
TEST_F(TestFOLQuantifier, Completed){
    std::cout << "TestFOLQuantifier suite completed" << std::endl;
}

// Test template
TEST_F(TestFOLQuantifier, Template){

}

