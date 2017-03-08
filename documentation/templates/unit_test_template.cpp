// AUTHOR: NA
// DATE: 02/13/17
// DESC: Unit testing template file
// FILE: unit_test_template.cpp

//NOTE :
// Instructions for running gtes
// Check library is known: sudo ldconfig -v | grep gtest
// Compile with c++: c++ <source_files> -lgtest -lgtest_main -o <output_file>

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

class TestClass : public ::testing::Test{
        protected:
            virtual void SetUp(){

            }
            virtual void TearDown(){

            }                                              }
};

// Tests are detected
TEST_F(TestClass, Detected){
    std::cout << "TestClass suite detected" << std::endl;
}

// Tests are completed
TEST_F(TestClass, Completed){
    std::cout << "TestClass suite completed" << std::endl;
}

// Test template
TEST_F(TestClass, Template){

}
