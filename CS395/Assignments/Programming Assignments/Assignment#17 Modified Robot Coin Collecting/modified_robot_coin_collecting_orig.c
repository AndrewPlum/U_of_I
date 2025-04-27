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

int max(int a, int b);
int robotCoinCollection(int rowSize, int colSize, int map[rowSize][colSize]);
void printTable(int rowSize, int colSize, int map[rowSize][colSize]);

// Main

int main(int argc, char *argv[])
{
   if (argc < 4)
   {
      printf("Insufficient arguments.\n");
      return 0;
   }

   int rowSize = atoi(argv[1]);
   int colSize = atoi(argv[2]);
   int map[rowSize][colSize];

   // input table
   
   int i, j;
   for (i = 0; i < rowSize; i++)
   {
      for (j = 0; j < colSize; j++)
      {
         if (strcmp(argv[i * colSize + j + 3], "X") == 0)
         {
            map[i][j] = -1;
         }
         else
         {
            map[i][j] = atoi(argv[i * colSize + j + 3]);
         }
      }
   }

   printf("Board Inputed:\n");
   printTable(rowSize, colSize, map);

   // coin collection table
   
   int optimalPath = robotCoinCollection(rowSize, colSize, map);
   printf("The optimal path with this board is: %d\n", optimalPath);

   return 0;
}

// Returns the max of two ints

int max(int a, int b)
{
   return a > b ? a : b;
}

// Creates and prints the coin collection table

int robotCoinCollection(int rowSize, int colSize, int map[rowSize][colSize])
{
   int navTable[rowSize][colSize];
   navTable[0][0] = map[0][0];

   int i = 1, j = 1;

   // do rows
   
   while (i < rowSize && map[i][0] != -1)
   {
      navTable[i][0] = navTable[i - 1][0] + map[i][0];
      i = i + 1;
   }

   // a wall has been found
   
   while (i < rowSize)
   {
      navTable[i][0] = -10;
      i++;
   }

   // do columns
   
   while (j < colSize && map[0][j] != -1)
   {
      navTable[0][j] = navTable[0][j - 1] + map[0][j];
      j = j + 1;
   }

   // a wall has been found
   
   while (j < colSize)
   {
      navTable[0][j] = -10;
      j++;
   }

   // navigate map
   
   for (i = 1; i < rowSize; i++)
   {
      for (j = 1; j < colSize; j++)
      {
         if (map[i][j] != -1)
         {
            navTable[i][j] = max(navTable[i - 1][j], navTable[i][j - 1]) + map[i][j];
         }
         
         // a wall has been found
         
         else
         {
            navTable[i][j] = -10;
         }
      }
   }

   // reset negatives
   
   for (i = 0; i < rowSize; i++)
   {
      for (j = 0; j < colSize; j++)
      {
         if (navTable[i][j] < 0)
         {
            navTable[i][j] = 0;
         }
      }
   }

   // display coin collecting table
   
   printf("Coin Collecting Table:\n");
   printTable(rowSize, colSize, navTable);

   return navTable[rowSize - 1][colSize - 1];
}

// Displays a passed table

void printTable(int rowSize, int colSize, int map[rowSize][colSize])
{
   int i, j;
   for (i = 0; i < rowSize; i++)
   {
      for (j = 0; j < colSize; j++)
      {
         if (map[i][j] == -1)
         {
            printf("%c\t", 'X');
         }
         else
         {
            printf("%d\t", map[i][j]);
         }
      }
      printf("\n");
   }
   printf("\n");
}