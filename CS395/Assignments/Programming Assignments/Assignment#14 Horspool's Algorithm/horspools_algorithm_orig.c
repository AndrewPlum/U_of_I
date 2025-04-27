/*********************************************
 * Id: plum0598
 *
 * This program sorts an array of integers 
 * passed as arguments using an insertion sort
 * algorithm. 
 *********************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

// Prototypes

void printShiftTable(int table[]);
void horspoolMatching(char needle[], char haystack[], int needleSize, int haystackSize);
int *shiftTable(char needle[], int size);

// Main

int main(int argc, char *argv[])
{
   horspoolMatching(argv[1], argv[2], strlen(argv[1]), strlen(argv[2]));
   return 0;
}

// Prints the Horspool shift table

void printShiftTable(int table[])
{
   int i, start;
   for (start = MIN_WRITEABLE; start < MAX_ALPHABET; start += TABLE_ROW_LENGTH)
   {
      for (i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for (i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");
   }
}

// Performs Horspool matching for the given needle and haystack

void horspoolMatching(char needle[], char haystack[], int needleSize, int haystackSize)
{
   int matches[haystackSize];
   int matchCount = 0;
   int k = 0;
   int j = 0;
   int n = haystackSize;
   int m = needleSize;
   int *p = shiftTable(needle, needleSize);
   int i = m - 1;

   printf("%s\n", haystack);

   while (i <= n - 1)
   {
      k = 0;

      while ((k <= m - 1) && (needle[m - 1 - k] == haystack[i - k]))
      {
         k++;
      }

      if (k != m)
      {
         printf("%*s%s\n", i - m + 1, "", needle);
      }

      if (k == m)
      {
         matchCount++;
         matches[j] = i;
         j++;
         printf("%*s%s---found\n", i - m + 1, "", needle);
      }

      i = i + p[(int)haystack[i]];
   }

   printf("Matches found at locations:");

   for (i = 0; i < matchCount; i++)
   {
      printf(" %d", matches[i] - 2);
   }

   printf("\n");
}

// Generates and prints the Horspool shift table

int *shiftTable(char needle[], int size)
{
   int *table = malloc(sizeof(int) * MAX_ALPHABET);
   int i, j;
   for (i = 0; i <= MAX_ALPHABET - 1; i++)
   {
      table[i] = size;
   }
   for (j = 0; j <= size - 2; j++)
   {
      table[(int)needle[j]] = size - 1 - j;
   }
   printShiftTable(table);
   return table;
}