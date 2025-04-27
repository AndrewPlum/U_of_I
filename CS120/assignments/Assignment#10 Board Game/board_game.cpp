        /*
        Andrew Plum
        CS 120-06
        Assignment #10
        10/30/21
        */

        // I did all of the regular assignment; there was no extra credit.

        /*
        This is a program where you play a board game.
        */

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
                            // Declaration of the square class
class square{
  private:
    int move;
    string message;
    string symbol;
    int gold_gain;
  public:
    square();
    void print();
    int action();
    int gold_change();
    void set(int,char,string,int);
};
                            // Function Prototypes
void print_board(square[], int, int);
void read_board(square[]);
void check_position(int &);
                           // Global variables
const int board_length = 20;

int main(){
  int current_player = 1, roll;
  int player1_position = 0, player2_position = 0;
  int player1_gold = 0;
  int player2_gold = 0;
  int El_Dorado = 50;
  square the_board[board_length];  // declare an array of squares
  srand(time(NULL));


  // Game Preface Details

  cout << endl << "Game Overview:" << endl << endl;
  cout << "This game is \"The Search for El Dorado.\" \nThe year is 1540 AD. You are an explorer with a party in the New World hunting for the lost city of gold; however you are not the only ones here.";
  cout << "\nOther explorers, hostile to your party, have come looking for the ancient city.";
  cout << "\nIt is a perilous journey ahead; one in which you will trek through a hazardous jungle possibly encountering hostile natives whilst you search for clues of unimaginable riches.";
  cout << "\nWill you be able to find El Dordado, the lost ancient city of gold?" << endl;

  // Game Rules

  cout << endl << "Game Rules:" << endl << endl;
  cout << "This game works like a simple board game." << endl;
  cout << "Each square on the board is represented by a dash or a line that alternate to better distinguish spaces in between." << endl;
  cout << "You press enter to roll and then your piece is moved those spaces." << endl;
  cout << "There are special events for landing on certain squares on the game board indicated by a special symbol." << endl;
  cout << "If landed on, the event will be indicated and its effects automatically applied." << endl;
  cout << "You win the game by having more gold score than your opponent." << endl;
  cout << "Gold score is gained through special events on several of the board's squares as well as by reaching the last square on the game board where El Dorado is located." << endl;
  cout << "When a player lands on the last board game square, the game ends and victory goes to the player with highest gold score." << endl << endl;

  // Rest of the code from the game file

  read_board(the_board);
  cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
  cout << "X                                                  X" << endl;
  cout << "X   Player 1's Gold: " << player1_gold << "                             X" << endl;
  cout << "X   ";
  print_board(the_board,player1_position,1);
  cout << "X                                                  X" << endl;
  cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
  cout << endl;
  cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
  cout << "X                                                  X" << endl;
  cout << "X   Player 2's Gold: " << player2_gold << "                             X" << endl;
  cout << "X   ";
  print_board(the_board,player2_position,2);
  cout << "X                                                  X" << endl;
  cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
  do{
      cout<<"\n\n\nPlayer "<<current_player<<" type enter to roll.\n";
      cin.ignore();
      roll = 1 + (rand() % 5);
      cout << "Player "<<current_player<<" rolled a "<<roll<<".\n";
      if(current_player == 1){
         player1_position += roll;
         check_position(player1_position);
         player1_gold += the_board[player1_position].gold_change();
         player1_position += the_board[player1_position].action();
         check_position(player1_position);
         if(player1_position == board_length-1){
             player1_gold += El_Dorado;
         }
      }
     else{
        player2_position += roll;
        check_position(player2_position);
		player2_gold += the_board[player2_position].gold_change();
        player2_position += the_board[player2_position].action();
        check_position(player2_position);
     	if(player2_position == board_length-1){
     	    player2_gold += El_Dorado;
     	}
     }
     cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
     cout << "X                                                  X" << endl;
     if(player1_gold < 0){
     cout << "X   Player 1's Gold: " << player1_gold << "                           X" << endl;
     }
     if(player1_gold == 0){
     cout << "X   Player 1's Gold: " << player1_gold << "                             X" << endl;
     }
     if(player1_gold > 0 && player1_gold < 100){
     cout << "X   Player 1's Gold: " << player1_gold << "                            X" << endl;
     }
     if(player1_gold >= 100){
     cout << "X   Player 1's Gold: " << player1_gold << "                           X" << endl;
     }
     cout << "X   ";
     print_board(the_board,player1_position,1);
     cout << "X                                                  X" << endl;
     cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
     cout << endl;
     cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
     cout << "X                                                  X" << endl;
     if(player2_gold < 0){
     cout << "X   Player 2's Gold: " << player2_gold << "                           X" << endl;
     }
     if(player2_gold == 0){
     cout << "X   Player 2's Gold: " << player2_gold << "                             X" << endl;
     }
     if(player2_gold > 0 && player2_gold < 100){
     cout << "X   Player 2's Gold: " << player2_gold << "                            X" << endl;
     }
     if(player2_gold >= 100){
     cout << "X   Player 2's Gold: " << player2_gold << "                           X" << endl;
     }
     cout << "X   ";
     print_board(the_board,player2_position,2);
     cout << "X                                                  X" << endl;
     cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
     current_player = (current_player % 2) + 1;
  }while((player1_position<board_length-1) && (player2_position<board_length-1));
  current_player = (current_player % 2) + 1;
  if(player1_gold > player2_gold){
  	cout << "\nPlayer 1 has more gold! \nPlayer 1 Wins!!!\n";
  }
  if(player1_gold < player2_gold){
      cout << "\nPlayer 2 has more gold! \nPlayer 2 Wins!!!\n";
  }
  if(player1_gold == player2_gold){
        cout << "\nPlayer 1 and player 2 have the same amount of gold. \nIt's a tie game.\n";
  }
  cin.ignore();
  return 0;
}


void read_board(square b[]){
     ifstream infile;
     infile.open("game.txt");
     int square_number, square_move;
     string square_message;
     char square_symbol;
     int gold_gain;
     while(!infile.eof()){
         infile >> square_number >> square_move >> gold_gain >> square_symbol;
         getline(infile,square_message);
         if(square_number < board_length)
               b[square_number].set(square_move,square_symbol,square_message,gold_gain);
     }
}
void print_board(square b[], int player_position, int player_number){
     for(int i = 0; i < board_length; i++){
         if(i != player_position){
             b[i].print();
        }else{
        	 cout << "|";
             cout << "\e[4m" << player_number << "\e[0m";
        }
    }
    cout << "Goal   X\n";
    cout << "X                                           ";
    cout << "       X\n";
}
void check_position(int &p){
    if(p < 0)
         p = 0;
    if(p >= board_length)
         p = board_length-1;
}
                           // Functions of the class square
square::square(){
     symbol = " ";
     move = 0;
     message = "";
     gold_gain = 0;
}
int square::action(){
     cout << message << endl;
     return move;
}
int square::gold_change(){
     return gold_gain;
}
void square::print(){
     cout << "|";
     cout << "\e[4m" << symbol << "\e[0m";
}
void square::set(int m, char s, string a_message, int g){
     move = m;
     symbol = s;
     message = a_message;
     gold_gain = g;
}
