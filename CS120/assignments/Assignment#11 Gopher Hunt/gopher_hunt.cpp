        /*
        Andrew Plum
        CS 120-06
        Assignment #11
        11/7/21
        */

        // I did all of the regular assignment; and the EXTRA CREDIT.

        /*
        This is gopher hunt, a game program similar to minesweeper. In this version, corners count as neighboring mines.
        */

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

// Global Variables

const int width = 10;         // for array
const int height = 10;        // for array

// Function Prototypes

void check_for_zeros(int, int, int [height][width], char [height][width]);     // *** EXTRA CREDIT ***

// Main

int main(){
    int result = 0; // used to exit game loop
    int win_condidtion_count = 0; // counts how many hidden spaces are left
    int width_guess; // variable to store entered guess
    int height_guess; // variable to store entered guess
    int num_of_mines = 10;                  // roughly the number of mines will be equal to the number the variable num_of_mines is equal to; may have variation due to randomness
    int mine_num = num_of_mines - 1;        // signifies which numbers are mines
    int true_num_of_mines;                  // the true number of mines which is counted after full field is created
    int num_of_neighbor_mines_counter;
    int full_field[height][width];  // declare an array of arrays
    char guess_field[height][width];  // declare an array of arrays
    srand(time(NULL));

    // Game Preface Details

    cout << endl << "Game Overview:" << endl << endl;
    cout << "This is the game gopher hunt. \nThere is a field full of randomly placed gopher holes." << endl;

    // Game Rules

    cout << endl << "Game Rules:" << endl << endl;
    cout << "You, the player, pick cells on a two dimensional grid of this field trying to avoid the locations of the gophers. The fields cells are numbered as coordinates in the fourth quadrant of a Cartesian plane except without negative y values. \nEach time a cell is selected, the number of gophers in the neighboring spaces is revealed in that cell (neighbors includes diagonals so each cell has eight neighbors). \nIf the value zero is revealed in a cell, all of its neighboring cell are revealed.\nThe player wins if the reveal all of the cells without gophers and loses if they pick a cell containing a gopher. \n There is a counter at the top with the number of not yet guessed cells, a line as a separator, and the number of mines on the right of the line separator. \nThis game is very similar to minesweeper." << endl;
	cout << endl << endl;

    // Create full mine field

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            full_field[i][j] = rand() % (num_of_mines);     // fill the array of arrays with a random field of values
            if(full_field[i][j] != mine_num){               // change all the values which aren't the set mine number to 0
                full_field[i][j] = 0;
            }
        }
    }

        // Count the true number of mines for win condition

    true_num_of_mines = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(full_field[i][j] == mine_num){
                true_num_of_mines++;                        // if equal to the number which represents a mine, increment the mine counter
            }
        }
    }

        // figure out number for spaces which neighbor mines

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(full_field[i][j] != mine_num){               // if not a mine then

                num_of_neighbor_mines_counter = 0;

                if(full_field[i + 1][j] == mine_num && i + 1 < height){
                    num_of_neighbor_mines_counter++;
                }
                if(full_field[i - 1][j] == mine_num && i > 0){
                    num_of_neighbor_mines_counter++;
                }
                if((full_field[i][j + 1] == mine_num) && j + 1 < width){
                    num_of_neighbor_mines_counter++;
                }
                if((full_field[i][j - 1] == mine_num) && j > 0){
                    num_of_neighbor_mines_counter++;
                }
                if((full_field[i + 1][j + 1] == mine_num) && j + 1 < width && i + 1 < height){
                    num_of_neighbor_mines_counter++;
                }
                if((full_field[i - 1][j - 1] == mine_num) && j > 0 && i > 0){
                    num_of_neighbor_mines_counter++;
                }
                if(full_field[i + 1][j - 1] == mine_num && i + 1 < height && j > 0){
                    num_of_neighbor_mines_counter++;
                }
                if(full_field[i - 1][j + 1] == mine_num && i > 0 && j + 1 < width){
                    num_of_neighbor_mines_counter++;
                }

                full_field[i][j] = num_of_neighbor_mines_counter;
            }
            cout << full_field[i][j] << " "; // *** THIS PRINTS THE KEY AND IS IMPORTANT FOR WHEN I AM SCRIPTING SO I KNOW WHERE THE MINES ARE. THIS LINE AND THE NEXT "cout << endl;" LINE CAN BE COMMENTED OUT IF I DON"T WANT THE KEY BEING PRINTED ***
        }
        cout << endl;
    }
    cout << endl << endl;

    // Create blank guessing field

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            guess_field[i][j] = '-';
            //guess_field[i][j] = full_field[i][j]+48; // not necessary
            cout << guess_field[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    // Game loop

    do{
        cout << "Which space on the field do you want to explore?" << endl;
        do{
            cout << "Enter the x coordinate number from 1 to " << width << ": ";
            cin >> width_guess;
        }while(!(width_guess > 0 && width_guess < 11)); // enforces bounds
        do{
            cout << "Enter the y coordinate number from 1 to " << height << ": ";
            cin >> height_guess;
        }while(!(height_guess > 0 && height_guess < 11)); // enforces bounds
        // change the guesses so they match with what's supposed to be their corresponding array value
        width_guess -= 1;
        height_guess -= 1;
        // change guessing field
        cout << endl;
        if(full_field[height_guess][width_guess] == mine_num){
            guess_field[height_guess][width_guess] = '*';
            result = -1;
        }
        if(full_field[height_guess][width_guess] != mine_num){
            guess_field[height_guess][width_guess] = full_field[height_guess][width_guess] + 48;
            check_for_zeros(width_guess, height_guess, full_field, guess_field);    // check for zeros and the neighbors, reveals all neighbors to zeros  // *** EXTRA CREDIT ***
        }
        win_condidtion_count = 0;
        for(int i = 0; i < height; i++){
           for(int j = 0; j < width; j++){
              if(guess_field[i][j] == '-'){
                 win_condidtion_count++;
              }
           }
        }
        cout << win_condidtion_count << " | " << true_num_of_mines << endl;
        if(win_condidtion_count == true_num_of_mines){
          result = 1;
        }

        // Print the affect guessing field array

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                cout << guess_field[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

    }while(result == 0);

    // Wining and losing messages

    if(result == -1){
        cout << "You lost the game." << endl;
    }
    if(result == 1){
        cout << "You won the game!!!" << endl;
    }

    return 0;
}

// *** EXTRA CREDIT ***

void check_for_zeros(int width_guess, int height_guess, int full_field[height][width], char guess_field[height][width]){

    int x = width_guess;
    int y = height_guess;

	if(x >= width || y >= height || x < 0 || y < 0){
		return;
	}

    if(full_field[height_guess][width_guess] == 0){               // if not a mine then

        // show all neighboring cells because there are no mines nearby

		if(height_guess + 1 < height)
        	guess_field[height_guess + 1][width_guess] = full_field[height_guess + 1][width_guess] + 48;

		if(height_guess - 1 >= 0)
	        guess_field[height_guess - 1][width_guess] = full_field[height_guess - 1][width_guess] + 48;

		if(width_guess + 1 < width)
	        guess_field[height_guess][width_guess + 1] = full_field[height_guess][width_guess + 1] + 48;

		if(width_guess - 1 >= 0)
	        guess_field[height_guess][width_guess - 1] = full_field[height_guess][width_guess - 1] + 48;

		if(height_guess + 1 < height && width_guess + 1 < width)
	        guess_field[height_guess + 1][width_guess + 1] = full_field[height_guess + 1][width_guess + 1] + 48;

		if(height_guess - 1 >= 0 && width_guess - 1 >= 0)
	        guess_field[height_guess - 1][width_guess - 1] = full_field[height_guess - 1][width_guess - 1] + 48;

		if(height_guess + 1 < height && width_guess - 1 >= 0)
	        guess_field[height_guess + 1][width_guess - 1] = full_field[height_guess + 1][width_guess - 1] + 48;

		if(height_guess - 1 >= 0 && width_guess + 1 < width)
    	    guess_field[height_guess - 1][width_guess + 1] = full_field[height_guess - 1][width_guess + 1] + 48;

        // recursion to check nearby zeros

        if(height_guess + 1 < height && guess_field[height_guess + 2][width_guess] == '-')
	        check_for_zeros(width_guess, height_guess + 1, full_field, guess_field);

        if(height_guess - 1 >= 0 && guess_field[height_guess - 2][width_guess] == '-')
    	    check_for_zeros(width_guess, height_guess - 1, full_field, guess_field);

        if(width_guess + 1 < width && guess_field[height_guess][width_guess + 2] == '-')
        	check_for_zeros(width_guess + 1, height_guess, full_field, guess_field);

        if(width_guess - 1 >= 0 && guess_field[height_guess][width_guess - 2] == '-')
	        check_for_zeros(width_guess - 1, height_guess, full_field, guess_field);

        if(height_guess + 1 < height && width_guess + 1 < width && guess_field[height_guess + 2][width_guess + 2] == '-')
    	    check_for_zeros(width_guess + 1, height_guess + 1, full_field, guess_field);

        if(height_guess - 1 >= 0 && width_guess - 1 >= 0 && guess_field[height_guess - 2][width_guess - 2] == '-')
        	check_for_zeros(width_guess - 1, height_guess - 1, full_field, guess_field);

        if(height_guess + 1 < height && width_guess - 1 >= 0 && guess_field[height_guess + 2][width_guess - 2] == '-')
	        check_for_zeros(width_guess - 1, height_guess + 1, full_field, guess_field);

        if(height_guess - 1 >= 0 && width_guess + 1 < width && guess_field[height_guess - 2][width_guess + 2] == '-')
    	    check_for_zeros(width_guess + 1, height_guess - 1, full_field, guess_field);

    }

    return;
}


/* To Do

    H


*/
