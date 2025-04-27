/*********************************************
 * Id: plum0598
 *
 * This program compares how long it takes for 
 * selection sort, insertion sort, and quick sort 
 * sorting algorithms to sort an array of elements
 * that varies in size
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

// Prototypes

void selection_sort(int array[], int size);
void insertion_sort(int array[], int size);
int hoares_partition(int array[], int left, int right);
void quick_sort(int array[], int low, int high, int array_length);
void swap(int *x, int *y);
void randomize_array(int array[], int size);

// Main

int main(int argc, char *argv[]){
   
   srand(time(NULL));
   struct timeval start, stop;
   int selection_sort_times[3];
   int selection_sort_time_index = 0;
   int insertion_sort_times[3];
   int insertion_time_index = 0;
   int quick_sort_times[3];
   int quick_time_index = 0;
   
   int i;
   for (i = 3; i <= 5; i++){
      int size = (int)pow(10, i);
      int array[size];
      printf("%d\n", size);

      randomize_array(array, size);
      gettimeofday(&start, NULL);
      selection_sort(array, size);
      gettimeofday(&stop, NULL);
      selection_sort_times[selection_sort_time_index] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
      selection_sort_time_index++;

      randomize_array(array, size);
      gettimeofday(&start, NULL);
      insertion_sort(array, size);
      gettimeofday(&stop, NULL);
      insertion_sort_times[insertion_time_index] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
      insertion_time_index++;

      randomize_array(array, size);
      gettimeofday(&start, NULL);
      quick_sort(array, 0, size - 1, size);
      gettimeofday(&stop, NULL);
      quick_sort_times[quick_time_index] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
      quick_time_index++;
   }

   printf("//+-----------------------+-----------------+----------------+------------+\n");
   printf("//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |\n");
   printf("//+-----------------------+-----------------+----------------+------------+\n");
   printf("//|                   1000|               %d|              %d|          %d|\n",selection_sort_times[0],insertion_sort_times[0],quick_sort_times[0]);
   printf("//|                  10000|               %d|              %d|          %d|\n",selection_sort_times[1],insertion_sort_times[1],quick_sort_times[1]);
   printf("//|                 100000|               %d|              %d|          %d|\n",selection_sort_times[2],insertion_sort_times[2],quick_sort_times[2]);
   printf("//+-----------------------+-----------------+----------------+------------+\n");
   return 0;
}

// Sorts an array of integers using selection sort.

void selection_sort(int array[], int size){
   int i, j;
   for(i = 0; i < size - 1; i++){
      int minIndex = i;
      for(j = i + 1; j < size; j++){
         if(array[j] < array[minIndex]){
            minIndex = j;
         }
      }
      swap(&array[minIndex], &array[i]);
   }
}

// Swaps the position of two integer elements.

void swap(int *a, int *b){
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

// Sorts an array of integers using insertion sort

void insertion_sort(int array[], int size){
   
   // declare indexes
   
   int i, j;
   
   // print each iteration of the sort
   
   for(i = 1; i < size; i++){
      int v = array[i];
      j = i - 1;
      while(j >= 0 && array[j] > v){
         array[j + 1] = array[j];
         j = j - 1;
      }
      array[j + 1] = v;
   }
}

// Hoare's Partition: algorithm which splits array into 2 subarrays where left side is less than the pivot and the right side is greater than the pivot

int hoares_partition(int array[], int low, int high){
   int pivot = array[low];
   int i = low;
   int j = high + 1;

   while(i < j){
      i++; // initial increment
      while(array[i] < pivot){
         i++;
      }
      j--; // initial decrement
      while(array[j] > pivot){
         j--;
      }

      if (i < j) {
         swap(&array[i], &array[j]); // pass the addresses of the elements to swap
      }
   }

   swap(&array[low], &array[j]); // pass the addresses of the elements to swap
   
   return j;
}

// Quick sort sorting algorithm

void quick_sort(int array[], int low, int high, int array_length){
   if(low < high){

      int split = hoares_partition(array, low, high);

      // separately sort elements before partition and after partition

      quick_sort(array, low, split - 1, array_length);
      quick_sort(array, split + 1, high, array_length);
      
   }
}

// Randomizes the elements of an array passed in as an argument

void randomize_array(int array[], int size){
   int i;
   for (i = 0; i < size; i++){
      array[i] = rand() % 10;
   }
}

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                   1000|               1|              0|          0|
//|                  10000|               145|              73|          0|
//|                 100000|               14539|              7298|          8|
//+-----------------------+-----------------+----------------+------------+

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                   1000|               1|              0|          0|
//|                  10000|               146|              74|          0|
//|                 100000|               14540|              7305|          9|
//+-----------------------+-----------------+----------------+------------+

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                   1000|               1|              0|          0|
//|                  10000|               145|              73|          0|
//|                 100000|               14549|              7307|          9|
//+-----------------------+-----------------+----------------+------------+
