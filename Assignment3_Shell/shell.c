
//  ****** MINISHELL *************
//
//  Created by Yu Lin on 3/24/20.
//  Copyright © 2020 Yu Lin. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // This is new!
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>
#include <string.h>
int SIZE = 80;


// Create a signal handler
void sigint_handler(int sig){
    // Ask yourself why 35?
    write(1,"\nTerminating through signal handler\n\n", 35);
    printf("\n==== MINI $HELL TERMINATED =====\n");
    exit(0);
}

// custom commands
// -help
// -exit
// -TBD
void instructionPrinter() {
    printf("===== A List Of COMMANDS =====\n");
    printf("n-cd()\n-help()\n-exit()\n-TBD()\n-ls()\n");
    printf("==============================\n");
}




int breadCrumbFunc (char* path) {
    char* myargv[10];
    myargv[0]=path;
    printf("%s", myargv[0]);
    char* temp = "./helloworld";
    printf( "%d",strcmp(temp, myargv[0]));

    myargv[1]=NULL;
    myargv[2]=NULL; // Terminate the argument list
    pid_t pid = fork();
      if(pid==0){
          // Executes command from child then terminates our process
          execve(temp,myargv,NULL);
          printf("Child: Should never get here\n");
          exit(1);
      }else {
          wait(NULL);
          // This call makes the parent wait on its children.
      }
    return 0;
}



int interpret(char* cmd){
    // character pointer used to iterate through strtok
    char* iter = NULL;
    
    // Look for position of the pipe symbol.
    // If pipe symbol is not in command, pPosition will be NULL.
    char* pPosition = strchr(cmd , '|');
    
    // When this following line is called,
    // strtok sets cmd[1] as the starting item.
    iter = strtok(cmd, " ");
    
    if (pPosition == NULL){
        breadCrumbFunc(cmd);
    }
    
    while (iter != NULL) {
  
        if (pPosition != NULL){
            
        }
        
          
        //Using Strtok to assign 'NULL' to end of token
        iter = strtok(NULL, " ,-");
    }
    return 0;
}



int main(int argc, const char * argv[]) {
    // Limiting the number of characters in each command to 80
    char str[80];
    
    // Install our signal handler
    signal(SIGINT, sigint_handler);
    
    printf("\n\n\n=== Welcome To MINISHELL ====\n");
    while(1){
        printf("\nMINI_$HELL>> ");
        char* cmd= fgets(str, SIZE, stdin);
    
        // Built-in help command -- call instructionPrinter, a helper function
        if (strncmp("help", str, 4) == 0){
                  instructionPrinter();
        }
        
        // Built-in cd command
        else if (strncmp(str, "cd", 2) == 0) {
         int end = (int)strlen(str);
         char endChar = str[end - 1];
             if (endChar == '\n') {
                 str[end - 1] = '\0';
             }
         chdir(&str[3]);
         char empty[100];
         printf("%s\n", getcwd(empty, 100));
        }
        
        // Built-in exit command
        else if (strncmp(str, "exit", 4) == 0){
            printf("\n==== EXITING MINI $HELL =====\n");
            printf("\n========== SEEYOU! ==========\n\n\n");
            exit(0);
        }
        
        // Built-in ls command that uses system's ls function
        else if (strncmp(str, "ls", 2) == 0) {
            char* myargv[10];
            myargv[0]="/bin/ls";
            myargv[1]="-F";
            myargv[2]=NULL; // Terminate the argument list
            if(fork()==0){
                // Executes command from child then terminates our process
                execve(myargv[0],myargv,NULL);
                printf("Child: Should never get here\n");
                exit(1);
            }else {
                wait(NULL); // This call makes the parent wait on its children.
            }
        }
        
        // If none of the built-in commands is hit, then interpret command.
        // Jump to interpret helper.
        else{interpret (cmd);}
        
        sleep(1);
    }
    return 0;
}
