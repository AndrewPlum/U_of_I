/*********************************************
 * Id: plum0598
 *
 * This program finds the smallest difference between the values passed into argv[]
 *********************************************/

// Libraries and macros

#define MAXTOKEN 256

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Prototypes

//void lex(char *line, int start, int end, int length, int shift, char type[]); // Assign meaning to tokens
void lex(char *line, int start, int end, int length, char type[]); // Assign meaning to tokens - original
// need to add 1 as a parameter to lex - need to figure out indices


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

///*

// Assign meaning to the tokens - attempt 2

void lex(char *line, int start, int end, int length, char *type){
   int i;
   int len;
   int start_copy;
   char token[MAXTOKEN];
   while((start < length) && (isspace(line[start]))){ // strip leading spaces
      start++;
   }
   if(start > end){
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
   /*
   if((strcmp(type, "String") == 0)){
      printf("%s: %s\n", type, token);
   }
   else if((strcmp(type, "Token") == 0)){ // "\0 - FF ",\0 - FT  ,\0 - TF ,ls\0 - TT
      if((token[0] != '"') || (token[1] != '\0')){
         if((token[0] == '"') && (token[1] != '\0')){
            i = 0;
            while(token[i + 1] != '\0'){
               token[i] = token[i + 1];
               i++;   
            }
            token[i] = '\0';
            printf("%s: %s\n", type, token);
         }
         else{
            printf("%s: %s\n", type, token);
         }
      }
      else{
         if((token[0] == '"') && (token[1] == '\0')){
            return;
         }
         printf("%s: %s\n", type, token);
      }
   }
   //*/
   printf("%s: %s\n", type, token);
}

//*/

///*

// Break the string down into tokens - attempt 2

int tokenize(char *line, int size){
   int start = 0;
   int end = 0;
   //int is_a_string = 0;
   //printf("%s/n", line);
   /*
   for(end = 0; end < size; end++){
      if(line[end] == '"'){
         is_a_string++;
      } 
      else if(line[end] != '"'){
         is_a_string--;
      }
   }
   //*/
   ///*
   for(end = 0; end < size; end++){
      if(line[end] == '"'){
         //lex(line, start, end, size, "Token"); // need to add 1 as a parameter to lex
         //is_a_string++;
         start = end;
         //printf("THIS CHARCTER: %c %d\n", line[end], end);
         end++;
         //printf("THIS CHARCTER: %c %d\n", line[end], end);
         while(end < size && line[end] != '"'){ //&& line[end + 1] != '"'){
            end++;
            //printf("THIS CHARCTER: %c %d\n", line[end], end);
         }
         /*
         if(line[end + 1] != '"'){
            //printf("THIS CHARCTER: %c\n", line[end]);
            end++;
            //printf("NEXT CHARCTER: %c\n", line[end]);
         }
         //*/
         //end++;
         //printf("NEXT CHARCTER: %c %d\n", line[end + 1], end);
         lex(line, start, end + 1, size, "String");
         //end++;
         start = end;
         //start++;
      }
      else if(isspace(line[end])){
         lex(line, start, end, size, "Token");
         start = end;
      }
   }
   //*/
   return 0;
}

//*/