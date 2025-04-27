/*
Andrew Plum
Professor Wilder
CS 240
9/9/22
*/

    /*
    ***Assignment #1***
    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// constant int

const int input_max = 256; // put max check with fgets

// prototypes

int makearg(char *s, char ***args);

// main function

int main(){
	int argc;
	char **argv;
	char *word;
	char input_line[input_max];
	int i = 0;

	// prompt program message and input line

	printf("Input a line of text: ");
	fgets(input_line, input_max, stdin);

	// makearg() called

	argc = makearg(input_line, &argv);
	printf("Number of words in the input line: %d\nThe words are:\n", argc);

	// code to print each word

	for(i = 0; i < argc; i++){
		word = argv[i];
		printf("%s\n", word);
	}

	// free memory

	free(argv);

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
