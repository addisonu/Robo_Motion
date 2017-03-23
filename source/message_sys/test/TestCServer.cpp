// AUTHOR: NA
// DATE: 02/13/17
// DESC: Unit test for server portion of messaging system
// FILE: TestCServer.cpp
 
#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

class TestCServer : public ::testing::Test{
	protected:
		virtual void SetUp(){

		}
		virtual void TearDown(){

		}
};

// Tests are detected
TEST_F(TestCServer, Detected){
	std::cout << "TestCServer suite detected" << std::endl;
}

// Server socket created
TEST_F(TestCServer, SocketCreated){

}
// No client detected
TEST_F(TestCServer, ClientNotDetected){

}
// Client detected
TEST_F(TestCServer, ClientDetected){

}
// Server read from client
TEST_F(TestCServer, ReadClient){

}
// Server write to client
TEST_F(TestCServer, WriteClient){

}
// Tests are completed
TEST_F(TestCServer, Completed){
	std::cout << "TestCServer suite completed" << std::endl;  
}

