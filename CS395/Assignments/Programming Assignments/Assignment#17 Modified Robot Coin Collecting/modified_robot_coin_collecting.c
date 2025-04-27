/*********************************************
 * Id: plum0598
 *
 * This program finds the optimal soltion in gthe robot coin collecting problem.
 * Look at the problem description fcr more info.
 * Input: Matrix C[1..n, 1..m] whose elements are equal to 1 and 0
 * for cells with and without a coin, respectively.
 * Output: Largest number of coins the robot can bring to cell (n, m)
 *
 * Works like 99% of the time but odd niche case where it breaks - try to understand why
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes

int find_max(int num1, int num2);
int calculate_optimal_coins(int rows, int cols, int game_board[rows][cols]);
void display_table(int rows, int cols, int game_board[rows][cols]);
int is_obstacle(char cell_content);
void initialize_matrix(int rows, int cols, int matrix[rows][cols], int initial_value);

// Main function

int main(int argc, char *argv[]){
   if(argc < 4){
      printf("Insufficient command line arguments.\n");
      return 0;
   }

   int rows = atoi(argv[1]);
   int cols = atoi(argv[2]);
   int game_board[rows][cols];

   // input table
   
   int i = 0;
   int j = 0;
   while(i < rows){
      while(j < cols){
         switch(strcmp(argv[i * cols + j + 3], "X") == 0){
            case 1:
            game_board[i][j] = -1;
            break;
            default:
            game_board[i][j] = atoi(argv[i * cols + j + 3]);
         }
         j++;
      }
      i++;
      j = 0;
   }

   printf("Board Inputed:\n");
   display_table(rows, cols, game_board);

   // coin collection table
   
   int max_coins = calculate_optimal_coins(rows, cols, game_board);
   printf("The optimal path with this board is: %d\n", max_coins);

   return 0;
}

// Find the maximum of two integers

int find_max(int num1, int num2){
   if(num1 > num2){
      return num1;
   }
   else{
      return num2;
   }
}

// Calculate and display the coin collection table

int calculate_optimal_coins(int rows, int cols, int game_board[rows][cols]){
   int coin_table[rows][cols];
   initialize_matrix(rows, cols, coin_table, 0);
   coin_table[0][0] = game_board[0][0];

   int i = 1;
   int j = 1;

   // process rows
   
   while(i < rows && !is_obstacle(game_board[i][0])){
      coin_table[i][0] = coin_table[i - 1][0] + game_board[i][0];
      i++;
   }

   // obstacle found in the row
   
   while(i < rows){
      coin_table[i][0] = -10;
      i++;
   }

   // process columns
   
   while(j < cols && !is_obstacle(game_board[0][j])){
      coin_table[0][j] = coin_table[0][j - 1] + game_board[0][j];
      j++;
   }

   // obstacle found in the column
   
   while(j < cols){
      coin_table[0][j] = -10;
      j++;
   }

   // navigate the game board
   
   i = 1;
   while(i < rows){
      j = 1;
      while(j < cols){
         if(!is_obstacle(game_board[i][j])){
            coin_table[i][j] = find_max(coin_table[i - 1][j], coin_table[i][j - 1]) + game_board[i][j];
         }
         else{
            coin_table[i][j] = -10;
         }
         j++;
      }
      i++;
   }

   // reset negatives
   
   i = 0;
   while(i < rows){
      j = 0;
      while(j < cols){
         if(coin_table[i][j] < 0){
            coin_table[i][j] = 0;
         }
         j++;
      }
      i++;
   }

   // display coin collecting table
   
   printf("Coin Collecting Table:\n");
   display_table(rows, cols, coin_table);

   return coin_table[rows - 1][cols - 1];
}

// Display a given matrix

void display_table(int rows, int cols, int matrix[rows][cols]){
   int i = 0;
   int j = 0;
   while(i < rows){
      while(j < cols){
         if(matrix[i][j] == -1){
            printf("%c\t", 'X');
         }
         else{
            printf("%d\t", matrix[i][j]);
         }
         j++;
      }
      printf("\n");
      i++;
      j = 0;
   }
   printf("\n");
}

// Check if a cell content represents an obstacle

int is_obstacle(char cell_content){
   switch(cell_content){
      case -1:
      return 1;
      default:
      return 0;
   }
}

// Initialize a matrix with a specified initial value

void initialize_matrix(int rows, int cols, int matrix[rows][cols], int initial_value){
   int i = 0;
   int j = 0;
   while(i < rows){
      while(j < cols){
         matrix[i][j] = initial_value;
         j++;
      }
      i++;
      j = 0;
   }
}
