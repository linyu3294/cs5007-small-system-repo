// Modify this file for your assignment


#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // This is new!
#include <unistd.h>     
#include <sys/wait.h>	
#include <math.h>
#include <time.h>
#include <string.h>

int BUFFER_SIZE = 80;


// Tried my best. Ultimately I could not get the piping to fully work. I believe it had to do something with my parsing and how I pass the parsed input into the piping function. Was not able to figure out the solution in time. I was able to get the basic structure of the pipe function, but was not able to get it to work due to parsing issues. Parsing works well otherwise.  To run the guessing game, you must type 'guessingGame' in camelCase. 



// Create a signal handler
void sigint_handler(int sig){
	// Ask yourself why 35?
	write(1,"Terminating through signal handler\n",35); 
	exit(0);
}



// custom commands 
// -help
// -exit
// -guessingGame

void helpPrinter(){
	printf(" === YOUR BUILT IN COMMANDS ===\n");
	printf("-help()\n-exit()\n-guessingGame()\n");
	printf(" ==============================\n");
}


// guessingGame function
int guessingGame(){
	int rounds[5];
	int i = 0;
	int j;
	int upper = 10;
	int lower = 1;
	for (j = 1; j <= 5;j++){
		srand(time(0));
		int randomNumber = rand()%upper+lower;
		int numGuessesThisRound = 0;
                printf("=============\n");
                printf("CPU Says: Pick a number 1-10\n");
                printf("=============\n ");
		int userGuess;
		while (1) {
			numGuessesThisRound++;
			scanf("%d", &userGuess);
			if (userGuess == randomNumber){
				printf("Correct!\n");
				rounds[i] = numGuessesThisRound;
				i++;
				break;
			}	
			else if (userGuess > randomNumber) {
				printf("Guess too high!\n");
			}
			else { 
				printf("Guess too low!\n");
			}		
		}
	}
	int k;
	printf("===============\n");
	printf("Here are the results of your game!");
	printf("\n===============\n");
	for (k = 0; k < 5; k++){
		printf("Game %d took you %d guesses\n", k, rounds[k]);
	}
	return 0;
}

// left pipe helper function to parse left commands before pipe
char** leftPipeHelper(char** userString){
	char** leftPipeArray; //initialize leftPipeArray
	int leftPipeLength = strlen(userString);
	int i;
	int pipeIndex;
	for (i = 0; i<leftPipeLength; i++){ //look for pipe
		if (userString[i] == '|'){
			pipeIndex = i; //assign index
		}
	}	
	char** leftArray[leftPipeLength + 1];
	int j;
	for (j = 0; j < pipeIndex; j++){
		leftArray[j] = userString[j]; //create left pipe sub array
	}
	return leftArray; //return subarray
}


// right pipe helper function to parse right commands after pipe
char** rightPipeHelper(char** userString){
	char** rightPipeArray; //initialize rightPipeArray
	int rightPipeLength = strlen(userString);
	int i;
	int pipeIndex;
	for (i = 0; i < rightPipeLength; i++){ //look for pipe
		if (userString[i] == '|'){
			pipeIndex = i; //assign index
		}
	}
	int rightPipeCounter = 0;
	int j;
	for (j = pipeIndex; j < rightPipeLength; j++){ //counting length of array after pipe
		rightPipeCounter++;
	}	
	char** rightArray[rightPipeCounter];
	int x;
	for (x = pipeIndex; x < rightPipeLength; x++){ 
		rightPipeArray[j] = userString[j]; //create right pipe sub array
	}
	return rightPipeArray; //return subarray
}


char** stringParser(char* userString) {
	int i;
	int len;
	int numWords = 1;
	len = strlen(userString);
	for (int i = 0; i < len; i++){ //delimit with a space and checking if next word is a space
		if (userString[i] != ' ' && userString[i+1] == ' '){ 
			numWords++;
		}
	}
	// find number of words in a string
	char** myArray  = (char**)malloc(sizeof(char*) * numWords + 1);
	char* iterator;
	iterator = strtok(userString, " \n");
	i = 0; 
	while (iterator != NULL){ //iterate through word list
		myArray[i] = iterator; // adding to the array 	
		i++;
		iterator = strtok(NULL, " \n");
	}
	myArray[numWords] = NULL; //set last index of array to NULL
	return myArray;
}


//pipeFinder helper function looks for pipe in user string and returns 0 if true.
//returns -1 if pipe is not found
int pipeFinder(char** parsedString){
	int stringLength = strlen(parsedString);
	int i = 0;
	while (parsedString[i] != NULL){
		if (strcmp(parsedString[i],"|") == 0) { //if pipe found, return 0 on success. 
			return 0;
		}
	i++;
	}
	return -1;
}


// pipe helper function 
//void pipingHelper(char* left, char* right){
void pipingHelper(char** left, char** right){
	int fileDescriptor[2]; //initializing file descriptor to size 2
	if (pipe(fileDescriptor) == -1){ //check if failed
		perror("Pipe failed");
		exit(1);
	}
	char** parsedLeft = stringParser(left);
	if (fork() == 0){
		dup2(fileDescriptor[1], 1); 
		close(fileDescriptor[0]);
		close(fileDescriptor[1]);
		execvp(parsedLeft[0], parsedLeft);
		printf("Error should not get here\n");
		exit(0);
	}

	char** parsedRight = stringParser(right);
	if (fork() == 0){
		dup2(fileDescriptor[0], 0); 
		close(fileDescriptor[0]);
		close(fileDescriptor[1]);
		execvp(parsedRight[0], parsedRight);
		printf("Error should not get here\n");
		exit(0);
	}
	close(fileDescriptor[0]);
	close(fileDescriptor[1]);
	wait(NULL);
	wait(NULL);
	free(parsedLeft);
	free(parsedRight);
}



int main(int argc, char* argv[]) {
	signal(SIGINT, sigint_handler);
	char str[80];
	while(1){
		printf("\nMINI_$HELL>> ");
		fgets(str, BUFFER_SIZE, stdin);
		// help command
		if (strncmp("help", str, 4) == 0){
			helpPrinter();
		} 
		// exit command
		else if (strncmp(str,"exit", 4) == 0){
			printf("\n=== TERMINATING MINI $HELL ===\n");
			printf("\n========== GOODBYE! ==========\n\n\n");
			exit(0);
		}
		// guessingGame command
		else if (strncmp(str,"guessingGame", 12) == 0){
			guessingGame();		
		}
		// cd command
		else if (strncmp(str, "cd", 2) == 0) {
			int end = strlen(str);
			char endChar = str[end - 1];
			if (endChar == '\n') {
				str[end - 1] = '\0';
			}
			chdir(&str[3]);
			char empty[100];
			printf("%s\n", getcwd(empty, 100));	
		}
		// if this condition is reached, command is not built-in command
		else {		
			char* stringCopy;
			strcpy(stringCopy, str);
			char** parsedString = stringParser(str);
			if (pipeFinder(parsedString) == 0) { //check if pipe is found
				char** leftCommand = leftPipeHelper(stringCopy);
				char** rightCommand = rightPipeHelper(stringCopy);
				pipingHelper(leftCommand, rightCommand);		
			}
			else {
				char** parsedString = stringParser(str);
				pid_t pid = fork();
				if (pid == 0) {
					// Executes command from child then terminates our process
					execvp(parsedString[0], parsedString);
					printf("Input not recognized, did you mean something else?\n");
					exit(1);
				} else {
					wait(NULL); // This call makes the parent wait on its children.
					free(parsedString);
				}
			}
		}
	}
} 
