/*
Andrew Plum
Professor Wilder
CS 240
9/25/22
*/

    /*
    ***Assignment #2 - IO-bound.c***
    */

// include libraries

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// main function

int main(){

    // create variables

    int x = 1; // conditional variable
    clock_t start, end; // create clock variables; NOTE: given in seconds
    double cpu_time_used; // create time stored variable
    FILE *fp; // create file poiter

    // start clock time right before loop

    start = clock(); // this method using clock() to calculate time is more accurate and precise

    // IO-bound loop

    while(x){
        fp = fopen ("IO-bound-file.txt", "w"); // open and write to this file
        fprintf(fp, "a"); // write "a" to file
        fclose(fp); // close file
        end = clock(); // record clock time here
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate elapsed loop time
        if(cpu_time_used >= 300){ // exit loop condition
            x = 0;
        }
    }

    // print done

    //printf("Done\n");

    // terminate program

    exit(0);

    // end of program

	return 0;
}
