        /*
        Andrew Plum
        CS 120-06
        Assignment #4
        9/18/21
        */

        // I did all of the regular assignment; there was no extra credit.

 	/*  The game of NIM 
 	*/

 #include<iostream>     // include two libraries
 #include<cstdlib>
 using namespace std;

 int main()             // main() starts the actual program 
 {
    // ---------------- Variable declarations ---------------------
    
    int num_objects; 
    int current_player; 
    int move;
    int repeat;
    
    // ------------------ Beginning Message -----------------------

   do {
       cout << "\nThis is the game of nim.\n";
       cout << "There are 23 objects that are slowly taken away.\n";
       cout << "On your turn the, you choose to take away somewhere between 1 to 3 objects.\n";
       cout << "The computer then takes their turn, taking 1 to 3 objects away.\n";
       cout << "Turns continue to alternate back and fourth between you and the computer.\n";
       cout << "The game ends when all of the objects are taken away.\n";
       cout << "To win the game, you must not be the last one to take an object away.\n\n";

    // ----------- Beginning of the main game loop ----------------
    
       int num_objects = 23;
       int current_player = 1;
       do {                                      
           if (num_objects == 23){           // game commentary
                cout << "The game is about to start. What shall the first move be?\n";
                }
           if (current_player == 1) {    // conditional: if
                cout << "\nPlayer 1 enter your move (1-3): ";  // output
                cin >> move;                 // input
                while (move < 1 || move > 3 || move > num_objects){
                   cout << "Illegal move. \nEnter a new move (1-3): ";
                   cin >> move;
                }
           } else {                          // else part of conditional
                do {                         // make sure move is legal
                   move =  1+ rand() % 3;    // random computer move
                } while (move < 1 || move > 3 || move > num_objects);
                cout << "Computer removed " << move << endl;
           }
           num_objects = num_objects - move;  // implement the move
           cout << num_objects << " objects remaining. ";
           if (num_objects > 0){             // prints the number of objects 
                   for (int i = 0; i < num_objects; i++){
                       cout << "*";
                   }
                } 
           current_player = (current_player + 1) % 2;  // switch players
           if (num_objects == 20 || num_objects == 15 || num_objects == 8 || num_objects == 5){           // more game commentary
                cout << "\nInteresting move.\n\n";
                }
           if (num_objects == 12){           // more game commentary
                cout << "\nWe are at the halfway point now.\nIt's still anyone's game to win.\n\n";
                }
           if (num_objects < 4 && num_objects > 0){ // even more game commentary
                cout << "\nThe game's nearing its end; the winner is going to be...\n\n"; 
                }
       } while (num_objects > 0);                    
   
   // ------------  end of the game loop --------------------------
   
       if (current_player == 1){
           cout << "\nPlayer " << current_player << " wins!!!\n";
           cout << "Congratulations! You have prevailed and shown humans are superior to computers.\n";
           cout << "May the legacy of your triumph live on for eternity.\n";
       }     
       if (current_player == 0){
           cout << "\nPlayer " << current_player << " wins!!!\n";
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

