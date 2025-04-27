    /*
    Andrew Plum
    CS 121-01
    Assignment #4
    2/6/22
    */

		// I did all of the regular assignment and EXTRA CREDIT.

	/* my_fraction.h */

#include<iostream>
using namespace std;

enum error_code{success, fail, overflow, underflow, dividebyzero}; // succes:0 fail:1 overflow:2 underflow:3 dividebyzero:4

class fraction{
    private:
        int num;
        int den;
    public:
        fraction();                     // constructor with no arguments
		fraction(int,int);              // constructor with two arguments
		~fraction();                    // destructor
        error_code set(int,int);        // set numerator and denominator
        error_code setn(int);           // set numerator ***NOT REQUIRED FOR ASSIGNMENT***
        error_code setd(int);           // set denominator ***NOT REQUIRED FOR ASSIGNMENT***
        void print();                   // print fraction
        fraction operator+ (fraction);  // addition fraction and fraction
        fraction operator+ (int);       // addition fraction and integer
        friend fraction operator+ (int,fraction);  // addition integer and fraction
        fraction operator- (fraction);  // subtraction fraction and fraction
        fraction operator- (int);       // subtraction fraction and integer
        friend fraction operator- (int,fraction);  // subtraction integer and fraction
        fraction operator* (fraction);  // multiplication fraction and fraction
        fraction operator* (int);       // multiplication fraction and integer
        friend fraction operator* (int,fraction);  // multiplication integer and fraction
        fraction operator/ (fraction);  // division fraction and fraction
        fraction operator/ (int);       // division fraction and integer
        friend fraction operator/ (int,fraction);  // division integer and fraction
        void reduce();              // reduce fraction simplest improper form ***EXTRA CREDIT***
};

// fraction constructor with no arguments code

fraction::fraction(){
    num = 1;
    den = 1;
}

// fraction constructor with two arguments code

fraction::fraction(int n, int d){
    // set fraction to 0 over 1 if denominator is 0
    if(d == 0){
        num = n;
        den = 1;
    }else{
        num = n;
        den = d;
        reduce(); // reduces to simplest improper form
    }
}

// fraction destructor

fraction::~fraction(){
    num = 1;
    den = 1;
    // not needed code:
    // cout << "Destroying fraction: ";
    // print();
    // cout << endl;
}

// set fraction through fraction class specific public function

error_code fraction::set(int n, int d){
    // set fraction to n over 1 if denominator is 0
    error_code ec = success;
    if(d == 0){
        num = n;
        den = 1;
        ec = dividebyzero;
    }else{
        num = n;
        den = d;
        reduce(); // reduces to simplest improper form
    }
    return ec;
}

// set fraction numerator through fraction class specific public function ***NOT REQUIRED FOR ASSIGNMENT***

error_code fraction::setn(int n){
    error_code ec = success;
    num = n;
    reduce(); // reduces to simplest improper form
    return ec;
}

// set fraction denominator through fraction class specific public function ***NOT REQUIRED FOR ASSIGNMENT***

error_code fraction::setd(int d){
    error_code ec = success;
    if(d == 0){
        den = 1;
        ec = dividebyzero;
    }
    reduce(); // reduces to simplest improper form
    return ec;
}

// print fraction through fraction class specific public function

void fraction::print(){
    cout << num << "/" << den << endl;
}

// ADDITION of fraction and fraction through fraction class specific public function

fraction fraction::operator+(fraction f){
    fraction answer;
    int temp_num, temp_den; // because I don't want to change original values
    temp_num = num;
    temp_den = den;
    int new_common_den;
    num = num * f.den; // done because we will later need a common denominator
    f.num = f.num * den; // done because we will later need a common denominator
    new_common_den = den * f.den; // get common denominator
    answer.num = num + f.num;
    answer.den = new_common_den;
    answer.reduce(); // reduces to simplest improper form
    num = temp_num; // set back to original
    den = temp_den; // set back to original
    return answer;
}

// ADDITION of fraction and integer through fraction class specific public function

fraction fraction::operator+(int x){
    fraction answer;
    answer.num = num + (x * den);
    answer.den = den * 1; // unecessary but shown still
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// ADDITION of fraction and integer through fraction class specific friend public function

fraction operator+(int x, fraction f){
    fraction answer;
    answer.num = (x * f.den) + f.num;
    answer.den = 1 * f.den; // unecessary but shown still
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// SUBTRACTION of fraction and fraction through fraction class specific public function

fraction fraction::operator-(fraction f){
    fraction answer;
    int temp_num, temp_den; // because I don't want to change original values
    temp_num = num;
    temp_den = den;
    int new_common_den;
    num = num * f.den; // done because we will later need a common denominator
    f.num = f.num * den; // done because we will later need a common denominator
    new_common_den = den * f.den; // get common denominator
    answer.num = num - f.num;
    answer.den = new_common_den;
    answer.reduce(); // reduces to simplest improper form
    num = temp_num; // set back to original
    den = temp_den; // set back to original
    return answer;
}

// SUBTRACTION of fraction and integer through fraction class specific public function

fraction fraction::operator-(int x){
    fraction answer;
    answer.num = num - (x * den);
    answer.den = den * 1; // unecessary but shown still
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// SUBTRACTION of fraction and integer through fraction class specific friend public function

fraction operator-(int x, fraction f){
    fraction answer;
    answer.num = (x * f.den) - f.num;
    answer.den = 1 * f.den; // unecessary but shown still
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// MULTIPLICATION of fraction and fraction through fraction class specific public function

fraction fraction::operator*(fraction f){
    fraction answer;
    answer.num = num * f.num;
    answer.den = den * f.den;
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// MULTIPLICATION of fraction and integer through fraction class specific public function

fraction fraction::operator*(int x){
    fraction answer;
    answer.num = num * x;
    answer.den = den * 1; // unecessary but shown still
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// MULTIPLICATION of fraction and integer through fraction class specific friend public function

fraction operator*(int x, fraction f){
    fraction answer;
    answer.num = x * f.num;
    answer.den = 1 * f.den;
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// DIVISION of fraction and fraction through fraction class specific public function

fraction fraction::operator/(fraction f){
    fraction answer;
    answer.num = num * f.den;
    answer.den = den * f.num;
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// DIVISION of fraction and integer through fraction class specific public function

fraction fraction::operator/(int x){
    fraction answer;
    answer.num = num * 1; // unecessary but shown still
    answer.den = den * x; // flip integer fraction for division
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// DIVISION of fraction and integer through fraction class specific friend public function

fraction operator/(int x, fraction f){
    fraction answer;
    answer.num = x * f.den; // unecessary but shown still
    answer.den = 1 * f.num; // flip integer fraction for division
    answer.reduce(); // reduces to simplest improper form
    return answer;
}

// reduce fraction simplest improper form ***EXTRA CREDIT***

void fraction::reduce(){
    for(int i = (num * den); i > 1; i--){
        if((num % i == 0) && (den % i == 0)){ // finds greatest common factor between numerator and denominator
            num = num / i; // reduces by greatest common factor
            den = den / i; // reduces by greatest common factor
        }
    }
}
