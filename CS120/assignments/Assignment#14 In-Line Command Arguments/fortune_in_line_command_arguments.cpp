        /*
        Andrew Plum
        CS 120-06
        Assignment #14
        12/3/21
        */

        // I did all of the regular assignment and the extra credit.

        /*
        This is a simple program which uses in-line command arguments for a fortune teller.
        */

#include<iostream> // include a library
#include<cstdlib>
#include<string.h>
#include<ctime>
using namespace std;

int main(int argc, char *argv[])  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
    int disliked;  // create a variable to store the disliked number
	int age;       // create a variable to store the age of the user
	int year_born;    // create a variable to store the decade the user was born
	int lucky;     // create a variable to store the lucky number
	// ------------- Get user input -------------------------
	favorite = atoi(argv[1]);
	cout << "Your favorite number is: " << favorite << endl;  // output
    disliked = atoi(argv[2]);
    cout << "The number you entered that you don't like is: " << disliked << endl;
	age = atoi(argv[3]);
	cout << "You entered " << age << " for your age" << endl;
	year_born = atoi(argv[4]);
	cout << "You entered " << year_born << " for the year you were born" << endl;
	lucky = int(double((favorite*disliked*year_born)+(time(NULL) % 10))/(age/10)) % 10;  // *** THIS IS WHERE TIME IS USED FOR THE EXTRA CREDIT ***
	cout << endl << "Your secret, lucky number is: " << lucky << endl;
	if(lucky < 0){  // conditional, calues less than 0
		cout << "Try to be less negative." << endl;
	}
	if(lucky >= 0 && lucky < 5){ // 0 to 4 inclusive
		cout << "Think bigger!" << endl;
	}
	if(lucky >= 5 && lucky < 9){ // 5 to 8 inclusive
		cout << "Today you should embrace technology." << endl;
	}
	if(lucky == 9){ // exactly 9
		cout << "Today is your lucky day!" << endl;
	}
	if(lucky == 7){ // exactly 7
                cout << "This decade you are in your prime" << endl;
    }
	return 0;
}
