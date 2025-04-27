    /*
	Andrew Plum
	CS 121-01
	Assignment #9
	3/24/22
	*/

		// I did all of the regular assignment.

	/* array_merge_sort.cpp */

        /*
        Comparison of the merge and quick sorting algorithm:

        The merge sorting algorithm and the quick sorting algorithm were both very quick at sorting.
        They both used arrays. The merge sorting algorithm had a more consistent sorting speed whereas
        the quick sorting algorithm had more variability with its sorting speed. The quick sorting
        algorithm was quicker if the initial list was near or already sorted, but it was clearly
        slower if the initial list was near or completely sorted backwards. The way the list was initially
        sorted did not appear to have an affect on the performance of the merge sorting algorithm. The
        merge sorting algorithm was more memory intensive as multiple arrays were used whereas the
        quick sorting algorithm was not as memory intensive. The merge sorting algorithm was also quicker
        the more cores the computer processor had.
        */

#include<iostream>
#include"array_merge_sort.h"
#include<cstdlib> // srand
#include<ctime>
using namespace std;

int main(){

	// Seed with 777

    srand(777); // random seed 777

    // Intro

    cout << endl;
    cout << "This is program which demonstrates merge sort using arrays." << endl;
    cout << endl;

    // Create variables and arrays for array 1

	const int maxsize = 100000;
	int magnitude = 100;
	int array[maxsize];
	int orig_array[maxsize]; // holds the original array values

	// Fill array with random values

	for(int i = 0; i < maxsize; i++){
		array[i] = (rand() % magnitude);
		orig_array[i] = array[i]; // copy values
	}

	// Merge sort the array

	merge_sort(array, 0, (maxsize - 1));

	// Print the original array and the now sorted array

	cout << endl;
	cout << "Original array:" << endl;
	for(int i = 0; i < maxsize; i++){
		cout << orig_array[i] << ", ";
	}
	cout << endl;

	cout << endl;
	cout << "Sorted array:" << endl;
	for(int i = 0; i < maxsize; i++){
		cout << array[i] << ", ";
	}
	cout << endl;

	return 0;

}
