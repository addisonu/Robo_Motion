// AUTHOR: AU
// DATE: 02/15/17
// DESC: Class implemention for server
// FILE: server.cpp

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

MessageServer::MessageServer()
{
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);
}

bool MessageServer::openConnection(std::string &msg)
{
    client = socket(AF_INET, SOCK_STREAM, 0);
    std::string result;
    if(client < 0){
        msg = "Error establishing socket...";
        return false;
    }
    msg = "Connection established...";
    return true;
}

bool MessageServer::bindSocket(std::string &msg)
{
    if((bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr))) < 0){
        msg = "Error binding connection, the socket     has already been established...";
        return false;
    }
    msg = "Connection successfully bound...";
    return true;
}
bool MessageServer::listenClient(std::string &msg)
{
    size = sizeof(server_addr);
    listen(client, 1);
    int client_count = 1;
    server = accept(client, (struct sockaddr*)&server_addr, &size);

    if(server < 0){
        msg = "Error accepting client(s)...";
        return false;
    }
    while(server > 0){
        strcpy(buffer, "=> Server connected...\n");
        send(server, buffer, bufsize, 0);
        std::cout << "=> Connected with the client #"
            << client_count << ", you are good to go...\n"
            << "\n=> Enter # to end the connection\n" << std::endl;
        doConnection();
    }
    close(client);
    return true;
}
void MessageServer::doConnection()
{
    do{
        recv(server, buffer, bufsize, 0);
        std::cout << buffer << " ";
        if(*buffer == '#'){
            *buffer = '*';
            is_exit = true;
        }
    }while(*buffer != '*');

    do{
        std::cout << "\nServer: ";
        do{
            std::cin >> buffer;
            send(server, buffer, bufsize, 0);
            if(*buffer == '#'){
                send(server, buffer, bufsize, 0);
                *buffer = '*';
                is_exit = true;
            }
        }while(*buffer != '*');
        
        std::cout << "Client: ";
        do{
            recv(server, buffer, bufsize, 0);
            std::cout << buffer << " ";
            if(*buffer == '#'){
                *buffer = '*';
                is_exit = true;
            }
        }while(*buffer != '*');
    }while(!is_exit);
}

bool MessageServer::closeConnection(std::string &msg)
{
    try{
        msg = "\n\n=> Connection terminated with IP     " + std::string(inet_ntoa(server_addr.sin_addr));
        close(server);
        is_exit = false;
        //exit 1?
    }
    catch(std::exception e){

    }
    return true;
}
