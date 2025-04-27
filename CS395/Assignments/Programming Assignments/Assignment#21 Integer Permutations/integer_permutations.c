/*********************************************
 * Id: plum0598
 *
 * This program calculates and prints all  
 * permutations of characters of a string of numbers
 * entered in as command line arguments.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes

void print_permutations(int n);
void swap(char *a, char *b);
void generate_integer_array(char *integers, int n);
void swap_and_permute(char *integers, int start, int end);

// Main

int main(int argc, char *argv[]){
   
   switch(argc){
      case 2: // if 2
      print_permutations(atoi(argv[1]));
      break;
      default: // else
      printf("Enter the number to display permutations for.\n");
   }

   return 0;

}

// Print permutations 

void print_permutations(int n){
   char integers[n];
   generate_integer_array(integers, n);
   swap_and_permute(integers, 0, n - 1);
}

// Generate integer array

void generate_integer_array(char *integers, int n){
   int i;
   for(i = 1; i <= n; i++){
      integers[i - 1] = i + '0';
   }
}

// Perform swaps and permutations

void swap_and_permute(char *integers, int start, int end){
   if(start == end){
      printf("%s\n", integers);
   } 
   else
   {
      for(int i = start; i <= end; i++){
         swap(&integers[start], &integers[i]);
         swap_and_permute(integers, start + 1, end);
         swap(&integers[start], &integers[i]);
      }
   }
}

// Swap two character addresses

void swap(char *x, char *y){
   char temp = *x;
   *x = *y;
   *y = temp;
}