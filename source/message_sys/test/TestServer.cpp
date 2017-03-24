// AUTHOR: NA
// DATE: 03/23/17
// DESC: Unit test server class
// FILE: TestServer.cpp

//NOTE:
// Instructions for running gtest
// Check library is known: sudo ldconfig -v | grep gtest
// Compile with c++: c++ <source_files> -lgtest -lgtest_main -o <output_file>

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

class TestServer : public ::testing::Test{
        protected:
            virtual void SetUp(){

            }
            virtual void TearDown(){

            }                                              }
};

// Tests are detected
TEST_F(TestServer, Detected){
    std::cout << "TestServer suite detected" << std::endl;
}

// Tests are completed
TEST_F(TestServer, Completed){
    std::cout << "TestServer suite completed" << std::endl;
}

// Test template
TEST_F(TestServer, Template){

}
