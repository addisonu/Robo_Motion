// AUTHOR: AU
// DATE: 02/15/17
// DESC: Driver for client
// FILE: client_main.cpp

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <exception>
#include "../Server/client.h"

int main(int argc, char **argv)
{
	try{
	std::string msg;
	MessageClient client;
	client.openConnection(msg);
	client.bindSocket(msg);
	client.doConnection();
	client.closeConnection(msg);
	}
	catch(std::exception &e){
		std::cout << "There was an unkwon error, program terminating" << std::endl;
		return 1;
	}
    return 0;;
}
