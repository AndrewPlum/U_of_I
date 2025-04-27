/*
Andrew Plum
Professor Bolden
CS 270
10/7/22
*/

    /*
    ***Assignment #1 - Part 3 - array_main.c***
    */

// Libraries

#include<stdio.h>
#include<stdlib.h>

// Prototypes

void array_sum_and_avaerage(int[], int);
void array_maximum(int[], int);
void array_minimum(int[], int);

// Main

int main(){

	// variables

	int i = 0;
	int arr_size = 10;
	int arr[arr_size];

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

	array_sum_and_average(arr, arr_size);
	array_maximum(arr, arr_size);
	array_minimum(arr, arr_size);

	// end of program

	return 0;

}
