	/*
	Andrew Plum
	CS 120-06
	Assignment #1
	8/30/21
	
	I did the regular assignment plus the extra credit; I added the variables and inputs of the age of the user and what decade the user was born as 
	well as one more conditional along with a new message accompanying it*/
	
   /* The fortune Teller -
    * a simple program introducing some
    * fundimental programming concepts.
    */
#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
        int disliked;  // create a variable to store the disliked number
	int age;       // create a variable to store the age of the user
	int decade;    // create a variable to store the decade the user was born	
	int lucky;     // create a variable to store the lucky number
	// ------------- Get user input -------------------------
	cout << "Enter your favorite number (no decimals): ";  // output
	cin >> favorite;  		// user input
	cout << "Enter a number you don't like (no decimals): ";
	cin >> disliked;
	cout << "Enter a whole number of your age (round if needed): ";
	cin >> age;
	cout << "Enter a whole number rounded to the tens place of the decade you were born (if 00 round up to 10): ";
        cin >> decade;
	lucky = ((favorite*disliked*age)/(decade/10)) % 10;
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
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}
