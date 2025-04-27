/*
Andrew Plum
Professor Bolden
CS 270
10/7/22
*/

    /*
    ***Assignment #1 - Part 3 - array_maximum.c***
    */

#include<stdio.h>
#include<stdlib.h>

void array_maximum(int arr[], int arr_size){

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
