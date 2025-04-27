        /*
        Andrew Plum
        CS 120-06
        Lab #6
        10/1/21
        */

        // I did all of the regular assignment; there was no extra credit.

        /*
        This is a simple program which creates squares and rectangles based off user input.
        */

#include<iostream>
using namespace std;
// *** Prototypes of functions ****
int get_side();
char get_symbol();
int print_rectangle(int,int,char);

int main(){

    // beggining program prompt message

    cout << "\nThis is a simple program which creates rectangles based off user input.\n";
    cout << "You will be asked what to input and you will enter a number for side lengths and a letter for what the shape should be made out of.\n";
    cout << "The program then calculates and outputs a rectangle.\n";

    // original program

    int side1, side2, num_symbols;
    char c;
    side1 = get_side();
    side2 = get_side();
    c = get_symbol();
    num_symbols = print_rectangle(side1,side2,c);
    cout << num_symbols << " characters were printed.\n\n";
}

//--------------  Functions -------------------

    // Get Side

int get_side(){
    int side;
    cout << "Please enter a number for the side length between 1 and 10 (inclusive): ";
    do{
        cin >> side;
        if(side < 0 || side > 10){
            cout << "The side must be between 1 and 10.\n";
            cout << "Please try again: ";
        }
    }while(side < 0 || side > 10);
    return side;
}

    // Get symbol

char get_symbol(){
    char symbol;
    cout << "Please enter a character you want the rectangle to be made out of: ";
    cin >> symbol;
    return symbol;
}

    // Print rectangle

int print_rectangle(int side1, int side2, char c){
    int num_symbols;
    char symbol;
    symbol = c;
    for(int i = 1; i <= side2; i++){
        cout << symbol;
        for(int j = 2; j <= side1; j++){
            cout << symbol;
        }
        cout << "\n";
    }
    num_symbols = side1 * side2;
    return num_symbols;
}











