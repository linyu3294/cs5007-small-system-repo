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
#include <sys/socket.h>
#include <netinet/in.h>


int main(){
    //create server socket
    int server_socket;
    //domain = AF_INET(IPv4) or AF_INET6
    //                      domain,     type,  protocol
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Set Sever address variables
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9004); 
    server_address.sin_addr.s_addr = htons(INADDR_ANY);
    
    // Bind server socket and server address
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
      
    //Start an infinite loop
    while(1){
        // Use an integer to store a potential client socket 
        int client_socket;
        
	//print some init statements
	printf("Server started successfully...\n");
        printf("Listening for client inputs...\n");       
	
	//char array for client output
	char clientOutput[30]; 

	//listening for client 
        listen(server_socket,10); //10 clients queued up in server to connect
        
	//Accepting client inputs
	client_socket = accept(server_socket, NULL, NULL);
        
	char server_message[256] = "You have reached the server\n";
        //Sent message to client
	send(client_socket, server_message, sizeof(server_message), 0); 
        
	//print which socket client connected to
	printf("Client has joined %d\n", server_socket);
        
	char userName[30];
	//Print client username
	recv(client_socket, &userName, 30, 0);
        printf("Client username: %s\n", userName);
	
	//while loop to stream client inputs 
	while(1){
		//breaks out of loop if user types "exit"
		recv(client_socket, &clientOutput, 30, 0);
		if (strcmp(clientOutput, "exit\n")==0){
	    		break;
		}
		//fork() to create sperate processes
		if (fork() == 0){
			system(clientOutput);
			exit(0);
	    	}	
		//Reset Array
		memset(clientOutput, 0, 30);
	}
    printf("Disconnecting!\n");
    }
    // close server socket
    close(server_socket);
}

