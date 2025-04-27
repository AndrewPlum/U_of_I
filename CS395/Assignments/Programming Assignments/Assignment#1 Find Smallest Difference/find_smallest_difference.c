/*********************************************
 * Id: plum0598
 *
 * This program finds the smallest difference between the values passed into argv[]
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

// Prototypes

int min_distance(int size, int values[]);

// Main

int main(int argc, char *argv[]){
   
   // variable delcarations
   
   int i;
   int values[argc - 1];
   
   // check argc
   
   if(argc < 2){
      printf("%s\n", argv[0]);
   }
   
   // assign values converted integer values from argv

   for(i = 0; i < argc - 1; i++){
      values[i] = atoi(argv[i + 1]);
   }
   
   // call min_distance() and print value returned
   
   int dmin = min_distance(argc - 1, values);
   printf("%d\n", dmin);
   
   // end of program 
   
   return 0;
}

// min_distance() finds the smallest difference between two value

int min_distance(int size, int values[]){
   int dmin = 2147483647;
   int i;
   int j;
   for(i = 0; i < size - 1; i++){
      for(j = 0; j < size - 1; j++){
         if((i != j) && (abs(values[i] - values[j]) < dmin)){
            dmin = abs(values[i] - values[j]);
         }
      }
   }
   return dmin;
}
