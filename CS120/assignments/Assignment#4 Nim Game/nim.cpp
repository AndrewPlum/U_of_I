        /*
        Andrew Plum
        CS 120-06
        Assignment #4
        9/18/21
        */

        // I did all of the regular assignment. There was no extra credit; if there was I would have done it.

 	/*  The game of NIM - This game is a game where the user and computer take objects away until none are left.
 	**	The last one to take away an objects loses and the other player wins.
 	*/

 #include<iostream>     // include three libraries
 #include<cstdlib>
 #include<ctime>
 using namespace std;

 int main()             // main() starts the actual program
 {
    // ---------------- Variable declarations ---------------------
	
    int num_objects;
    int current_player;
    int start_com_objects;
    int move;
    int max_move;
    int min_move;
    int game_over;
    int repeat;
	
    do {
	
    num_objects = 23;       // recommended at 23
    start_com_objects = 23; // number of objects when game commentary starts; recommended to be equal to the same value as num_objects is
    max_move = 3;           // maximum move; recommended at 3
    min_move = 1;           // minimum move; recommended at 1
    current_player = 1;     // recommended not to change
    game_over = 0;          // set the number of objects when the game ends; recommended at 0

    // ------------------ Beginning Message -----------------------

       cout << "\nThis is the game of nim.\n";
       cout << "There are " << num_objects << " objects that are slowly taken away.\n";
       cout << "On your turn the, you choose to take away somewhere between " << min_move << " to " << max_move << " objects.\n";
       cout << "The computer then takes their turn, taking " << min_move << " to " << max_move << " objects away.\n";
       cout << "Turns continue to alternate back and forth between you and the computer.\n";
       cout << "The game ends when there are " << game_over << " objects left to take away.\n";
       cout << "To win the game, you must not be the last one to take an object away.\n\n";

    // ----------- Beginning of the main game loop ----------------
	
    srand(time(NULL));
       do {
           if (num_objects == start_com_objects){           // game commentary
                cout << "The game is about to start. What shall the first move be?";
                }
           if (current_player == 1) {    // conditional: if
                cout << "\n\nPlayer 1 enter your move (" << min_move << "-" << max_move << "): ";  // output
                cin >> move;                 // input
                while (move < min_move || move > max_move || move > num_objects){
                   cout << "Illegal move. \nEnter a new move (" << min_move << "-" << max_move << "): ";
                   cin >> move;
                }
           } else {                          // else part of conditional
                if (num_objects > max_move){        // code to change computer so it'll make moves not to loose
                    do {                         // make sure move is legal
                        move =  1+ rand() % max_move;    // random computer move
                    } while (move < min_move || move > max_move || move > num_objects);
                } else if (num_objects == min_move){
                        move = min_move;
                } else if (num_objects == max_move){
                        move = (max_move - min_move);
                } else if (num_objects < max_move){
                        move = (num_objects - min_move);
                }
                cout << "\n\nComputer removed " << move << endl;
           }
           num_objects = num_objects - move;  // implement the move
           cout << num_objects << " objects remaining.";
           if (num_objects > game_over){             // prints the number of objects 
                   for (int i = 0; i < num_objects; i++){
                       cout << "*";
                       if (i == num_objects){
                           cout << "\n";
                       }
                   }
                }
           current_player = (current_player + 1) % 2;  // switch players
           if (num_objects == 20 || num_objects == 15 || num_objects == 8 || num_objects == 5){           // more game commentary
                cout << "\n\nInteresting move.";
                }
           if (num_objects == 12){           // more game commentary
                cout << "\n\nWe are at the halfway point now.\nIt's still anyone's game to win.";
                }
           if (num_objects < 4 && num_objects > 0){ // even more game commentary
                cout << "\n\nThe game's nearing its end; the winner is going to be...";
                }
       } while (num_objects > game_over);

   // ------------  end of the game loop --------------------------

       if (current_player == 1){
           cout << "\n\nPlayer " << current_player << " wins!!!\n";
           cout << "Congratulations! You have prevailed and shown humans are superior to computers.\n";
           cout << "May the legacy of your triumph live on for eternity.\n";
       }
       if (current_player == 0){
           cout << "\n\nPlayer " << current_player << " wins!!!\n";
           cout << "Today technology has reigned superior to its maker.\n"; 
           cout << "The world embarks on a new age of uncertainty. It is a dark day for humanity.\n";
       }
       cout << "\nWould you like to play again?\n";
       cout << "Enter \"1\" for yes and \"0\" for no.\n";
       cin >> repeat;
       while (repeat != 1 && repeat != 0){
           cout << "Invalid answer. \nEnter \"1\" for yes and \"0\" for no.\n";
           cin >> repeat;
       }
   } while (repeat == 1);
   // do while loop if request to play again is true

   return 0;
}

