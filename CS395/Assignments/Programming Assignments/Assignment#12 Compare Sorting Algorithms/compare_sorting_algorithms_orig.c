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

// Prototypes

void swap(int *a, int *b);
void randomizeArray(int array[], int size);
void insertionSort(int array[], int size);
void selectionSort(int array[], int size);
void quicksort(int array[], int left, int right);
int hoarePartition(int array[], int left, int right);

// Main

int main(int argc, char *argv[])
{
   struct timeval start, stop;
   srand(time(NULL));
   int runtimes[9];
   int currRuntime = 0;

   int i;
   for (i = 3; i <= 5; i++)
   {
      long size = (int)pow(10, i);
      printf("%ld\n", size);
      int array[size];

      randomizeArray(array, size);
      gettimeofday(&start, NULL);
      selectionSort(array, size);
      gettimeofday(&stop, NULL);
      runtimes[currRuntime] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
      currRuntime++;

      randomizeArray(array, size);
      gettimeofday(&start, NULL);
      insertionSort(array, size);
      gettimeofday(&stop, NULL);
      runtimes[currRuntime] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
      currRuntime++;

      randomizeArray(array, size);
      gettimeofday(&start, NULL);
      quicksort(array, 0, size - 1);
      gettimeofday(&stop, NULL);
      runtimes[currRuntime] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
      currRuntime++;
   }

   printf("//+-----------------------+-----------------+----------------+------------+\n");
   printf("//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |\n");
   printf("//+-----------------------+-----------------+----------------+------------+\n");
   printf("//|                   1000|               %d|              %d|          %d|\n", runtimes[0], runtimes[1], runtimes[2]);
   printf("//|                  10000|               %d|              %d|          %d|\n", runtimes[3], runtimes[4], runtimes[5]);
   printf("//|                 100000|               %d|              %d|          %d|\n", runtimes[6], runtimes[7], runtimes[8]);
   printf("//+-----------------------+-----------------+----------------+------------+\n");
   return 0;
}

// Swaps two elements of an array with each other

void swap(int *a, int *b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

// Randomizes the elements of an array

void randomizeArray(int array[], int size)
{
   int i;
   for (i = 0; i < size; i++)
   {
      array[i] = rand() % 10;
   }
}

// Sorts an array of integers using insertion sort

void insertionSort(int array[], int size)
{
   int i, j;
   for (i = 1; i < size; i++)
   {
      int v = array[i];
      j = i - 1;
      while (j >= 0 && array[j] > v)
      {
         array[j + 1] = array[j];
         j = j - 1;
      }
      array[j + 1] = v;
   }
}

// Sorts an array of integers using selection sort

void selectionSort(int array[], int size)
{
   int i, j;
   for (i = 0; i < size - 1; i++)
   {
      int minIndex = i;
      for (j = i + 1; j < size; j++)
      {
         if (array[j] < array[minIndex])
         {
            minIndex = j;
         }
      }

      swap(&array[minIndex], &array[i]);
   }
}

// Sorts an array using the quicksort algorithm

void quicksort(int array[], int left, int right)
{
   int split;
   if (left < right)
   {
      split = hoarePartition(array, left, right);
      quicksort(array, left, split - 1);
      quicksort(array, split + 1, right);
   }
}

// Partitions an array using Hoare's algorithm

int hoarePartition(int array[], int left, int right)
{
   int i, j, initialLeft;
   initialLeft = array[left];
   i = left;
   j = right + 1;

   do
   {
      do
      {
         i++;
      } while (array[i] < initialLeft);
      do
      {
         j--;
      } while (array[j] > initialLeft);

      swap(&array[j], &array[i]);
   } while (i < j);

   swap(&array[j], &array[i]);
   swap(&array[j], &array[left]);

   return j;
}

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                   1000|                1|               0|           0|
//|                  10000|              121|              61|           1|
//|                 100000|            11917|            5890|           7|
//+-----------------------+-----------------+----------------+------------+

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                   1000|                1|               0|           0|
//|                  10000|              121|              59|           1|
//|                 100000|            12273|            5965|           7|
//+-----------------------+-----------------+----------------+------------+

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                   1000|                1|               0|           0|
//|                  10000|              122|              58|           2|
//|                 100000|            12632|            6217|           9|
//+-----------------------+-----------------+----------------+------------+