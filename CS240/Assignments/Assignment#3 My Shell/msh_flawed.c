/*
Andrew Plum
Professor Wilder
CS 240
10/21/22
*/

    /*
    ***Assignment #3 - msh.c***
    */

        /*
            Questions and To Do:
            1)Libraries
            2)Free argv placement
            3)Input max causing memory error
            4)Have to exit twice?
            5)Makefile
            6)Modular code?
            7)Parse by character vs by token using strtok()
            8)Can makearg be used from assignment#1
            9)Tar and submit
            10)Cant do multiple words with echo - multiple parameters?
        */

#include<stdio.h>
#include<stdlib.h>
#include<string.h> // IS THIS C++ OR C
//#include<sys/types.h> // IS THIS RIGHT?
#include<unistd.h>

// constant int

const int input_max = 256; // put max

// prototypes

int makearg(char *s, char ***args);

// main function

int main(){

    // variable declarations

    int argc;
    char **argv;
    char input_line[input_max];
    pid_t pid;

    // loop

    while(1){

        // prompt program message and input command

        printf(">:"); // prompt
        fgets(input_line, input_max, stdin);

        // makearg() called

        argc = makearg(input_line, &argv);

        // fork and execute command

        pid = fork(); // spawn new process
        if(pid == 0){
            execvp(argv[0], argv); // execvp() system call
            exit(0); // kill child process
        }

        // if "exit" enter exit loop

        if(strcmp(input_line, "exit\0") == 0){
            break;
        }
    }

    // free memory

    free(argv); // SHOULD THIS BE IN LOOP!!!!?

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
