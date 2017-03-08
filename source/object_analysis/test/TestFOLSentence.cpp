// AUTHOR: NA
// DATE: 02/13/17
// DESC: Test Sentence class 
// FILE: TestFOLSentence.cpp

#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "../FOL/Sentence.h"

using namespace ::testing;

class TestFOLSentence : public ::testing::Test{
        protected:
            virtual void SetUp(){
            }
            virtual void TearDown(){
            }                                              
};

// Tests are detected
TEST_F(TestFOLSentence, Detected){
    std::cout << "TestFOLSentence suite detected" << std::endl;
}

// Tests are completed
TEST_F(TestFOLSentence, Completed){
    std::cout << "TestFOLSentence suite completed" << std::endl;
}

// Test template
TEST_F(TestFOLSentence, Template){

}

