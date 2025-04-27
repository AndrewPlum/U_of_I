/*********************************************
 * Id: plum0598
 *
 * This program tokenizes and lexes a file
 *********************************************/

// Libraries and macros

#define MAXTOKEN 256

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Prototypes

void lex(char *line, int start, int end, int length, char type[]); // Assign meaning to tokens
int tokenize(char *line, int length); // Break the string down into tokens

// Main

int main(int argc, char *argv[])
{
   if(argc<2)
   {
      printf("Please specify input file.\n");
      printf("%s /y/shared/Engineering/cs-drbc/assignments/cs210/w01_in1.txt\n", argv[0]);
      return 1;
   }
   FILE * fp;
   char * line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen(argv[1], "r");
   if (fp == NULL){
      printf("Error: Could not open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   while ((read = getline(&line, &len, fp)) != -1) {
      tokenize(line, read); // read is size of line
   }

   fclose(fp);
   if (line) {
      free(line);
   }
   exit(EXIT_SUCCESS);
}

// Assign meaning to the tokens

void lex(char *line, int start, int end, int length, char *type){
   int i;
   int len;
   int start_copy;
   char token[MAXTOKEN];
   while((start < length) && (isspace(line[start]))){ // strip leading spaces
      start++;
   }
   if(start >= end){
      return;
   }
   //strncpy(token, &line[start], end - start);
   ///*
   i = 0;
   len = end - start;
   start_copy = start;
   while(i < len){
      token[i] = line[start_copy];
      start_copy++;
      i++;
   }
   //*/
   token[end-start] = '\0';
   printf("%s: %s\n", type, token);
}

// Break the string down into tokens - attempt 2

int tokenize(char *line, int size){
   int start = 0;
   int end = 0;
   for(end = 0; end < size; end++){
      if(line[end] == '"'){
         lex(line, start, end, size, "Token"); // this affects the submission if "String" is type confusing
         start = end;
         end++;
         while(end < size && line[end] != '"'){
            end++;
         }
         end++;
         lex(line, start, end, size, "String");
         start = end;
         end--;
      }
      else if(isspace(line[end])){
         lex(line, start, end, size, "Token");
         start = end;
      }
   }
   return 0;
}

