#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sstream>

class Server
{
    public:
        Server();
        ~Server();

        void init_server();
        int StartServer();

        int listen_to_socket();
        int accept_connection();
        void readRequest();
        void sendResponse();
        
        void log(const std::string &message);
        int exit_error(const std::string &message);

    private:
        std::string ip;
        int socket_fd;
        int new_socket;
        int port;
        int max_connections;
        struct sockaddr_in sock_addr;
        socklen_t sock_addr_len;
        
};

#endif 