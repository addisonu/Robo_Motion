// AUTHOR: AU
// DATE: 02/15/17
// DESC: Driver for server
// FILE: server_main.cpp

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <exception>
#include "../Server/server.h"

int main(int argc, char **argv)
{
	std::string msg;

	try{
		MessageServer server;
		server.openConnection(msg);
		server.listenClient(msg);
		server.closeConnection(msg);
	}
	catch(std::exception &e){
		std::cout << "An unknown error occurred. The program will now terminate" << std::endl;
		return 1;
	}
    return 0;
}
