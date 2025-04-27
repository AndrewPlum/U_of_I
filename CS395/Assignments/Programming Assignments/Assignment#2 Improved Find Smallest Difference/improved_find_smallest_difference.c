/*********************************************
 * Id: plum0598
 *
 * This program finds the smallest difference between the values passed into argv[].
 * It improves upon the last version.
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

// Prototypes

void bubble_sort(int array[], int maxsize);
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
   
   // bubble sort
   
   bubble_sort(values, argc - 1);
   
   // call min_distance() and print value returned
   
   int dmin = min_distance(argc - 1, values);
   printf("%d\n", dmin);
   
   // end of program 
   
   return 0;
}

// bubble_sort() for presort

void bubble_sort(int array[], int maxsize){
   int count = 0; // the number of times the counrter had to swap two numbers in the last sort
   int temp = 0; // temporary place holder
   int i = 0;
   do{
      count = 0;
      for(i = 0; i < (maxsize - 1); i++){ // i < (maxsize - 1) because I don't want the if conditions check the outside
         if(array[i] > array[i + 1]){
            temp = array[i + 1];
            array[i + 1] = array[i];
            array[i] = temp;
            count++;
         }
      }
   }while(count != 0);
}

// min_distance() finds the smallest difference between two value


int min_distance(int size, int values[]){
   int dmin = 2147483647;
   int i;
   for(i = 0; i < size - 1; i++){
      if((abs(values[i] - values[i + 1]) < dmin)){
         dmin = abs(values[i] - values[i + 1]);
      }
   }
   return dmin;
}

// min_distance() finds the smallest difference between two value

/*
int min_distance(int size, int values[]){
   int dmin = 2147483647;
   int i;
   int j;
   for(i = 0; i < size - 1; i++){
      for(j = i + 1; j < size - 1; j++){
         if((i != j) && (abs(values[i] - values[j]) < dmin)){
            dmin = abs(values[i] - values[j]);
         }
      }
   }
   return dmin;
}
*/