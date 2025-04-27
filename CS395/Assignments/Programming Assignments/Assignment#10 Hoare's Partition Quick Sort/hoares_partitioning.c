/*********************************************
 * Id: plum0598
 *
 * This program performs Hoare's partition on 
 * an array that is passed in as arguments 
 * through the command line.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Prototypes

int hoares_partition(int array[], int left, int right);
void quick_sort(int array[], int low, int high, int array_length);
void print_array(int array[], int low, int high, int array_length);
void swap(int *x, int *y);

// Main

int main(int argc, char *argv[]){

   // declare variables

   int array_length = argc - 1;
   int array[array_length];
   int i;
   
   // fill array with command line arguments

   for(i = 0; i < array_length; i++){ 
      array[i] = atoi(argv[i + 1]);
   }

   // quick sort and print array

   quick_sort(array, 0, array_length - 1, array_length);
   print_array(array, 0, array_length - 1, array_length);

   // end of program

   return 0;
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

      // print array

      print_array(array, low, high, array_length);
      
   }
}

// Print the passed array

void print_array(int array[], int low, int high, int array_length){

   int i;

   for(i = 0; i < array_length; i++){
      if(i == low){
         printf("[%d ", array[i]);
      }
      else if (i == high){
         printf("%d]  ", array[i]);
      }
      else{
         printf("%d ", array[i]);
      }
   }

   printf("\n");
}

// Swap function swaps addresses of two integers

void swap(int *x, int *y){
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}
