// AUTHOR: NA
// DATE: 03/23/17
// DESC: Unit test server class
// FILE: TestServer.cpp

//NOTE:
// Instructions for running gtest
// Check library is known: sudo ldconfig -v | grep gtest
// Compile with c++: c++ <source_files> -lgtest -lgtest_main -o <output_file>

#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "../Server/server.h"

using namespace ::testing;

class TestServer : public ::testing::Test{
        protected:

	    MessageServer *server;
	    std::string	open_str;
	    std::string	bind_str;
	    std::string	listen_client_str;
	    std::string	close_str;
		
            virtual void SetUp(){
		server = new MessageServer();

		open_str = "open_str";
		bind_str = "bind_str";
		listen_client_str = "listen_client_str";
		close_str = "close_str";
            }
            virtual void TearDown(){
		delete server;
            }                                              
};

// Tests are detected
TEST_F(TestServer, Detected){
    std::cout << "TestServer suite detected" << std::endl;
}

// Test open connection
TEST_F(TestServer, OpenConnection){
	EXPECT_TRUE(server->openConnection(open_str));
}

// Test binding socket
TEST_F(TestServer, BindSocket){
	EXPECT_TRUE(server->bindSocket(bind_str));
}

// Test listen for client
TEST_F(TestServer, ListenClient){
	EXPECT_TRUE(server->listenClient(listen_client_str));
}

// Test close connection
TEST_F(TestServer, CloseConnection){
	EXPECT_TRUE(server->closeConnection(close_str));
}

// Tests are completed
TEST_F(TestServer, Completed){
    std::cout << "TestServer suite completed" << std::endl;
}

// Test template
TEST_F(TestServer, Template){

}
