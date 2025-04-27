/*********************************************
 * Id: plum0598
 *
 * This program performs Gaussian elimination on 
 * a matrix which is created from values from argv[]
 *********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Prototypes

void print_matrix(int n, float A[n][n+1]);

// Main

int main(int argc, char *argv[]) {

   if(argc < 2){
      printf("NO VALUES ENTERED\n");
      return 0;
   }

   int rows = atoi(argv[1]);
   int columns = rows + 1;
   int n = rows;
   int num_elements = rows * columns;
   //printf("%d", n);
   
   // reject if wrong number of elements
   
   if (argc != num_elements + 2) {
      printf("Invalid number of elements.\n");
      //printf("%d %d", argc, num_elements);
      return 0;
   }

   // create matrix

   float A[n][n+1];

   // fill matrix

   int index = 2;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n + 1; j++){
         A[i][j] = atof(argv[index]);
         index++;
      }
   }
   
   // print original matrix
   
   //printf("Inputted matrix:\n");
   print_matrix(n, A);

   // perform iterations of gaussian elemination and print matrix
   
   // sometimes the sign of the outputted zeros don't match output - should fix
   for(int i = 0; i < n - 1; i++){
      for(int j = i + 1; j < n; j++){
         float tempji = A[j][i] / A[i][i];
         for(int k = i; k < n + 1; k++){
            A[j][k] = A[j][k] - (A[i][k] * tempji);
         }
      }
      //printf("\nInputted matrix after iteration %d:\n", i + 1);
      print_matrix(n, A);
   }
   
   /*
   DEL!!!
   for(int i = 0; i < n - 1; i++){
      for(int j = i + 1; j < n; j++){
         float tempji = A[j][i] / A[i][i];
         for(int k = i; k < n + 1; k++){
            A[j][k] = A[j][k] - tempji * A[i][k];
         }
      }
      //printf("\nInputted matrix after iteration %d:\n", i + 1);
      print_matrix(n, A);
   }
   */
   
   /*
   DEL!!!
   for(int i = 0; i < n - 2; i++){
      for(int j = i + 1; j < n - 1; j++){
         float tempji = A[j][i];
         for(int k = i; k < n; k++){
            A[j][k] = A[j][k] - (A[i][k] * tempji / A[i][i]);
         }
      }
      //printf("\nInputted matrix after iteration %d:\n", i + 1);
      print_matrix(n, A);
   }

   return 0;
   */
}

// Print matrix function

/*

void print_matrix(int n, float A[n][n+1]) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n + 1; j++) {
         printf("%.2f ", A[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

*/

// Print matrix function change sign of zeros

void print_matrix(int n, float A[n][n+1]){
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n + 1; j++){
         // check for negative zero and convert it to zero
         if(A[i][j] == 0.0 && signbit(A[i][j])){
            printf(" 0.00 ");
         }
         else
         {
            printf("%.2f ", A[i][j]);
         }
      }
      printf("\n");
   }
   printf("\n");
}