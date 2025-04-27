/*********************************************
 * Id: plum0598
 *
 * This program sorts an array of integers 
 * passed as arguments using an insertion sort
 * algorithm. 
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes

void printPermutations(int n);
void swap(char *a, char *b);
void permute(char *integers, int start, int end);

// Main

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Enter the number to display permutations for.\n");
      return 0;
   }

   printPermutations(atoi(argv[1]));

   return 0;
}

// Displays every permutation of numbers <= an integer n

void printPermutations(int n)
{
   char integers[n];
   int i;
   for (i = 1; i < n + 1; i++)
   {
      integers[i - 1] = i + '0';
   }

   permute(integers, 0, n - 1);
}

// Swaps two elements

void swap(char *a, char *b)
{
   char temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

// Recursive function to print every permutation of an integer

void permute(char *integers, int start, int end)
{
   if (start == end)
   {
      printf("%s\n", integers);
   }
   else
   {
      int i;
      for (i = start; i <= end; i++)
      {
         swap((integers + start), (integers + i));
         permute(integers, start + 1, end);
         swap((integers + start), (integers + i));
      }
   }
}