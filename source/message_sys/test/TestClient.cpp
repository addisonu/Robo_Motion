// AUTHOR: NA
// DATE: 03/23/17
// DESC: Unit test client class
// FILE: TestClient.cpp

//NOTE:
// Instructions for running gtest
// Check library is known: sudo ldconfig -v | grep gtest
// Compile with c++: c++ <source_files> -lgtest -lgtest_main -o <output_file>

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

class TestClient : public ::testing::Test{
        protected:
            virtual void SetUp(){

            }
            virtual void TearDown(){

            }                                              }
};

// Tests are detected
TEST_F(TestClient, Detected){
    std::cout << "TestClient suite detected" << std::endl;
}

// Tests are completed
TEST_F(TestClient, Completed){
    std::cout << "TestClient suite completed" << std::endl;
}

// Test template
TEST_F(TestClient, Template){

}
