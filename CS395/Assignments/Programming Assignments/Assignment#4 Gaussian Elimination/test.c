/*********************************************
 * Id: plum0598
 *
 * This program performs Gaussian elimination on 
 * a matrix which is created from values from argv[]
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

// Prototypes

//void fill_matrix();
//void print_matrix(float **matrix, int num_rows, int num_columns);

// Main

int main(int argc, char *argv[]){
   
   if(argc < 2){
      printf("NO VALUES ENTERED\n");
      return 0;
   }
   
   int i;
   int j;
   int k;
   float tempji;
   //int n = atoi(argv[1]);
   int n = argc - 2;
   int num_rows;
   int num_columns; 
   
   //printf("%d\n", atoi(argv[1])); // DEBUG
   
   num_rows = (atoi(argv[1]));
   num_columns = (argc - 2) / (atoi(argv[1]));
   float matrix[num_rows][num_columns];
   
   
   
   //float **matrix;
   //matrix = (float **)malloc(num_rows * sizeof(float));
   //*matrix = (float *)malloc(num_columns * sizeof(float));
   
   
   
   
   //printf("rows = %d\n\n", num_rows); // DEBUG
   //printf("cols = %d\n\n", num_columns); // DEBUG
   
   // fill matrix with values in argv[]
   
   ///*
   
   j = 0;
   k = 0;
   for(i = 2; i < argc; i++){
      if(k < num_columns){
         //printf("j = %d\n", j); // DEBUG
         //printf("k = %d\n", k); // DEBUG
         matrix[j][k] = atof(argv[i]);
         k++;
         if(k == num_columns){
            //printf("j = %d\n", j); // DEBUG
            //printf("k = %d\n", k); // DEBUG
            k = 0;
            j++;
         }
      }
      //printf("i = %d\n\n", i-2); // DEBUG
   }   
   //printf("i = %d\n\n", i-2); // DEBUG
   
   // print matrix
   
   for(j = 0; j < num_rows; j++){
      for(k = 0; k < num_columns; k++){
         printf("%.2f  ", matrix[j][k]);
      }
      printf("\n");
   }         
   // gaussian elimination
   
   ///*
   
   //printf("TEST\n"); // DEBUG
   for(i = 0; i < n - 2; i++){
      //printf("TEST\n"); // DEBUG
      for(j = i + 1; j < n - 1; j++){
         tempji = matrix[j][i];
         for(k = i; k < n; k++){
            matrix[j][k] = matrix[j][k] - (matrix[i][k] * tempji / matrix[i][i]);
            //printf("%d\n", matrix[j][k]); // DEBUG
         }
      }
      for(j = 0; j < num_rows; j++){
         for(k = 0; k < num_columns; k++){
            printf("%.2f  ", matrix[j][k]);
         }
         printf("\n");
      }
   }
   //printf("TEST\n"); // DEBUG
   //*/
   
   /*
   
   for(i = 0; i < n-1; i++) {
      for(j = i+1; j < n; j++) {
         tempji = matrix[j][i];
         for(k = i; k < n+1; k++) {
            matrix[j][k] = matrix[j][k] - (matrix[i][k] * tempji / matrix[i][i]);
         }
      }
   }
   
   */
   
   // print matrix
   
   //printf("\n\n", matrix[j][k]);
   /*
   
   for(j = 0; j < num_rows; j++){
      for(k = 0; k < num_columns; k++){
         printf("%.2f  ", matrix[j][k]);
      }
      printf("\n");
   }

   */

   // end of program

   //*/
   
   //printf("%d\n", atoi(argv[1])); // DEBUG
   
   return 0;
}

/*

// function fills the matrix

void fill_matrix(){
   
}

// function prints the matrix

void print_matrix(float **matrix, int num_rows, int num_columns){
   int j;
   int k;
   for(j = 0; j < num_rows; j++){
      for(k = 0; k < num_columns; k++){
         printf("%.2f  ", matrix[j][k]);
      }
      printf("\n");
   }
}

*/