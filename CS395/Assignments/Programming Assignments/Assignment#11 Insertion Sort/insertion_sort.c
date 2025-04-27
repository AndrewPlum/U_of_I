/*********************************************
 * Id: plum0598
 *
 * This program sorts an array of integers 
 * passed as arguments using an insertion sort
 * algorithm. 
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

// Prototypes

void insertion_sort(int array[], int size);
void print_array(int array[], int size, int sorted_index);

// Main

int main(int argc, char *argv[]){
   
   // check for input
   
   if(argc < 3){
      printf("Enter integer elements of an array separated by spaces.\n");
      return 0;
   }

   // declare variables

   int array[argc - 1];
   int i;
   
   // create array and fill with command line arguments
   
   for(i = 1; i < argc; i++){
      array[i - 1] = atoi(argv[i]);
   }

   // insertion sort

   insertion_sort(array, argc - 1);

   // end of program 

   return 0;
}

// Sorts an array of integers using insertion sort

void insertion_sort(int array[], int size){
   
   // declare indexes
   
   int i, j;
   
   // print initial array
   
   print_array(array, size, 0);
   
   // print each iteration of the sort
   
   for(i = 1; i < size; i++){
      int v = array[i];
      j = i - 1;
      while(j >= 0 && array[j] > v){
         array[j + 1] = array[j];
         j = j - 1;
      }
      array[j + 1] = v;
      print_array(array, size, i);
   }
}

// Prints the elements of an array

void print_array(int array[], int size, int sorted_index){
   int i;
   for(i = 0; i < size; i++){
      printf("%d ", array[i]);
      if(i == sorted_index){
         printf("| ");
      }
   }
   printf("\n");
}
