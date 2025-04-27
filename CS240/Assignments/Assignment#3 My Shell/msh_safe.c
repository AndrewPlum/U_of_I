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
#include<string.h>
#include<sys/wait.h> // include for wait()
#include<unistd.h> // include for fork()

// constant int

const int input_max = 1024; // put max

// prototypes

int makearg(char *s, char ***args);

// main function

int main(){

    // variable declarations

    int argc;
    char **argv;
    char input_line[input_max];
    //int i; // used for debugging
    //char *word; // used for debugging

    // loop

    while(1){

        // prompt program message and input command

        printf(">:"); // prompt
        fgets(input_line, input_max, stdin);

        // makearg() called

        argc = makearg(input_line, &argv);

        // print for debugging

        /*
        for(i = 0; i < argc; i++){
            word = argv[i];
            printf("%s\n", word);
	    }
        */

        // fork and execute command

        if(fork() != 0){ // spawn new process
            wait(NULL);
        }else{
            execvp(argv[0], argv); // execvp() system call
            exit(0); // kill child process
        }

        // if "exit" enter exit loop

        if(strcmp(input_line, "exit\0") == 0){
            break;
        }
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

    count = 0;
    word = strtok(s, " \n");
    while(word != NULL){
        args[0][count] = word;
        count++;
        word = strtok(NULL, " \n");
    }

    // return

    return count; // should return -1 if error
}
