// Implement your cycle count tool here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // checking to make sure we receive 2 arguments, the first argument is ./tool
    // second argument is the assembly file to be run.
    if (argc != 2){
        printf("invalid file!\n");
        return 1;
    }
    // Returning a file pointer using fopen in read mode
    FILE* fileReader = fopen(argv[1], "r");
    
    char ch;

    // Checking if the file is found
    if (fileReader == NULL){
        printf("File not found!\n");
        return 1;
    }

    // Initialize all counters to 0
    int addCounter = 0;
    int subCounter = 0;
    int mulCounter = 0;
    int divCounter = 0;
    int movCounter = 0;
    int leaCounter = 0;
    int pushCounter = 0;
    int popCounter = 0;
    int retCounter = 0;
    int totalCounter = 0; 
    // create a 100 character array string to ensure there was enough space.
    char myString[100];

    int i;
    // for loop is necessary to reset ch each time. 
    for (i = 0; i < 50; i++){
        ch = fgets(myString, 100, fileReader);
        char *token = strtok(myString, " \t");
        while (token != NULL){
            if ((strcmp(token,"add") ==0) ||(strcmp(token,"addq") == 0) || (strcmp(token,"addb")==0)){
                addCounter++;
            }   
            if (strcmp(token,"sub") == 0){
                subCounter++;
            }
            if (strcmp(token,"mul") == 0){
                mulCounter++;
            }
            if (strcmp(token,"div") == 0){
                divCounter++;
            }
            if (strcmp(token,"movq")== 0){
                movCounter++;
            }
            if (strcmp(token,"leaq") == 0){
                leaCounter++;
            }
            if (strcmp(token,"pushq") == 0){
                pushCounter++;
            }
            if (strcmp(token,"popq") == 0){
                popCounter++;
            }
            if (strcmp(token,"ret") == 0){
                retCounter++;
            }
            token = strtok(NULL, " ");
        }
    }
    // output results
    printf("=== Output counter ===\n");
    printf(" Add counter: %d\n", addCounter);
    printf(" Sub counter: %d\n", subCounter);
    printf(" Mul counter: %d\n", mulCounter);
    printf(" Div counter: %d\n", divCounter);
    printf(" Mov counter: %d\n", movCounter);
    printf(" Lea counter: %d\n", leaCounter);
    printf(" push counter: %d\n", pushCounter);
    printf(" pop counter: %d\n", popCounter);
    totalCounter = (addCounter + subCounter + mulCounter + divCounter + movCounter + leaCounter + pushCounter + popCounter);
    printf(" Total counts = %d\n", totalCounter);
    //Add typically takes between 1 and 3 cycles, so we will average it to 2 cycles per call. The total number of cycles = number of times add is called * 2.
    //Sub typically takes between 1 and 3 cycles, so ew will average it to 2 cycles per call.the total number of cycles = number of times sub is called * 2.
    //Mul typically takes between 9 and 11 cycles, so we will average it to 10 cycles per call. The total number of cycles = number of times Mul is called * 10.
    //Div typically takes between 17 and 46 cycles per call. We will average it to 31 cycles per call. The total numnber of cycles = number of times Div is called * 31. 
    //Mov takes ~ 1 cycle, so the total number of cycles = number of times mov is called*1.
    //Lea takes ~ 1 cycle, so the total number of cycles = number of times lea is called*1.
    //Push takes between 1 - 5 cycles, so we will average it to 3 cycles/push call. The total number of cycles for push is number of times push is called * 3. 
    //Pop typically takes between 1 to 6 cycles per call, so we will average it to 3 cycles per call. The total number of cycles = number of times Pop is called * 3.
    int addCycle = addCounter*2;
    int subCycle = subCounter*2;
    int mulCycle = mulCounter*10;
    int divCycle = divCounter*31;
    int movCycle = movCounter*1;
    int leaCycle = leaCounter*1;
    int pushCycle = pushCounter*3;
    int popCycle = popCounter*3;
    int totalCycles = 0;

    printf("=== Cycle Counter ===\n");
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
    
    // Close file when we are finished. 
    fclose(fileReader);

    return 0;
}


