        /*
        Andrew Plum
        CS 120-06
        Assignment #2
        8/30/21
	*/

        // I did the regular assignment and the extra credit

   /* The calculator -
    * a simple program introducing some
    * fundimental programming concepts.
    */

#include<iostream> // include a library
using namespace std;

int main(){  // main() starts the program
	double num1;
	double num2;
	int choice;
	cout << "Enter value 1: ";
	cin >> num1;
	// get the first number
	
	cout << "Enter value 2: ";
        cin >> num2;
	// get the second number

	cout << "Operators:\n";
	cout << "Addition       --> 1\n";
 	cout << "Subtraction    --> 2\n";
 	cout << "Multiplication --> 3\n";
 	cout << "Division       --> 4\n";
	// print the menu

	cout << "Your choice? ";
	cin >> choice;
	// get the users choice

	if(choice == 1){
		cout << num1 << " + " << num2 << " = ";
		cout << num1 + num2 << endl;	
	}else if(choice == 2){
                cout << num1 << " - " << num2 << " = ";
                cout << num1 - num2 << endl;
        }else if(choice == 3){
                cout << num1 << " * " << num2 << " = ";
                cout << num1 * num2 << endl;
        }else if(choice == 4, num2 == 0){
                cout << "Warning undefined\n";	// if divided by 0
        }else if(choice == 4){
                cout << num1 << " / " << num2 << " = ";
                cout << num1 / num2 << endl;
	}else {cout << "Invalid operator\n";
	}// if number given is not 1-4, invalid 
	// use some ifs to do the right calculation
	// print the answer

	return 0;
}

