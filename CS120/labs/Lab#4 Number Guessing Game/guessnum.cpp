        /*
        Andrew Plum
        CS 120-06
        Lab #4
        9/18/21
        */

        // I did all of the regular lab assignment; there was no extra credit.

        /*  The number guessing game - the user guesses a number the computer chooses
        */

#include<iostream>     // include three libraries
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){             // main() starts the actual program

    // variables

    int true_num;        // actual right number trying to guess
    int guess_num;       // guess number values
    int num_of_guesses;  // number of guesses taken to guess the true number
    int repeat;          // variable set up to repeat game if wanted

    // code

	srand(time(NULL));

    do {
        cout << "\nHello this is a number guessing game.\n";
        cout << "I, the computer, will choose a number \nbetween 1 and 100 including the numbers 1 and 100, \nand you will try and guess it.\n";
        cout << "I have picked a number, what is it?\n";
        true_num =  1 + rand() % 100;
        num_of_guesses = 0;

        // guessing code

        do {
            do {
                cout << "\nEnter guess: ";
                cin >> guess_num;
                if (guess_num < 1 || guess_num > 100){
                    cout << "Invalid guess; your guess needs to be any number from 1 to 100.";
                }
            } while (guess_num < 1 || guess_num > 100);
            num_of_guesses++;
            if (guess_num < true_num){
                cout << "Your guess was wrong; it was too low.\n";
            }
            if (guess_num > true_num){
                cout << "Your guess was wrong; it was too high.\n";
            }
        } while (guess_num != true_num);

        // code for guessing the correct true number

        cout << "\nCongrats! You correctly guessed that the true number is " << true_num << ".\n";
        cout << "In total, it took you " << num_of_guesses << " guesses to guess the correct number.\n";

        // play again loop code

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

