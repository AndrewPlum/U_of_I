/*
Andrew Plum
Professor Wilder
CS 240
11/19/22
*/

    /*
    ***Assignment #4 - ksim.c***
    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ksim_process.h> // header file I created

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

        printf("ksim"); // prompt
        num_lead_zeros = 9;
        ticks_copy = ticks;
        remainder = 1; // set equal to 1 so it enters next loop
        while(remainder > 0){
            remainder = ticks / 10;
            num_lead_zeros--;
        }
        ticks = ticks_copy;
        while(num_lead_zeros > 0){
            printf("0");
            num_lead_zeros--;
        }
        printf("%d>", ticks);
        fgets(input_line, input_max, stdin);




        // makearg() called

            //argc = makearg(input_line, &argv);

        // print for debugging

        /*
        for(i = 0; i < argc; i++){
            word = argv[i];
            printf("%s\n", word);
        }
        */

        // if "exit" enter exit loop

        if(strcmp(input_line, "exit\n") == 0){
            break;
        }
        ticks += 100;
    }

    // free memory

        //free(argv);

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
