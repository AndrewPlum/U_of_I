/*********************************************
 * Id: plum0598
 *
 * This program finds the smallest difference between the values passed into argv[]
 *********************************************/

// Libraries and macros

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 256

// Prototypes
void lex(char *line, int start, int end, int length, char *type);
int tokenize(char *line, int length);

// Main
int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("Please specify input file.\n");
      printf("%s /y/shared/Engineering/cs-drbc/assignments/cs210/w01_in1.txt\n", argv[0]);
      return 1;
   }
   FILE *fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;
   
   fp = fopen(argv[1], "r");
   if (fp == NULL) {
      printf("Error: Could not open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   while ((read = getline(&line, &len, fp)) != -1) {
      tokenize(line, read);
   }

   fclose(fp);
   if (line) {
      free(line);
   }
   exit(EXIT_SUCCESS);
}

// Assign meaning to the tokens
void lex(char *line, int start, int end, int length, char *type) {
   char token[MAXTOKEN];
   while ((start < length) && (isspace(line[start]))) {
      start++;
   }
   if (start >= end) {
      return;
   }
   strncpy(token, &line[start], end - start);
   token[end - start] = '\0';
   printf("%s: %s\n", type, token);
}

// Break the string down into tokens
int tokenize(char *line, int length) {
   int start = 0;
   int end = 0;
   for (end = 0; end < length; end++) {
      if (isspace(line[end]) || line[end] == '"') {
         if (line[start] == '"') {
            int i = start + 1;
            while (line[i] != '"') {
               i++;
            }
            end = i;
            lex(line, start, end + 1, length, "String");
         }
         else {
            lex(line, start, end, length, "Token");
         }
         start = end + 1;
      }
   }
   return 0;
}

