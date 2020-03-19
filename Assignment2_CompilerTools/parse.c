// Implement a working parser in this file that splits text into individual tokens.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    // character pointer used to iterate through strtok
    char* iter = NULL;

    // When this following line is called, strtok sets argv[1] as the starting
    // item.
    iter = strtok(argv[1], " ");
   
    while (iter != NULL) {
        printf("%s\n", iter);
        //Using Strtok to assign 'NULL' to end of token
        iter = strtok(NULL, " ,-");
    }

    return 0;

}
