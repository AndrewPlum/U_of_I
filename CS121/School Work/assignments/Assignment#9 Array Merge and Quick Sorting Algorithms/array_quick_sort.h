    /*
	Andrew Plum
	CS 121-01
	Assignment #9
	3/24/22
	*/

		// I did all of the regular assignment.

	/* array_quick_sort.cpp.h */

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
using namespace std;

void quick_sort(int[], int, int);

void quick_sort(int arr[], int start, int end){
	if(end - start <= 1){
        return;
	}
	int *smaller = new int[end - start];
	int *larger = new int[end - start];
	int num_smaller = 0;
	int num_larger = 0;
	int pivot = arr[start]; // start is not the best choice for choosing a pivot makes it slow if the list is already sorted
	for(int i = start + 1; i < end; i++){
        if(arr[i] < pivot){
            smaller[num_smaller] = arr[i];
            num_smaller++;
        } else {
            larger[num_larger] = arr[i];
            num_larger++;
        }
	}
	quick_sort(smaller, 0, num_smaller);
	//for(int i = 0; i < num_smaller; i++){ // print list after each recursive call
	//	cout << smaller[i] << ", ";
	//}
	quick_sort(larger, 0, num_larger);
	//for(int i = num_smaller + 1; i < end; i++){ // print list after each recursive call
    //	cout << larger[i - (num_smaller + 1)] << ", ";
	//}
	//cout << endl; // makes output look better

	for(int i = 0; i < num_smaller; i++){
        arr[i] = smaller[i];
	}
	arr[num_smaller] = pivot;
	for(int i = num_smaller + 1; i < end; i++){
        arr[i] = larger[i - (num_smaller + 1)];
	}
}
