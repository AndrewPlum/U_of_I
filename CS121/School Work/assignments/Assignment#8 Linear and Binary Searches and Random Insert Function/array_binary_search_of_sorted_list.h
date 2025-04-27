    /*
	Andrew Plum
	CS 121-01
	Assignment #8
	3/10/22
	*/

		// I did all of the regular assignment. Outputs of both programs have data on the speed of the algorithms.

	/* array_binary_search_of_sorted_list.h */

#include<iostream>
using namespace std;

void selection_sort(int[], int); // used to sort the list
bool binary_search(int arr[], int, int, int); // used for the actual binary search

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

bool binary_search(int arr[], int low, int high, int f){
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        cout << low << " " << mid << " " << high << endl;
        if(arr[mid] == f){
            return true;
        }
        if(arr[mid] > f){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}
