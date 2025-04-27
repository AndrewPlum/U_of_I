/*********************************************
 * Id: plum0598
 *
 * This program calculates and prints 2^n where n is the value passed in at argv[1].
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

// Prototypes

int two_to_the_n(int n);

// Main

int main(int argc, char *argv[]){
   
   // calculate 2^n and print answer
   
   printf("%d\n", two_to_the_n(atoi(argv[1])));

   // end of program
   
   return 0;
}

// function for taking 2^n for input n

int two_to_the_n(int n){
   if(n < 1){
      return 1;
   }
   return (two_to_the_n(n - 1) + two_to_the_n(n - 1));   
}