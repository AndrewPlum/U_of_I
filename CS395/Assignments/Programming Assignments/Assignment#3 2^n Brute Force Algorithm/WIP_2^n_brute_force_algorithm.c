/*********************************************
 * Id: plum0598
 *
 * This program finds the smallest difference between the values passed into argv[].
 * It improves upon the last version.
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

// Prototypes

void two_to_the_n(int size; int values[]);

// Main

int main(int argc, char *argv[]){
   
   // variable declarations
   
   int n;
   
   int i;
   int values[argc - 1];
   
   // enter input
   
   //printf("Enter a nonnegative integer: ");
   //scanf("%d", &n);
   
   // calculate 2^n and print answer
   
   
   
   // assign values converted integer values from argv

   for(i = 0; i < argc - 1; i++){
      values[i] = atoi(argv[i + 1]);
   }
   
   
   //printf("%d", two_to_the_n(n));
   two_to_the_n(argc - 1, values[]);
   
   
   
   
   // end of program
   
   return 0;
}

// function for taking 2^n for input n

void two_to_the_n(int size; int values[]){
   int i;
   for(i = 0; i < size; i++){
      if(values[i] < 1){
         values[i] = 1;
      }
      values[i] = (two_to_the_n(n - 1) + two_to_the_n(n - 1));   
   }
}

