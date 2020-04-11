// Compile with: gcc tcpserver.c -o tcpserver
//
// Implement tcp server below.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some types and unix operations
#include <sys/types.h>
#include <unistd.h>
//
// A sockets library and internet protocol library
#include <sys/socketb.h>
#include <netinet/in.h>


int main(){
//create server socket
    int server_socket;
    //domain = AF_INET(IPv4) or AF_INET6
    //                      domain,     type,  protocol
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_address;
    
    server_address.sin_family = AF_INET;
    //specify port to connect to - chose 9004 because it was open
    server_address.sin_port = htons(9004); 
    server_address.sin_addr.s_addr = htons(INADDR_ANY);

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
      
    while(1){
        // integer to hold a potential client socket 
        int client_socket;
        
	//print informative message 
	printf("Server started successfully...\n");
        printf("Listening for client inputs...\n");       
	
	//char array for client output
	char clientOutput[30]; 

	//listening for clients to connect
        listen(server_socket,27); //27 clients queued up in server to connect
        
	//server open to accept client inputs
	client_socket = accept(server_socket, NULL, NULL);
        
	char server_message[256] = "You have reached the server\n";
        //sent message to client
	send(client_socket, server_message, sizeof(server_message), 0); 
        
	//print which socket client connected to
	printf("Client has joined %d\n", server_socket);
        
	char userName[30];
	//receive client username and print it out
	recv(client_socket, &userName, 30, 0);
        printf("Client username: %s\n", userName);
	
	//loop to keep accepting client inputs 
	while(1){
		//breaks if user types "exit"
		recv(client_socket, &clientOutput, 30, 0);
		if (strcmp(clientOutput, "exit\n")==0){
	    		break;
		}
		//forks and performs a system call
		if (fork() == 0){
			system(clientOutput);
			exit(0);
	    	}	
		//clears array for next input
		memset(clientOutput, 0, 30);
	}
    printf("User disconnected!\n");
    }
    // close server socket
    close(server_socket)
}

