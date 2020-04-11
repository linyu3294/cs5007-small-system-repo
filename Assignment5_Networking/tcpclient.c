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

// // A sockets library and internet protocol library
#include <sys/socket.h>
#include <netinet/in.h>


int main(){
    //initialize client socket
    int client_socket;
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation \n");
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    //specify port to connect to - chose 9004 because it was open
    server_address.sin_port = htons(9004);
    server_address.sin_addr.s_addr = htons(INADDR_ANY);

    int connection_status;
    
    //specifying where to connect 
    if ((connection_status = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)))< 0){
            //if connection unsuccessful
	    printf("%d Connection unsuccessful\n", connection_status);
            close(client_socket);
            exit(0);
    } else {
	printf("Connection successful.\n");
        printf("You have reached the server.\n");
    }
	
    //taking in username
    char username[30];
    //setting default message to 128 char long
    char clientMessage[128];
    
    //prompting user to enter username 
    printf("Please enter your username > ");
    fgets(username, 30, stdin);

    //getting username length and message length
    int userNameLength = sizeof(username);
    int messageLength = sizeof(clientMessage);  

    //creatng empty char array for server response 
    char server_response[256];
    
    //receiving server response 
    recv(client_socket, &server_response, sizeof(server_response), 0);
    
    //sending uername to server with appropriate length 
    send(client_socket, username, userNameLength, NULL); 
    while (1){
        printf("client> ");
   	//prompt user to enter message
	fgets(clientMessage, messageLength, stdin);
	
	//reformat message length from 128 to actual message length 
	int clientMessageLength = strlen(clientMessage);
	
	//send message with appropriate message length 
        send(client_socket, clientMessage, clientMessageLength, NULL);
	
	//if message == "exit", break out of loop.
	if (strcmp(clientMessage, "exit\n")==0){
            printf("You are exiting the server...goodbye!\n");
	    break;
        }

    }       
   //close socket
    close(client_socket);
    return 0;
}
