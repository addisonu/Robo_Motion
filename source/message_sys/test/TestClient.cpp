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
#include "../Server/client.h"

using namespace ::testing;

class TestClient : public ::testing::Test{
        protected:

	    MessageClient *client;
	    std::string open_str;
	    std::string bind_str;
	    std::string listen_client_str;
	    std::string close_str;

            virtual void SetUp(){
		client = new MessageClient();

		open_str = "open_str";
		bind_str = "bind_str";
		listen_client_str = "listen_client_str";
		close_str = "close_str";
            }
            virtual void TearDown(){
		delete client;
            }                                              
};

// Tests are detected
TEST_F(TestClient, Detected){
    std::cout << "TestClient suite detected" << std::endl;
}

// Test opening a connection
TEST_F(TestClient, OpenConnection){
	EXPECT_TRUE(client->openConnection(open_str));
}

// Test binding a socket
TEST_F(TestClient, BindSocket){
	EXPECT_TRUE(client->bindSocket(bind_str));
}

// Test client listening
/*TEST_F(TestClient, ListenClient){
	EXPECT_TRUE(client->listenClient(listen_client_str));
}
*/

// Test closing a connection
TEST_F(TestClient, CloseConnection){
	EXPECT_TRUE(client->closeConnection(close_str));
}

// Tests are completed
TEST_F(TestClient, Completed){
    std::cout << "TestClient suite completed" << std::endl;
}

// Test template
TEST_F(TestClient, Template){

}
