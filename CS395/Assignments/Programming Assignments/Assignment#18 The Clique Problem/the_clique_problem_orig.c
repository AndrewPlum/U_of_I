/*********************************************
 * Id: plum0598
 *
 * This program sorts an array of integers 
 * passed as arguments using an insertion sort
 * algorithm. 
 *********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Prototypes

int findClique(int size, int matrix[][size], int row, int clique[], int total);
int calculateMaxClique(int size, int matrix[][size]);

// Main

int main(int argc, char *argv[])
{
   int size = atoi(argv[1]);
   int matrix[size][size];
   int i, j, k, count;

   // Read in matrix
   j = 0;
   for (k = 0; k < size - 1; k++)
   {
      count = 0;
      for (i = k + 1; i < size; i++)
      {
         matrix[k][i] = atoi(argv[2 + j + count]);
         count++;
      }
      j += count;
   }

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < i + 1; j++)
      {
         matrix[i][j] = 0;
      }
   }

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size; j++)
      {
         matrix[j][i] = matrix[i][j];
      }
   }

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size; j++)
      {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }

   int result = calculateMaxClique(size, matrix);

   for (i = size; i > 0; i--)
   {
      if (result < i)
      {
         printf("No clique found of size %d\n", i);
      }
      if (result == i)
      {
         printf("Clique found of size %d\n", i);
      }
   }

   return 0;
}

// Finds the clique from an adjacency matrix

int findClique(int size, int matrix[][size], int row, int clique[], int total)
{
   int i;
   int count = 0;

   for (i = 0; i < size; i++)
   {
      if (clique[i] == 1 && matrix[row][i] == 1)
      {
         count++;
      }
   }

   if (count == total)
   {
      return 1;
   }
   return 0;
}

// Calculates and returns the max clique

int calculateMaxClique(int size, int matrix[][size])
{
   int i, j, k, l, count, maxClique;
   int clique[size];

   maxClique = 2;
   count = 1;
   for (l = 0; l < size; l++)
   {
      for (j = 0; j < size; j++)
      {
         clique[j] = 0;
      }

      clique[l] = 1;
      for (i = 0; i < size; i++)
      {
         k = 0;

         if (matrix[l][i] == 1)
         {
            k = findClique(size, matrix, i, clique, count);
         }

         if (k == 1)
         {
            count++;
            clique[i] = 1;
         }
      }

      if (count > maxClique)
      {
         maxClique = count;
      }
      count = 1;
   }

   return maxClique;
}
