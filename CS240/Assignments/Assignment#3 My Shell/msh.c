/*
Andrew Plum
Professor Wilder
CS 240
10/24/22
*/

    /*
    ***Assignment #3***
    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
	//#include"sys/wait.h"



// constant int

const int input_max = 256; // put max check with fgets

// prototypes

int makearg(char *s, char ***args);

// main function

int main(){
	int argc;
	char **argv;
	//char *word;
	char input_line[input_max];
	//int i = 0;

	// loop

	while(1){

		// prompt program message and input line

		printf(">:");
		fgets(input_line, input_max, stdin);

		// makearg() called

		argc = makearg(input_line, &argv);

		// check if "exit"

		if(strcmp(input_line, "exit\0") == 0) {
			break;
		}

		// fork and exec call

/*
		if(fork() != 0){
			wait(NULL);
		}else{
			execvp(argv[0], argv);
		}
*/

		fork();

		// check pid

		if(getpid() == 0){
			execvp(argv[0], argv);
		}



		// free memory

		free(argv);
	}

	// end of main()

	return 0;
}

// definitions

int makearg(char *s, char ***args){

	// variable declarations

    int count = 0;
	int i = 0;
	char *word;

	// memory allocation

	*args = (char **) malloc(strlen(s) * sizeof(char));

	// return -1 if memory allocation fails

	if(*args == NULL){
        count = -1;
        return count;
	}

    //count number of words and format args

	word = strtok(s, " \n");
	while(word != NULL){
		args[0][count] = word;
		count++;
		word = strtok(NULL, " \n");
	}

	return count; // should return -1 if error
}
