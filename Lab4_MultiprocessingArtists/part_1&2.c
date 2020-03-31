//
//  main.c
//  basic_fork
//
//  Created by Yu Lin on 3/31/20.
//  Copyright © 2020 Yu Lin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Modify your paint function here
void paint(int workID){
    printf("Artist %d is painting\n",workID);
}

int main(int argc, char** argv){
    int* integers = malloc(sizeof(int)*8000);

    int numberOfArtists = 8; // How many child processes do we want?

    pid_t pid;
    // main loop where we fork new threads
        for(int i =0; i < numberOfArtists; i++){
                // (1) Perform a fork
            pid = fork();
        
        
                // (2) Make only the child do some work (i.e. paint) and then terminate.
                if(pid== 0){
            // TODO: make child paint
                paint(i);
            // TODO: Then terminate/exit child
            return 0;
        }
        }
    wait(NULL);
    printf("parent is exiting(last artist out!)\n");
    free(integers);
return 0;
}
