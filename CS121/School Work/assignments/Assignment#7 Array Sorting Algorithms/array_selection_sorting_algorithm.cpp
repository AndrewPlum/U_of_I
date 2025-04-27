    /*
	Andrew Plum
	CS 121-01
	Assignment #7
	2/28/22
	*/

		// I did all of the regular assignment.

	/* array_selection_sorting_algorithm.cpp */

#include<iostream>
#include"array_selection_sorting_algorithm.h"
#include<cstdlib> // srand
#include<ctime>
using namespace std;

int main(){

	// Seed with

    srand(time(NULL));

    // Intro

    cout << endl;
    cout << "This is program which demonstrates the selection sorting algorithm using arrays." << endl;
    cout << endl;

    // Create variables and arrays

	const int maxsize = 100;
	int array[maxsize];
	int orig_array[maxsize]; // holds the original array values

	// Fill array with random values

	for(int i = 0; i < maxsize; i++){
		array[i] = (rand() % maxsize + 1);
		orig_array[i] = array[i]; // copy values
	}

	// Selection sort the array

	selection_sort(array, maxsize);

	// Print the original array and the now sorted array

	cout << "Original array:" << endl;
	for(int i = 0; i < maxsize; i++){
		cout << orig_array[i] << endl;
	}
	cout << endl;

	cout << "Sorted array:" << endl;
	for(int i = 0; i < maxsize; i++){
		cout << array[i] << endl;
	}
	cout << endl;

	return 0;

}
