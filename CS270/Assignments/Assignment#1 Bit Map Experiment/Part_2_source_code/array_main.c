/*
Andrew Plum
Professor Bolden
CS 270
10/7/22
*/

    /*
    ***Assignment #1 - Part 1 and 2 - array_main.c***
    */

// Libraries

#include<stdio.h>
#include<stdlib.h>

// Globals

#define arr_size 10
int arr[arr_size];

// Prototypes

void array_sum_and_avaerage();
void array_maximum();
void array_minimum();

// Main

int main(){

	// variables

	int i = 0;

	// fill array

	for(; i < arr_size; i++){
		arr[i] = i + 1;
	}

	// print array

	printf("Array:\n");
	for(i = 0; i < arr_size; i++){
		printf("%d\n", arr[i]);
	}

	// call functions

	array_sum_and_average();
	array_maximum();
    array_minimum();

	// end of program

	return 0;

}
