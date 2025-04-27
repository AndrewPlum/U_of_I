    /*
	Andrew Plum
	CS 121-01
	Assignment #8
	3/10/22
	*/

		// I did all of the regular assignment. Outputs of both programs have data on the speed of the algorithms.

	/* array_binary_search_of_sorted_list.cpp */

#include<iostream>
#include"array_binary_search_of_sorted_list.h" // used to sort the array list
#include<cstdlib> // srand
#include<ctime>
using namespace std;

int main(){

	// Seed with

    srand(time(NULL));

    // Intro and array 1 binary search which uses 100 elements

    cout << endl;
    cout << "This is program which demonstrates binary searches on sorted list using arrays. Only the first array is printed. Binary search results are found at the bottom of the output." << endl;
    cout << endl;

    // Create variables and arrays for array 1

	const int maxsize = 100;
	int array[maxsize];
	int orig_array[maxsize]; // holds the original array values
	int result; // stores binary search result

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

	cout << "Binary Search using array 1:" << endl;
	int find = 99;
    clock_t t; // create timer
	t = clock(); //start timer
	result = binary_search(array, 0, maxsize, find);
	t = clock() - t; // end time
	cout << "Was " << find << " in the array(1 for yes and 0 for no):" << result << endl;
    cout << "Time to complete binary search on sorted array of size " << maxsize << ": " << t << " ms" << endl;
    cout << endl;


    // Binary search using array 2 which uses 1000 elements


	const int maxsize2 = 1000;
	int array2[maxsize2];
	int result2; // stores binary search result

	// Fill array with random values

	for(int i = 0; i < maxsize2; i++){
		array2[i] = (rand() % maxsize2 + 1);
	}

	// Selection sort array 2

	selection_sort(array2, maxsize2);

	cout << "Binary Search using array 2:" << endl;
	int find2 = 99;
	t = clock(); //start timer
	result2 = binary_search(array2, 0, maxsize2, find2);
	t = clock() - t; // end time
	cout << "Was " << find2 << " in the array(1 for yes and 0 for no):" << result2 << endl;
    cout << "Time to complete binary search on sorted array of size " << maxsize2 << ": " << t << " ms" << endl;
    cout << endl;


    // Binary search using array 3 which uses 10000 elements


	const int maxsize3 = 10000;
	int array3[maxsize3];
	int result3; // stores binary search result

	// Fill array with random values

	for(int i = 0; i < maxsize3; i++){
		array3[i] = (rand() % maxsize3 + 1);
	}

	// Selection sort array 3

	selection_sort(array3, maxsize3);

	cout << "Binary Search using array 3:" << endl;
	int find3 = 99;
	t = clock(); //start timer
	result3 = binary_search(array3, 0, maxsize3, find3);
	t = clock() - t; // end time
	cout << "Was " << find3 << " in the array(1 for yes and 0 for no):" << result3 << endl;
    cout << "Time to complete binary search on sorted array of size " << maxsize3 << ": " << t << " ms" << endl;
    cout << endl;


    // Binary search using array 4 which uses 50000 elements


	const int maxsize4 = 50000;
	int array4[maxsize4];
	int result4; // stores binary search result

	// Fill array with random values

	for(int i = 0; i < maxsize4; i++){
		array4[i] = (rand() % maxsize4 + 1);
	}

	// Selection sort array 4

	selection_sort(array4, maxsize4);

	cout << "Binary Search using array 4:" << endl;
	int find4 = 99;
	t = clock(); //start timer
	result4 = binary_search(array4, 0, maxsize4, find4);
	t = clock() - t; // end time
	cout << "Was " << find4 << " in the array(1 for yes and 0 for no):" << result4 << endl;
    cout << "Time to complete binary search on sorted array of size " << maxsize4 << ": " << t << " ms" << endl;
    cout << endl;

	return 0;

}
