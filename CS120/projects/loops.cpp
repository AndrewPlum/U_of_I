#include<iostream>
using namespace std;
int main(){

/*
	// enter a number between one and three
	int input = 0;
	int counter = 0;
	cout << "Enter a number 1 to 3\n";
	cin >> input;
	counter += 1
	while ((input < 1 || input > 3) && counter < 3){
		cout << "Invalid number\n";
		cout << "Try again\n";
		cout << "Enter a number 1 to 3\n";
		cin >> input;
	}
	if (counter <= 3){
		cout << "Your number is " << input;
		cout << endl;
	}
*/

	int a, b, c, d;
	c = 0;
	d = 0;

	cout << "Enter a value for a and then b\n";
	cin >> a;
	cin >> b;
	while (d < b){
	c += a;
	d++;
	}
	cout << "Answer = " << c << endl;
}
