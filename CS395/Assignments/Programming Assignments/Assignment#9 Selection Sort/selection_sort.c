/*********************************************
 * Id: plum0598
 *
 * This program sorts an array of integers 
 * passed as arguments using a selection sort
 * algorithm. 
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Prototypes

void selection_sort(int array[], int size);
void swap(int *a, int *b);
void print_array(int array[], int size);

// Main

int main(int argc, char *argv[]){
   
   // check for input
   
   if(argc <= 2){
      printf("Enter array of integers as arguments through the command line separated by spaces.\n");
      printf("You need at least integers in the array.\n");
      return 0;
   }

   // variable declarations
   
   int array[argc - 1];
   int i;
   
   // create array and fill with elements from argv
   
   for(i = 1; i < argc; i++){
      array[i - 1] = atoi(argv[i]);
   }

   // selection sort

   selection_sort(array, argc - 1);

   // end of program

   return 0;
}

// Sorts an array of integers using selection sort.

void selection_sort(int array[], int size){
   print_array(array, size);
   int i, j;
   for(i = 0; i < size - 1; i++){
      int minIndex = i;
      for(j = i + 1; j < size; j++){
         if(array[j] < array[minIndex]){
            minIndex = j;
         }
      }
      swap(&array[minIndex], &array[i]);
      print_array(array, size);
   }
}

// Swaps the position of two integer elements.

void swap(int *a, int *b){
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

// Prints the elements of a passed in array.

void print_array(int array[], int size){
   int i;
   for(i = 0; i < size; i++){
      printf("%d ", array[i]);
   }
   printf("\n");
}
