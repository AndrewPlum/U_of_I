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

int hoare_partition(int array[], int left, int right);
void quick_sort(int array[], int low, int high, int array_size);
void print_array(int array[], int low, int high, int array_size);
void swap(int *a, int *b);

// Main

int main(int argc, char *argv[]){
   
   // declare variables
   
   int i;
   int array_size = argc - 1;
   int array[array_size];
   
   // create array and fill with command line arguments
   
   for(i = 0; i < array_size; i++){
      array[i] = atoi(argv[i + 1]);
   }
   
   // quick sort and print array
   
   quick_sort(array, 0, array_size - 1, array_size);
   print_array(array, 0, array_size - 1, array_size);

   // end of program

   return 0;
}

// Hoare's Partition: 
// Divides array into 2 subarrays 
// Left side is less than the pivot
// And the right side is greater than the pivot

int hoare_partition(int array[], int low, int high){ 
   
   int pivot = array[low];
   int i = low, j = high + 1;
   
   while(true){
      do{ // find index where left ptr is greater than or equal to pivot
         i++;
      } while(array[i] < pivot);
      do{ // find index where right ptr is less than or equal to pivot
         j--;
      } while(array[j] > pivot);

      swap(array[i], array[j]);
      
      if(i >= j){
         // if ptrs touch, that means you covered the whole list, 
         // and everything to left is less than and everything to right is greater than
         break;
      }
   }

   swap(array[i], array[j]);

   swap(array[j], array[low]);

   return j;
}

// Quick sort sorting algorithm

void quick_sort(int array[], int low, int high, int array_size) { 
   if(low < high){
      
      int split = hoare_partition(array, low, high); 

      // separately sort elements before partition and after partition 
      
      quick_sort(array, low, split - 1, array_size);
      quick_sort(array, split + 1, high, array_size);
      
      print_array(array, low, high, array_size);
   } 
} 

// Print the passed array

void print_array(int array[], int low, int high, int array_size){
   
   int i;
   
   for(i = 0; i < array_size; i++){
      if(i == low){
         printf("[%d ", array[i]);
      }
      else if(i == high){
         printf("%d]  ", array[i]);
      }
      else{
         printf("%d ", array[i]);
      }
   }
   
   printf("\n");
}

// Swaps the address of two integers

void swap(int *a, int *b){
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}