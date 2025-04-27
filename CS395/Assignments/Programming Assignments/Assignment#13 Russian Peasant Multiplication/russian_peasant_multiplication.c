/*********************************************
 * Id: plum0598
 *
 * This program performs Russian peasant multiplication 
 * finding the product of two integers by 
 * doubling one integer while halving the other until it reaches 1.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Prototypes

int russian_peasant_multiplication(int m, int n, int ongoing_total);

// Main

int main(int argc, char *argv[]){
   
   // return if wrong arguments
   
   if(argc != 3){
      printf("To use command line should be: %s <integer1> <integer2>\n", argv[0]);
      return 0;
   }

   // declare variables

   int m = atoi(argv[1]);
   int n = atoi(argv[2]);
   int answer;

   // calculate russian peasant multiplication answer

   answer = russian_peasant_multiplication(m, n, 0);

   // print answer

   printf("%20s\n%20d\n", "------", answer);

   // end of program

   return 0;
   
}

// Russian Peasant Multiplication: Finding the product by doubling one number while halving the other until 1

int russian_peasant_multiplication(int m, int n, int ongoing_total){

   printf("%6d %6d", m, n); // print two numbers being multiplied

   switch(m){
      case 1:
      printf("%7d\n", n);
      return n;
      default:
      switch(m % 2){
         case 1:
         printf("%7d\n", n);
         return n + russian_peasant_multiplication(m / 2, 2 * n, ongoing_total);
         case 0:
         printf("\n");
         return russian_peasant_multiplication(m / 2, 2 * n, ongoing_total);
      }
   }
   
   return ongoing_total;

}
