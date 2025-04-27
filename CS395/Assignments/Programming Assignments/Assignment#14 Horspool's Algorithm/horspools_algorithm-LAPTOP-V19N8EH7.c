/*********************************************
 * Id: plum0598
 *
 * This program uses horspool's algorithm for pattern matching 
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

// Function Prototypes

void horspool_matching(char needle[], char haystack[], int needle_size, int haystack_size);
int *generate_shift_table(char needle[], int size);
void print_shift_table(int table[]);
void print_matches(int matches[], int match_count);

// Main Function

int main(int argc, char *argv[]){
   horspool_matching(argv[1], argv[2], strlen(argv[1]), strlen(argv[2]));
   return 0;
}

// Function to Perform Horspool Matching

void horspool_matching(char needle[], char haystack[], int needle_size, int haystack_size){
   int matches[haystack_size];
   int match_count = 0;
   int *shift_table = generate_shift_table(needle, needle_size);
   int x = 0;
   int y = 0;

   printf("%s\n", haystack);

   int i = needle_size - 1;
   while (i <= haystack_size - 1){
      x = 0;
      while ((x <= needle_size - 1) && (needle[needle_size - 1 - x] == haystack[i - x])){
         x++;
      }
      switch (x != needle_size){
         case 1:
         printf("%*s%s\n", i - needle_size + 1, "", needle);
         break;
         case 0:
         match_count++;
         matches[y] = i;
         y++;
         printf("%*s%s---found\n", i - needle_size + 1, "", needle);
         break;
      }
      i = i + shift_table[(int)haystack[i]];
   }

   printf("Matches found at locations:");
   print_matches(matches, match_count);

   free(shift_table);
}

// Function to Generate and Print the Horspool Shift Table

int *generate_shift_table(char needle[], int size){
   int *table = malloc(sizeof(int) * MAX_ALPHABET);
   
   int i;
   for (i = 0; i <= MAX_ALPHABET - 1; i++){
      table[i] = size;
   }

   int j;
   for (j = 0; j <= size - 2; j++){
      table[(int)needle[j]] = size - 1 - j;
   }

   print_shift_table(table);
   return table;
}

// Function to Print the Horspool Shift Table

void print_shift_table(int table[]){
   int start;
   int i;
   for (start = MIN_WRITEABLE; start < MAX_ALPHABET; start += TABLE_ROW_LENGTH){
      for (i = start; i < start + TABLE_ROW_LENGTH; i++){
         printf("%c\t", i);
      }
      printf("\n");

      for (i = start; i < start + TABLE_ROW_LENGTH; i++){
         printf("%d\t", table[i]);
      }
      printf("\n\n");
   }
}

// Function to Print Matches

void print_matches(int matches[], int match_count){
   for (int i = 0; i < match_count; i++){
      printf(" %d", matches[i] - 2);
   }
   printf("\n");
}
