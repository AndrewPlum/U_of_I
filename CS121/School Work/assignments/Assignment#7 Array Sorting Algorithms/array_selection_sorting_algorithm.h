    /*
	Andrew Plum
	CS 121-01
	Assignment #7
	2/28/22
	*/

		// I did all of the regular assignment.

	/* array_selection_sorting_algorithm.h */

#include<iostream>
using namespace std;

void selection_sort(int[], int);

void selection_sort(int array[], int maxsize){
    int min = 0; // minimum
	int min_index = 0;
	int temp = 0;
	bool sorted;

	for(int i = 0; i < maxsize - 1; i++){
		min_index = i;
		for(int j = i + 1; j < maxsize; j++){
			if(array[j] < array[min_index]){
				min_index = j; // get new lowest value
			}
		}
		if(min_index != min){
            temp = array[min_index];
            array[min_index] = array[i];
            array[i] = temp;
		}
	}
}
