// AUTHOR: NA
// DATE: 02/13/17
// DESC: Test Ontology class 
// FILE: TestFOLOntology.cpp

#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "../FOL/Ontology.h"

using namespace ::testing;

class TestFOLOntology : public ::testing::Test{
        protected:
            virtual void SetUp(){
            }
            virtual void TearDown(){
            }                                              
};

// Tests are detected
TEST_F(TestFOLOntology, Detected){
    std::cout << "TestFOLOntology suite detected" << std::endl;
}

// Tests are completed
TEST_F(TestFOLOntology, Completed){
    std::cout << "TestFOLOntology suite completed" << std::endl;
}

// Test template
TEST_F(TestFOLOntology, Template){

}

