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
	char input_line[input_max];
	char copy_input_line[input_max];
	int i = 0;

	printf("Input a line of text: ");

	// read in line of input

	fgets(input_line, input_max, stdin);
	for(i = 0; i < input_max; i++){
        copy_input_line[i] = input_line[i];
	}

	// makearg() called

	argc = makearg(input_line, &argv);
	printf("Number of words in the input line: %d\nThe words are:\n", argc);

	// code to print each word

	char *word = strtok(copy_input_line, " ");
	while(word != NULL){
		printf("%s\n", word);
		word = strtok(NULL, " ");
	}

	return 0;
}

// definitions

int makearg(char *s, char ***args){

	// variable declarations

    int length = strlen(s);
    int count = 0;
    int count_copy = 0;
	int i = 0;
	char copy_s[length];
	char *word;
	char **arrp = (char **) malloc(length * sizeof(char));

	// return -1 if memory allocation fails

	if(arrp == NULL){
        count = -1;
        return count;
	}

	// make copy of string s[]

    for(i = 0; i < length; i++){
        copy_s[i] = s[i];
	}

    //count method

	word = strtok(s, " ");
	while(word != NULL){
		word = strtok(NULL, " ");
		count++;
	}
	if(strcmp(s, "\n") == 0){ // if nothing is entered set count to 0
        count = 0;
	}
    count_copy = count;

	// format memory with args

    args = &arrp;
	word = strtok(copy_s, " ");
    *arrp = word; // use star to dereference args, access its memory location, and change it to contain word
	i = 1; // i = 1 because first word already formated
	while(i != count_copy){
        word = strtok(NULL, " ");
        arrp[i] = word;
        i++;
	}

	return count; // should return -1 if error
}
