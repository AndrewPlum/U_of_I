    /*
	Andrew Plum
	CS 121-01
	Assignment #4
	2/6/22
	*/

		// I did all of the regular assignment and EXTRA CREDIT.

	/* my_fraction.cpp */

#include<iostream>
#include"my_fraction.h"
using namespace std;

int main(){

    // Intro

    cout << endl;
    cout << "This is a program which demonstrates the functionality of my fraction class." << endl;
    cout << "This program's output is meant to be compared to the fraction.cpp file to better follow along with what the program is doing." << endl;
    cout << endl;

    // Demonstrate constructors and print fraction function

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate constructors and print function." << endl;
	cout << endl;

    fraction f1, f2(3,4), f3(6,0);

    cout << "Fraction 1: ";
    f1.print(); // not a part of cout statement because print is type void; should print 1/1
    cout << endl;
    cout << "Fraction 2: ";
    f2.print(); // should print 3/4
    cout << endl;
    cout << "Fraction 3: ";
    f3.print(); // should print 6/1
    cout << endl;

    // demonstrate set and print fraction function

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate set and print function." << endl;
	cout << endl;

	int error_return;

    f1.set(7,49); // should simplify to 1/7
    f2.set(8,10); // should simplify to 4/5
    error_return = f3.set(5,0); // should simplify to 5/1

    cout << "Fraction 1: ";
    f1.print(); // not a part of cout statement because print is type void; should print 1/7
    cout << endl;
    cout << "Fraction 2: ";
    f2.print(); // should print 4/5
    cout << endl;
    cout << "Fraction 3: ";
    f3.print(); // should print 5/1
    cout << endl;
    cout << "Fraction 3 set function returning divide by zero error: " << error_return << endl; // should return a 4
    cout << endl;

    // demonstrate addition fraction function

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate addition function." << endl;
	cout << endl;

	fraction x, y, z, a, b;
	x = f1 + f2; // 33/35 = 1/7 + 4/5; fraction and fraction
    y = f2 + f3; // 29/5 = 4/5 + 5/1; fraction and fraction
    z = f3 + f1; // 36/7 = 5/1 + 1/7; fraction and fraction
    a = f1 + 3; // 22/7 = 1/7 + 3/1; fraction and integer
    b = 3 + f2; // 19/5 = 3/1 + 4/5; integer and fraction

    cout << "Calculated fraction answer 1: ";
    x.print(); // 33/35 = 1/7 + 4/5
    cout << "Calculated fraction answer 2: ";
    y.print(); // 29/5 = 4/5 + 5/1
    cout << "Calculated fraction answer 3: ";
    z.print(); // 36/7 = 5/1 + 1/7
    cout << "Calculated fraction answer 4: ";
    a.print(); // 22/7 = 1/7 + 3/1
    cout << "Calculated fraction answer 5: ";
    b.print(); // 19/5 = 3/1 + 4/5
    // notice the calculated fraction answers were not stored in original fractions
    cout << endl;

    // demonstrate subtraction fraction function

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate subtraction function." << endl;
	cout << endl;

	x = f1 - f2; // -23/35 = 1/7 - 4/5; fraction and fraction
    y = f2 - f3; // -21/5 = 4/5 - 5/1; fraction and fraction
    z = f3 - f1; // 34/7 = 5/1 - 1/7; fraction and fraction
    a = f1 - 3; // -20/7 = 1/7 - 3/1; fraction and integer
    b = 3 - f2; // 11/5 = 3/1 - 4/5; integer and fraction

    cout << "Calculated fraction answer 1: ";
    x.print(); // -23/35 = 1/7 - 4/5
    cout << "Calculated fraction answer 2: ";
    y.print(); // -21/5 = 4/5 - 5/1
    cout << "Calculated fraction answer 3: ";
    z.print(); // 34/7 = 5/1 - 1/7
    cout << "Calculated fraction answer 4: ";
    a.print(); // -20/7 = 1/7 - 3/1
    cout << "Calculated fraction answer 5: ";
    b.print(); // 11/5 = 3/1 - 4/5
    // notice the calculated fraction answers were not stored in original fractions
    cout << endl;

    // demonstrate multiplication fraction function

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate multiplication function." << endl;
	cout << endl;

	x = f1 * f2; // 4/35 = 1/7 * 4/5; fraction and fraction
    y = f2 * f3; // 4/1 = 40/10 = 8/10 * 5/1; fraction and fraction
    z = f3 * f1; // 5/7 = 5/1 * 1/7; fraction and fraction
    a = f1 * 3; // 3/7 = 1/7 * 3/1; fraction and integer
    b = 3 * f2; // 12/5 = 3/1 * 4/5; integer and fraction

    cout << "Calculated fraction answer 1: ";
    x.print(); // 4/35 = 1/7 * 4/5
    cout << "Calculated fraction answer 2: ";
    y.print(); // 4/1 = 4/5 * 5/1
    cout << "Calculated fraction answer 3: ";
    z.print(); // 5/7 = 5/1 * 1/7
    cout << "Calculated fraction answer 4: ";
    a.print(); // 3/7 = 1/7 * 3/1
    cout << "Calculated fraction answer 5: ";
    b.print(); // 12/5 = 3/1 * 4/5
    // notice the calculated fraction answers were not stored in original fractions
    cout << endl;

    // demonstrate division fraction function

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate division function." << endl;
	cout << endl;

	x = f1 / f2; // 5/28 = 1/7 / 4/5; fraction and fraction
    y = f2 / f3; // 4/25 = 4/5 / 5/1; fraction and fraction
    z = f3 / f1; // 35/1 = 5/1 / 1/7; fraction and fraction
    a = f1 / 3; // 1/21 = 1/7 / 3/1; fraction and integer
    b = 3 / f2; // 15/4 = 3/1 / 4/5; integer and fraction

    cout << "Calculated fraction answer 1: ";
    x.print(); // 5/28 = 1/7 / 4/5
    cout << "Calculated fraction answer 2: ";
    y.print(); // 4/25 = 4/5 / 5/1
    cout << "Calculated fraction answer 3: ";
    z.print(); // 35/1 = 5/1 / 1/7
    cout << "Calculated fraction answer 4: ";
    a.print(); // 1/21 = 1/7 / 3/1
    cout << "Calculated fraction answer 5: ";
    b.print(); // 15/4 = 3/1 / 4/5
    // notice the calculated fraction answers were not stored in original fractions
    cout << endl;

    // end of program message

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Program ended.";
	cout << endl;

	return 0;

}
