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

int is_keyword(char *token);
int is_operator_1(char *line, int position);
int is_operator_2(char *line, int position);
int is_numeric(char *token);
int is_identifier(char *token);
void lex(char *line, int start, int end, int length, char type[], int in_comment); // Assign meaning to tokens
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

// Returns 1 if operator in set 1

int is_operator_1(char *line, int position){
   const int size = 20;
   char *operator[] = {"<", ">", "(", ")", "+", "-", "*", "/", "|", "&", 
      ";", ",", ":", "=", "$", "@", "{", "}", "[", "]"};
   int i;
   for(i = 0; i < size; i++){
      if(line[position] == operator[i][0]){
         return 1;
      }
   }
   return 0;
}

// Returns 1 if operator in set 2

int is_operator_2(char *line, int position){
   const int size = 12;
   char *operator[] = {":=", "..", "<<", ">>", "<>", "<=", ">=", "**", "!=", "=>", "{:", "}:"};
   int i;
   for(i = 0; i < size; i++){
      if(line[position] == operator[i][0] && line[position + 1] == operator[i][1]){
         return 1;
      }
   }
   return 0;
}

// Returns 1 if keyword

int is_keyword(char *token){
   const int size = 35; 
   char *keywords[] = {"accessor", "and", "array", "bool", "case", "character", 
   "constant", "else", "elsif", "end", "exit", "float",
   "func", "if", "ifc", "in", "integer", "is", "mutator", "natural", "null", 
   "of", "or", "others", "out", "pkg", "positive",
   "proc", "ptr", "range", "subtype", "then", "type", "when", "while"};
   int i;
   for(i = 0; i < size; i++){
      if(strcmp(token, keywords[i]) == 0){
         return 1;
      }
   }
   return 0;
}

// Returns 1 if numeric

int is_numeric(char *token){
   int dots = 0;
   int i;
   for(i = 0; i < strlen(token); i++){
      if(!(isxdigit(token[i]))){
         if((token[i] != '.') || (dots > 0)){
            return 0;
         }
         dots++;
      }
   }
   return 1;
}

// Returns 1 if indentifier 

int is_identifier(char *token){
   int i;
   if(!(isalpha(token[0]))){
      return 0;
   }
   for(i = 1; i < strlen(token); i++){
      if(token[i] != '_' && !isalpha(token[i]) && !isdigit(token[i])){
         return 0;
      }
   }
   return 1;
}

// Assign meaning to the tokens - character literals work, multiline comment attempt

void lex(char *line, int start, int end, int length, char *type, int in_comment){
   int i;
   int len;
   int start_copy;
   char token[MAXTOKEN];
   if(in_comment != 1){ // if not in comment
      while((start < length) && (isspace(line[start]))){ // strip leading spaces
         start++;
      }
   }
   if(start >= end){
      return;
   }
   //strncpy(token, &line[start], end - start);
   i = 0;
   len = end - start;
   start_copy = start;
   while(i < len){
      token[i] = line[start_copy];
      start_copy++;
      i++;
   }
   token[end-start] = '\0';
   if(is_keyword(token) == 1){
      printf("Keyword: %s\n", token);
   }
   else if(is_numeric(token) == 1){
      printf("Numeric: %s\n", token);
   }
   else if(is_identifier(token) == 1){
      printf("Identifier: %s\n", token);
   }
   else{
      printf("%s: %s\n", type, token);
   }
}

// Break the string down into tokens - character literal works, multiline comment attempt

int tokenize(char *line, int size){
   int start = 0;
   int end = 0;
   static int in_comment = 0;
   for(end = 0; end < size; end++){
      if(in_comment == 1){
         lex(line, start, end, size, "Token", in_comment);
         start = end;
         while(end < size - 1 && !(line[end] == '*' && line[end + 1] == '/')){ // find end of comment
            end++;
         }
         if(line[end] == '*' && line[end + 1] == '/'){ // if at end of comment
            end += 2;
            lex(line, start, end, size, "Comment", in_comment);
            in_comment = 0;
         } 
         else {
            lex(line, start, end, size, "Comment", in_comment);
            return 1;
            in_comment = 1;
         }  
         start = end;
         end--;
      }
      else if(line[end] == '/' && line[end + 1] == '*'){
         lex(line, start, end, size, "Token", in_comment);
         start = end;
         while(end < size - 1 && !(line[end] == '*' && line[end + 1] == '/')){ // find end of comment
            end++;
         }
         if(line[end] == '*' && line[end + 1] == '/'){ // if at end of comment
            end += 2;
            lex(line, start, end, size, "Comment", in_comment);
            in_comment = 0;
         } 
         else {
            lex(line, start, end, size, "Comment", in_comment);
            in_comment = 1;
         }  
         start = end;
         end--;
      }
      else if(is_operator_2(line, end) == 1){
         lex(line, start, end, size, "Token", in_comment); 
         start = end;
         end++;
         end++;
         lex(line, start, end, size, "Operator", in_comment);
         start = end;
         end--;
      }
      else if(is_operator_1(line, end) == 1){
         lex(line, start, end, size, "Token", in_comment); 
         start = end;
         end++;
         lex(line, start, end, size, "Operator", in_comment);
         start = end;
         end--;
      }
      else if(line[end] == '"'){
         lex(line, start, end, size, "Token", in_comment); 
         start = end;
         end++;
         while(end < size && line[end] != '"'){
            end++;
         }
         end++;
         lex(line, start, end, size, "String", in_comment);
         start = end;
         end--;
      }
      else if(line[end] == '\''){
         lex(line, start, end, size, "Token", in_comment);
         start = end;
         end++;
         if(line[end] == '\\'){
            end++;
         }
         end += 2;
         lex(line, start, end, size, "Char", in_comment);
         start = end;
         end--;
      }
      else if(isspace(line[end])){
         lex(line, start, end, size, "Token", in_comment);
         start = end;
      }
   }
   return 0;
}
