// AUTHOR: AU
// DATE: 02/15/17
// DESC: Class implementation for client
// FILE: client.cpp

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include "client.h"

MessageClient::MessageClient()
{
    buffer = new char[bufsize];
    char ip_add[] = "127.0.0.1";
    ip = ip_add;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);
}

bool MessageClient::openConnection(std::string &msg)
{
    client = socket(AF_INET, SOCK_STREAM, 0);
    if(client < 0){
        msg = "Error establishing socket...";
        return 0;
    }
    msg = "Socket client has been created...";
    return true;
}

bool MessageClient::bindSocket(std::string &msg)
{
    if(!connect(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0){
        return false;
    }
    std::stringstream s(portNum);
    s << "Connection to the server port number: ";
    msg = s.str();
    std::cout << "=> Awaiting confirmation from the server...";
    std::cout << "=> Connection confirmed, you are good to     go...";
    recv(client, buffer, bufsize, 0);
    std::cout << "\n\n=> Enter # to end the connection";
    return true;
}

/*bool MessageClient::listenClient(std::string &msg)
{

}
*/

void MessageClient::doConnection()
{
    do{

        std::cout << "Client: ";
        do{
            std::cin >> buffer;
            send(client, buffer, bufsize, 0);
            if(*buffer == '#'){
                send(client, buffer, bufsize, 0);
                *buffer = '*';
                is_exit = true;
            }
        }while(*buffer != 42);

        std::cout << "Server: ";
        do{
            recv(client, buffer, bufsize, 0);
            std::cout << buffer << " ";
            if(*buffer == '#'){
                *buffer = '*';
                is_exit = true;
            }
        }while(*buffer != 42);

    }while(!is_exit);
    std::string msg;
    closeConnection(msg);
}

bool MessageClient::closeConnection(std::string &msg)
{
    try{
    std::cout << "\n=> Connection terminated.\nGoodbye...\n";
    close(client);
    }
    catch(std::exception &e){

    }
    return true;
}
