// AUTHOR: AU
// DATE: 02/15/17
// DESC: Class definition for server
// FILE: server.h

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

class MessageServer {
    public:
        MessageServer();
        bool openConnection(std::string &msg);
        bool bindSocket(std::string &msg);
        bool listenClient(std::string &msg);
        void doConnection();
        bool closeConnection(std::string &msg);

    private:
        struct sockaddr_in server_addr;
        socklen_t size;
        int client;
        int server;
        int portNum = 1500;
        bool is_exit = false;
        int bufsize = 1024;
        char *buffer;// = nullptr;
};
