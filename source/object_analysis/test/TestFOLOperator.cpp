// AUTHOR: NA
// DATE: 02/13/17
// DESC: Tests operator class
// FILE: TestFOLOperator.cpp

#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "../FOL/Operator.h"

using namespace ::testing;

class TestFOLOperator : public ::testing::Test{
        protected:

            virtual void SetUp(){
            }
            virtual void TearDown(){
            }
};

// Tests are detected
TEST_F(TestFOLOperator, Detected){
    std::cout << "TestFOLOperator suite detected" << std::endl;
}

// Tests are completed
TEST_F(TestFOLOperator, Completed){
    std::cout << "TestFOLOperator suite completed" << std::endl;
}

// Test template
TEST_F(TestFOLOperator, Template){

}

