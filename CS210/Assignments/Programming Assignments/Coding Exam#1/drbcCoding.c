#define MAXTOKEN 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This is the function you need to write
void parser(char *line, int length);

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
      parser(line, read);
   }

   fclose(fp);
   if (line) {
      free(line);
   }
   exit(EXIT_SUCCESS);
}

/*
void parser(char *line, int length) {
   int i;
   char s[11];
   if(length >= 4){
      if(line[3] == '*'){
         i = 0;
         while(i < 10){
            s[i] = line[i];
            i++;
         }
         s[i] = '\n';
         printf(s);
      //printf(line);
      }
   //printf(line);
   }
}
*/

/*
void parser(char *line, int length) {
   int i = 0;
   if(length >= 4){
      if(line[3] == '*'){
         /*if(length < 10){
            for(i = 0; i < length; i++){
         	   printf("%c", line[i]);
      	   }
         } else {
            for(i = 0; i < 10; i++){
               printf("%c", line[i]);
            }
         }
         
         for(i = 0; i < 10; i++){
         	printf("%c", line[i]);
            if(line[i] == '\n'){
               return;
            }
         }
         printf("\n");
      //printf(line);
      }
   //printf(line);
   }
}
*/
void parser(char *line, int length) {
   char token[MAXTOKEN];
   int len = 10;
   if(length < len){
      len = length;
   }
   if(len < 4 || line[3] != '*'){
      return;
   }
   len--;
   strncpy(token, line, len);
   token[len] = '\0';
   printf("%s\n", token);
}
/*
void parser(char *line, int length) {
   int start = 0;
   int end = 9;
   if(line[3] == '*'){
      for(start = 0; start < end; start++){
	     printf("%c", line[start]);
	  }
	  printf("\n");
	  //printf(line);
   }
}
*/
