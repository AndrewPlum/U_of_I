/*
Andrew Plum
Professor Bolden
CS 270
10/7/22
*/

    /*
    ***Assignment #1 - Part 3 - array_sum_and_average.c***
    */

#include<stdio.h>
#include<stdlib.h>

void array_sum_and_average(int arr[], int arr_size){

	int i = 0;
	int sum = 0;
	int average = 0;

	for(; i < arr_size; i++){
		sum += arr[i];
	}
	average = sum / arr_size;

	printf("Sum:\n%d\n", sum);
	printf("Average:\n%d\n", average);

	return;

}
