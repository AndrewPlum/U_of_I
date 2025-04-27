/*
Andrew Plum
Professor Bolden
CS 270
10/7/22
*/

    /*
    ***Assignment #1 - Part 1 and 2 - array_minimum.c***
    */

#include<stdio.h>
#include<stdlib.h>

#define arr_size 10
extern int arr[arr_size];

void array_minimum(){

	int i = 0;
	int min = arr[0]; // set max equal to first element

	for(; i < arr_size; i++){
		if(min > arr[i]){
            min = arr[i];
		}
	}

	printf("Array minimum:\n%d\n", min);

	return;

}
