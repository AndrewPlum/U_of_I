/*********************************************
 * Id: plum0598
 *
 * This program reads out the actions to solve the
 * tower of Hanoi based on the amount of disks entered
 * This version has a restriction:
 * Rod B must be involved in every move (TO and FROM rod B)
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

// Tower of Hanoi function

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
