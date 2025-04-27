    /*
	Andrew Plum
	CS 121-01
	Assignment #7
	2/28/22
	*/

		// I did all of the regular assignment.

	/* array_bubble_sorting_algorithm.cpp.h */

#include<iostream>
using namespace std;

void bubble_sort(int[], int);

void bubble_sort(int array[], int maxsize){
	int count = 0; // the number of times the counrter had to swap two numbers in the last sort
	int temp = 0; // temporary place holder
	do{
		count = 0;
		for(int i = 0; i < (maxsize - 1); i++){ // i < (maxsize - 1) because I don't want the if conditions check the outside
			if(array[i] > array[i + 1]){
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				count++;
			}
		}
	}while(count != 0);
}
