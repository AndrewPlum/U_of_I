    /*
	Andrew Plum
	CS 121-01
	Assignment #9
	3/24/22
	*/

		// I did all of the regular assignment.

	/* array_merge_sort.h */

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

void merge_sort(int[], int, int); // breaks down array
void merge(int[], int, int, int); // puts array back together

void merge_sort(int array[], int begin, int end){


	if(begin < end){ // exit condition
		int mid = (begin + end) / 2; // get mid index value of array
		merge_sort(array, begin, mid); // merge sort left half
		merge_sort(array, mid + 1, end); // merge sort right half
		merge(array, begin, mid, end); // put array back to better
	}
}

void merge(int array[], int left, int mid, int right){
	int temp[right]; // create array of maxsize
	int first_right = mid+1;
	int index = left;
	int save = left; // saved original left value

	while((left <= mid) && (first_right <= right)){
		if(array[left] < array[first_right]){
			temp[index] = array[left];
			left++;
		}
		else{
			temp[index] = array[first_right];
			first_right++;
		}
		index++;
	}

	while(left <= mid){
		temp[index] = array[left];
		left++;
		index++;
	}
	while(first_right <= right){
		temp[index] = array[first_right];
		first_right++;
		index++;
	}

	for(index = save ; index <= right ; index++){
		array[index] = temp[index];
		// cout << array[index] << ", "; // print the array
	}
	//cout << endl;
}
