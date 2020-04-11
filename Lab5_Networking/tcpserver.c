// Compile with: gcc tcpserver.c -o tcpserver
//
// Implement tcp server below.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some types and unix operations
#include <sys/types.h>
#include <unistd.h>

// A sockets library and internet protocol library
#include <sys/socket.h>
#include <netinet/in.h>


int main(){
    //create server socket
    int server_socket;

    //domain = AF_INET(IPv4) or AF_INET6
    //                      domain,     type,  protocol
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9004); //play w this for ports
    server_address.sin_addr.s_addr = htons(INADDR_ANY);

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    printf("Server bind()\n");

    listen(server_socket,27); //27 clients queued up in server to connect
    
    // integer to hold a potential client socket 
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);
    
    //send message from server
    char server_message[256] = "You have reached the server";
    send(client_socket, server_message, sizeof(server_message), 0);

    //close socket
    close(server_socket);

}
