/*********************************************
 * Id: plum0598
 *
 * This program performs Russian peasant multiplication 
 * finding the product of two integers by 
 * doubling one integer while halving the other until it reaches 1
 *********************************************/

// Prototypes

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int russianPeasant(int m, int n, int total);

// Main

int main(int argc, char *argv[])
{
   int m = atoi(argv[1]);
   int n = atoi(argv[2]);
   int product = russianPeasant(m, n, 0);

   printf("%20s\n%20d\n", "------", product);

   return 0;
}

// Performs Russian peasant multiplication, displaying the steps

int russianPeasant(int m, int n, int total)
{
   printf("%6d %6d", m, n);

   if (m == 1)
   {
      printf("%7d\n", n);
      return n;
   }

   if (m % 2 == 1)
   {
      printf("%7d\n", n);
      return n + russianPeasant(m / 2, 2 * n, total);
   }
   else if (m % 2 == 0)
   {
      printf("\n");
      return russianPeasant(m / 2, 2 * n, total);
   }

   return total;
}
