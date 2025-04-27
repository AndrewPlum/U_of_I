#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
        int x = 7;
	cout << "x = " << x << endl;
	// prints 7

	double y; 
	y = (99/100) * 1000;
        cout << "y = " << y << endl;
	// prints 0

	double Z;
	Z = (99.0/100) * 1000;
        cout << "Z = " << Z << endl;
	// prints 990

	int a;
	double num1, num2;
	num1 = 99;
	num2 = 100;
        a = (num1/num2) * 1000;
        cout << "a = " << a << endl;
	// prints 990

	int b;
	int in1;
	int in2;
	in1 = 99;
	in2 = 100;
	b = (double(in1)/double(in2)) * 1000;
	cout << "b = " << b << endl;
	// prints 990

}



