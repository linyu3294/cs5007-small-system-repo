// Note: I recommend implementing the tcpserver.c first.
//
// Compile with: gcc tcpclient.c -o tcpclient
//
// Implement tcp client below.
// Note: I recommend implementing the tcpserver.c first.
//
// Compile with: gcc tcpclient.c -o tcpclient
//
// Implement tcp client below.


// Our standard libraries
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
    // Initialize client socket
    int client_socket;
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation \n");
    }

    // Set Server Socket address variables
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9004);
    server_address.sin_addr.s_addr = htons(INADDR_ANY);

    int connection_status;
    
    // Check connection status 
    if ((connection_status 
                = connect(
                    client_socket, 
                    (struct sockaddr*)&server_address, 
                    sizeof(server_address)
                    )
        )< 0){
        // If connection unsuccessful then exit
	    printf("%d Connection unsuccessful\n", connection_status);
            close(client_socket);
            exit(0);
    } else {
        // Else print successful status
	printf("Connection successful.\n");
        printf("You have reached the server.\n");
    }
	
    // Init username
    char username[30];
    // Setting default message to 128 char long
    char clientMessage[128];
    
    // Prompting user to enter username 
    printf("Please enter your username > ");
    fgets(username, 30, stdin);

    // Getting username length and message length
    int userNameLength = sizeof(username);
    int messageLength = sizeof(clientMessage);  

    // Creatng empty char array for server response 
    char server_response[256];
    
    // Receiving server response 
    recv(client_socket, &server_response, sizeof(server_response), 0);
    
    // Sending uername to server with corresponding length 
    send(client_socket, username, userNameLength, NULL); 
    while (1){
        printf("<%s>",username);
   	//Prompt user to type message
	fgets(clientMessage, messageLength, stdin);
	
	//Adjust length of message from 128 char to actual message length 
	int clientMessageLength = strlen(clientMessage);
	
	//Send message with appropriate message length 
        send(client_socket, clientMessage, clientMessageLength, NULL);
	
	//If user types "exit", break out of loop.
	if (strcmp(clientMessage, "exit\n")==0){
            printf("You are exiting the server...goodbye!\n");
	    break;
        }

    }       
   //close socket
    close(client_socket);
    return 0;
}
