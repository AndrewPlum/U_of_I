/*
Andrew Plum
Professor Bolden
CS 270
10/7/22
*/

    /*
    ***Assignment #1 - Part 1 and 2 - array_maximum.c***
    */

#include<stdio.h>
#include<stdlib.h>

#define arr_size 10
extern int arr[arr_size];

void array_maximum(){

	int i = 0;
	int max = arr[0]; // set max equal to first element

	for(; i < arr_size; i++){
		if(max < arr[i]){
            max = arr[i];
		}
	}

	printf("Array maximum:\n%d\n", max);

	return;

}
