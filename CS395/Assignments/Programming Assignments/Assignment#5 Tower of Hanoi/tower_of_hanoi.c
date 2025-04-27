/*********************************************
 * Id: plum0598
 *
 * This program reads out the actions to solve the
 * tower of Hanoi based on the amount of disks entered
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Prototypes

void tower_of_hanoi(int n, char start, char intermediate, char end);

// Main

int main(int argc, char *argv[]){
   
   int num_disks = atoi(argv[1]);
   //printf("Enter the number of disks: ");
   //scanf("%d", &num_disks);

   tower_of_hanoi(num_disks, 'A', 'B', 'C');

   return 0;
}

// Tower of Hanoi function

void tower_of_hanoi(int n, char start, char intermediate, char end){
   if(n == 1){
      printf("Move %c TO %c\n", start, end);
      return;
   }
   tower_of_hanoi(n - 1, start, end, intermediate);
   printf("Move %c TO %c\n", start, end);
   tower_of_hanoi(n - 1, intermediate, start, end);
}
