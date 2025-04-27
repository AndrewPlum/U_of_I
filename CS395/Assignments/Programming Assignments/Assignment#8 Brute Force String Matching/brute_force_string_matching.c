/*********************************************
 * Id: plum0598
 *
 * This program returns all the indexes of an 
 * inputted text string where an inputted 
 * pattern string matches. argv[1] is the 
 * pattern string and argv[2] is the text
 * string. It might be missing an edge case.
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Main

int main(int argc, char *argv[]){
   
   // check for right input
   
   if(argc != 3){
      printf("Enter the pattern to match as argv[1] and then a string for argv[2].\n");
      return 0;
   }

   // declarations

   int i;
   int j;
   int count = 0;
   int m = strlen(argv[1]); // pattern length
   int n = strlen(argv[2]); // text length
   int positions[200];

   // find matches

   printf("Matches found at locations: ");

   for(i = 0; i < n - m + 1; i++){
      j = 0;
      while(j < m && argv[1][j] == argv[2][i + j]){
         j++;
      }
      if(j == m){
         positions[count] = i;
         positions[count + 1] = '\0';
         count++;
      }
   }
   
   for(i = 0; i < count; i++){
      printf("%d", positions[i]);
      if(i < count - 1){
         printf(" ");
      }
   }
   printf("\n");

   // end of program 

   return 0;
}
