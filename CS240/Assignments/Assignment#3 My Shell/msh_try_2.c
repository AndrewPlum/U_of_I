/*
Andrew Plum
Professor Wilder
CS 240
10/21/22
*/

    /*
    ***Assignment #3 - msh***
    */

        /*
            Questions and To Do:
            10)Cant do multiple words with echo - multiple parameters?
        */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h> // include for wait()
#include<unistd.h> // include for fork()

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
  //  char **argv_copy;

    int i;
    char *word;

    // loop

    while(1){

        // prompt program message and input command

        printf(">:"); // prompt
        fgets(input_line, input_max, stdin);

        // makearg() called

        argc = makearg(input_line, &argv);

//        argv_copy = (char **) malloc(argc * sizeof(char));

/*	for(i = 0; i < argc; i++){
            strcpy(argv_copy[i],argv[i]);
        }
*/
        // print for debug

        
  /*      for(i = 0; i < argc; i++){
		    word = argv_copy[i];
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

    free(argv); // SHOULD THIS BE IN LOOP!!!!?

    // end of main()

    return 0;
}

// definitions

int makearg(char *s, char ***args){

    // variable declarations

    int count = 0;
    int count_copy = 0;
    int i = 0;
    char *word;
    char *s_copy = (char *) malloc(strlen(s) * sizeof(char)); // used to count number of tokens

    // use strcpy() to set s_copy equal to s
    
    strcpy(s_copy,s);
    //printf("%s\n",s);

    // count number of tokens in string copy so count can be used in malloc()

    count = 0;
    word = strtok(s_copy, " \n");
    while(word != NULL){
        count++;
        word = strtok(NULL, " \n");
    }
    count_copy = count;

    // memory allocation

    *args = (char **) malloc(count * sizeof(char));

    //*args = (char **) malloc(strlen(s) * sizeof(char));

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

    //printf("%d", count);
    //*args = (char **) realloc(args, count * sizeof(char));

    return count; // should return -1 if error
}
