// Implement your cycle count tool here.
/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[]) {
    // First, we need to check that the two arguments are properly loaded. The
    // first refers the number of arguments ./tool will accept, and the second
    // argument refers the the assembly file to be run.
    if (argc !=2) {
    printf("invalid file!\n");
    return 1;
}
// Returning a file pointer using fopen in read mode
FILE* fileReader = fopen(argv[1], "r");


if (fileReader == NULL) {
    printf("Unable to open file! Please make sure file is in directory specified\n");
    return 1;
}

// Initialize all counters with value of 0.
    int counter_add =0;
    int counter_subtract =0;
    int counter_multi=0;
    int counter_div =0;
    int counter_mov =0;
    int cunter_leaq =0;
    int counter_push =0;
    int counter_pop =0;
    int counter_ret =0;

    int total_counters =0;


char ch;
// create an array string to store the string to be parsed
    char myString[1000]
    
    int i;
    for (i =0; i< 50; i++){
        ch = fgets(myString, 1000, filereader);
        char *keyword = strtok(myString, "\t");
        while(token != NULL){
            if (strcmp(keyword, "add") ==0 
                    ||
                strcmp(keyword, "addq") ==0
                    ||
                strcmp(meyword, "addb") ==0
                ){counter_add++; }
        
            if (strcmp(keyword, "sub") ==0){
                counter_subtract++; 
            }
            if (strcmp(keyword, "mul") ==0){
                counter_mult++;
            }
            if (strcmp(keyword, "div") ==0){
                counter_div++;
            }
            if (strcmp(keyword, "movq") ==0) {
                counter_mov++;
            }
            if (strcmp(keyword, "leaq") ==0) {
                counter_leaq++;
            }
            if (strcmp(keyword, "pushq") ==0){          
                counter_push++;
            }
            if (strcmp(keyword, "popq") ==0){
                counter_pop++;
            }
            if (strcmp(keyword, "ret") ==0) {
                counter_ret++;     
            }


}
