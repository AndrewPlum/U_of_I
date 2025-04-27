        /*
        Andrew Plum
        CS 120-06
        Assignment #1
        8/30/21
	*/

        // I did the regular assignment; there was no extra credit.
   	
	// Catergorizing numbers

#include<iostream> // include a library
using namespace std; 
int main(){ // main() starts the program
	
	double x;
	double y;
	// set up variables

	cout << "This programs tells you whether \nthe number"; 
	cout << " you've entered is positve or negative, \neven or ";
	cout << "odd, and an integer or a decimal.\n";
	// tells what the program does
	
	cout << "Enter value: ";
        cin >> x;
	// User enters in number
	
	y = int(x);
	// set up int version of variable x which truncates it

	if(x - y == 0 && int(x) % 2 == 0 && x >= 0){
		cout << x << " is an integer, even, and positive.\n";
	}
        if(x - y == 0 && int(x) % 2 == 0 && x < 0){
                cout << x << " is an integer, even, and negative.\n";
        }
        if(x - y == 0 && int(x) % 2 != 0 && x > 0){
                cout << x << " is an integer, odd, and positive.\n";
        }
        if(x - y == 0 && int(x) % 2 != 0 && x < 0){
                cout << x << " is an integer, odd, and negative.\n";
        }
        if(x - y != 0 && int(x) % 2 != 0 && x > 0){
                cout << x << " is a decimal, odd, and positive.\n";
        }
        if(x - y != 0 && int(x) % 2 != 0 && x < 0){
                cout << x << " is a decimal, odd, and negative.\n";
        }
        if(x - y != 0 && int(x) % 2 == 0 && x > 0){
                cout << x << " is a decimal, odd, and positive.\n";
        }
        if(x - y != 0 && int(x) % 2 == 0 && x < 0){
                cout << x << " is a decimal, odd, and negative.\n";
        }
        // Use ifs to get correct answer
        // Print the catergorized number statement
	

	/*
	NOT IMPORTANT CODE
	if(x > 0 || x == 0 || x < 0){
		cout << "Invalid number entered\n";
	}
	NOT IMPORTANT CODE
	Was trying to code in message for invalid inputs
	*/ 


	return 0;
}
