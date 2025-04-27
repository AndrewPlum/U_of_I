/*
Andrew Plum
Professor Wilder
CS 240
10/21/22
*/

    /*
    ***Assignment #3 - msh.c***
    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h> // IS THIS C++ OR C
#include<sys/types.h>
#include<unistd.h>

// constant int

const int input_max = 256; // put max check with fgets

// prototypes

int makearg(char *s, char ***args);

// main function

int main(){

    // variable declarations

	int argc;
	char **argv;
	//char *word;
	char input_line[input_max];
	int i = 0;

	char command[input_max];
	char *parameters[input_max];
	char file_name[input_max];
	//char *envp[] = {(char *)"PATH=/bin", 0};

	// loop

	while(1){

        // prompt program message and input command

        printf(">:"); // prompt
        fgets(input_line, input_max, stdin);

        // makearg() called

        argc = makearg(input_line, &argv);

        printf("\nTEST");

        // parse input

        strcpy(command, argv[0]); // parse command
        strcpy(*parameters, "");
        for(i = 0; i < argc; i++){
            strcat(*parameters, argv[i]); // add parameters to string of characters
            strcat(*parameters, " "); // add space in between parameters to command
        }

        // free memory

        free(argv);

        // fork and execute command

        if(fork() != 0){ // spawn new process if
            wait(NULL);
        } else {
            strcpy(file_name, "msh.c");
            strcpy(file_name, command);
            execvp(file_name, parameters);//, envp); // execve() // execvp() system call
        }
        if(strcmp(command, "exit") == 0){
            break;
        }
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

	printf("\nTEST");

	return count; // should return -1 if error
}
