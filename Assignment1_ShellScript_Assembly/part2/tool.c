
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // First, we need to check that the two arguments are properly loaded.
    // The first refers the number of arguments ./tool will accept, and
    // the second argument refers the the assembly file to be run.
    if (argc != 2){
        printf("invalid file!\n");
        return 1;
    }
    // OPEN THE FILE
    FILE* fileReader = fopen(argv[1], "r");
    
    
    // Checking if the file is found
    if (fileReader == NULL){
        printf("File not found!\n");
        return 1;
    }

    // Initialize all counters to 0
    int counter_add = 0;
    int counter_sub = 0;
    int counter_multi = 0;
    int counter_div = 0;
    int counter_mov = 0;
    int counter_leaq = 0;
    int counter_push = 0;
    int counter_pop = 0;
    int counter_ret = 0;
    int totalCounter = 0;

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
    int counter_leaq =0;
    int counter_push =0;
    int counter_pop =0;
    int counter_ret =0;

    int total_counters =0;

    char myString[100];
    char ch;

    int i;
    for (i =0; i< 50; i++){
        ch = fgets(myString, 1000, fileReader);
        char *keyword = strtok(myString, "\t");
        while(keyword != NULL){
            if (strcmp(keyword, "add") ==0
                    ||
                strcmp(keyword, "addq") ==0
                    ||
                strcmp(keyword, "addb") ==0
                ){counter_add++; }
        
            if (strcmp(keyword, "sub") ==0){
                counter_subtract++;
            }
            if (strcmp(keyword, "mul") ==0){
                counter_multi++;
            }
            if (strcmp(keyword,"div") == 0){
                counter_div++;
            }
            if (strcmp(keyword,"movq")== 0){
                counter_mov++;
            }
            if (strcmp(keyword,"leaq") == 0){
                counter_leaq++;
            }
            if (strcmp(keyword,"pushq") == 0){
                counter_push++;
            }
            if (strcmp(keyword,"popq") == 0){
                counter_pop++;
            }
            if (strcmp(keyword,"ret") == 0){
                counter_ret++;
            }
            keyword = strtok(NULL, " ");
        }
    }
    // print results of each counter
    printf("=== counters ===\n");
    printf(" Add counter: %d\n", counter_add);
    printf(" Sub counter: %d\n", counter_sub);
    printf(" Mul counter: %d\n", counter_multi);
    printf(" Div counter: %d\n", counter_div);
    printf(" Mov counter: %d\n", counter_mov);
    printf(" Lea counter: %d\n", counter_leaq);
    printf(" push counter: %d\n",counter_push );
    printf(" pop counter: %d\n", counter_pop);
    totalCounter = (counter_add + counter_sub + counter_multi + counter_div + counter_mov + counter_leaq + counter_push + counter_pop);
    printf(" Total counts = %d\n", totalCounter);
    
   
    int addCycle = counter_add*2;
    int subCycle = counter_sub*2;
    int mulCycle = counter_multi*10;
    int divCycle = counter_div*31;
    int movCycle = counter_mov*1;
    int leaCycle = counter_leaq*1;
    int pushCycle =counter_push*3;
    int popCycle = counter_pop*3;
    int totalCycles = 0;

    printf("=== Cycles ===\n");
    printf(" Add cycles: %d\n", addCycle);
    printf(" Sub cycles: %d\n", subCycle);
    printf(" Mul cycles: %d\n", mulCycle);
    printf(" Div cycles: %d\n", divCycle);
    printf(" Mov cycles: %d\n", movCycle);
    printf(" Lea cycles: %d\n", leaCycle);
    printf(" push cycles: %d\n", pushCycle);
    printf(" pop cycles: %d\n", popCycle);    
    totalCycles = (addCycle + subCycle + mulCycle + divCycle + movCycle + leaCycle + pushCycle + popCycle);
    printf(" Total cycles = %d\n", totalCycles);
    
    // Close file After we are done 
    fclose(fileReader);

    return 0;
        
        }
    }
}


