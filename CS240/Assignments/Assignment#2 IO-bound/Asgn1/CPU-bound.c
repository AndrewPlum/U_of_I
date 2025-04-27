/*
Andrew Plum
Professor Wilder
CS 240
9/25/22
*/

    /*
    ***Assignment #2 - CPU-bound.c***
    */

// include libraries

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// main function

int main(){

    // create variables

    long unsigned int i = 0; // incremented variable
    clock_t start, end; // create clock variables; NOTE: given in seconds
    double cpu_time_used; // create time stored variable

    // start clock time right before loop

    start = clock(); // this method using clock() to calculate time is more accurate and precise

    // CPU-bound loop

    while(1){
        i++; // calculation performed
        //printf("%d\n", i); // print value
        end = clock(); // record clock time here
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate elapsed loop time
        if(cpu_time_used >= 300){ // exit loop condition
            exit(0); // terminate program
        }
    }

    // end of program

	return 0;
}
