/*********************************************
 * Id: plum0598
 *
 * This program reads out the actions to solve the
 * tower of Hanoi based on the amount of disks entered
 * This version has a restriction:
 * A can only move to B
 * B can only move to C
 * C can only move to A
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Prototypes

void tower_of_hanoi(int n, char start, char intermediate, char end);
//void tower_of_hanoi(int n, char start, char end, char intermediate);

// Main

int main(int argc, char *argv[]){
   int num_disks = atoi(argv[1]);
   //printf("Enter the number of disks: ");
   //scanf("%d", &n);
   if(num_disks <= 0){
      printf("Enter sufficient disks to move\n");
      return 0;
   }
   else
   {
      //printf("Sequence of moves:\n");
      tower_of_hanoi(num_disks, 'A', 'B', 'C'); // Standard 'A', 'B', and 'C' pegs
   }
   return 0;
}

// Tower of Hanoi function - recursive function which moves the disks

void tower_of_hanoi(int num_disks, char start, char intermediate, char end){
   if(num_disks == 1){
      printf("Move %c TO %c\n", start, intermediate);
      printf("Move %c TO %c\n", intermediate,end);
      return;
   }
   else if(num_disks == 2){
      printf("Move %c TO %c\n", start, intermediate);
      printf("Move %c TO %c\n", intermediate,end);
      printf("Move %c TO %c\n", start, intermediate);
      printf("Move %c TO %c\n", end,start);
      printf("Move %c TO %c\n", intermediate,end);
      printf("Move %c TO %c\n", start,intermediate);
      printf("Move %c TO %c\n", intermediate, end);
   }
   else
   {
      tower_of_hanoi(num_disks - 1,start,intermediate,end);
      printf("Move %c TO %c\n", start, intermediate); 
      tower_of_hanoi(num_disks - 2,end,start,intermediate);
      printf("Move %c TO %c\n",end,start); 
      tower_of_hanoi(num_disks - 2,intermediate,end,start);
      printf("Move %c TO %c\n",intermediate,end); 
      tower_of_hanoi(num_disks - 1,start,intermediate,end);
   }
}

/*
// Tower of Hanoi function - recursive function which moves the disks

void tower_of_hanoi(int n, char start, char intermediate, char end){
   if(n < 1){
      return;
   }
   tower_of_hanoi(n - 1, start, intermediate, end);
   printf("Move %c TO %c\n", start, intermediate);
   if(n > 1){
      tower_of_hanoi(n - 2, end, start, intermediate);
      printf("Move %c TO %c\n", end, start);
      tower_of_hanoi(n - 2, intermediate, end, start);
      return;
   }
   printf("Move %c TO %c\n", intermediate, end);
   tower_of_hanoi(n - 1, start, intermediate, end);
}
*/

/*
// Tower of Hanoi function - recursive function which moves the disks

void tower_of_hanoi(int n, char start, char intermediate, char end){
   if(n > 0){
      tower_of_hanoi(n - 1, start, end, intermediate); // Move from start to end
      printf("Move %c TO %c\n", start, end);
      tower_of_hanoi(n - 1, intermediate, start, end); // Move from intermediate to end
   }
}
*/

/*
// Tower of Hanoi function - recursive function which moves the disks

void tower_of_hanoi(int n, char start, char intermediate, char end){
   if(n > 0){
      tower_of_hanoi(n - 1, start, intermediate, end);
      printf("Move %c TO %c\n", start, intermediate);
      tower_of_hanoi(n - 1, end, intermediate, start);
      printf("Move %c TO %c\n", intermediate, end);
      tower_of_hanoi(n - 1, start, intermediate, end);
      return;
   }
}
*/