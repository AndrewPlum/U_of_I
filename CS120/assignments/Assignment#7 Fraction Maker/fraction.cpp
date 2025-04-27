        /*
        Andrew Plum
        CS 120-06
        Assignment #7
        10/12/21
        */

        // I did all of the regular assignment; there was no extra credit.

        /*
        This is a simple program where fractions are created and you can set there values
        */

#include<iostream>
using namespace std;

class fraction{                         // function class created
	private:
		int num;
		int den;
	public:
		fraction();                     // constructor with no arguments
		fraction(int,int);              // constructor with two arguments
		void set_fraction(int,int);
		void print_fraction();
		void print_mixed_number();
		void print_decimal();
};

int main(){
	fraction f1, f2, f3(9,0), f4(7,2);          // three fraction objects created and set through three different methods
	cout << "Fraction 1:" << endl;
	f1.set_fraction(15,4);               // test set fraction method
	f1.print_fraction();
	f1.print_mixed_number();
	f1.print_decimal();
    cout << endl;
    cout << "Fraction 2:" << endl;
    f2.print_fraction();                // test constructor with no arguments method
	f2.print_mixed_number();
	f2.print_decimal();
	cout << endl;
	cout << "Fraction 3:" << endl;
    f3.print_fraction();                // test constructor with two arguments method
	f3.print_mixed_number();
	f3.print_decimal();
	cout << endl;
	cout << "Fraction 4:" << endl;
	f4.print_fraction();                // test constructor with two arguments method
	f4.print_mixed_number();
	f4.print_decimal();
	cout << endl;
}

// fraction constructor with no arguments code

fraction::fraction(){
    num = 1;
    den = 1;
}

// fraction constructor with two arguments code

fraction::fraction(int n, int d){
    // set fraction to 0 over 1 if denominator is 0
    if(d == 0){
        num = 0;
        den = 1;
    }else{
        num = n;
        den = d;
    }
}

// set fraction through fraction class specific public function

void fraction::set_fraction(int n, int d){
    if(d == 0){
        num = 0;
        den = 1;
    }else{
        num = n;
        den = d;
    }
}

// print fraction through fraction class specific public function

void fraction::print_fraction(){
	cout << num << "/" << den << endl;
}

// print mixed number through fraction class specific public function

void fraction::print_mixed_number(){
    int r;
    int new_num;
    int whole_num;
    if(num > den){
    r = num % den;
    new_num = num - r;
    whole_num = new_num / den;
    cout << whole_num << " & " << r << "/" << den << endl;
    }
    if(num == den){
        cout << 1 << endl;
    }
    if(num < den){
        cout << num << "/" << den << endl;
    }
}

// print decimal through fraction class specific public function

void fraction::print_decimal(){
	cout << (double)num / (double)den << endl;
}
