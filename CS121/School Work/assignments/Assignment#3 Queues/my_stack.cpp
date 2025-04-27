    /*
    Andrew Plum
    CS 121-01
    Assignment #3
    1/30/22
    */

        // I did all of the regular assignment

    /* my_stack.cpp */

#include<iostream> // include a library
#include<stack>
using namespace std;

// protypes

bool check_match(stack<char> &, char &);

// global constant variables

const int length = 1024;

int main(){

	stack<char> stack;

	// take in array

    char charArr[length];
    cout << "This is a program which demonstrates how a stack works." << endl;
    cout << "Enter a string: ";
    cin.getline(charArr, length);

    // Put Array on stack

	int error_counter = 0;

	for(int i = 0; (i < length) && (charArr[i] != '\0'); i++){

		char c = charArr[i];

		switch(c){
			case '(':
			case '[':
			case '{':
			case ')':
			case '}':
			case ']':
				error_counter++;
				stack.push(c);
				break;
		}

		switch(c){
			case ')':
				if(check_match(stack, c)){
					error_counter -= 2;
				}

				break;
			case ']':
				if(check_match(stack, c)){
					error_counter -= 2;
				}
				break;
			case '}':
			    if(check_match(stack, c)){
			    	error_counter -= 2;
			    }
			    break;
		}
	}

	cout << error_counter << " errors found." << endl;

}

// Function definitions

bool check_match(stack<char> &stack, char &c){
	char m = '\0';
	char n = '\0';
	switch(c){
		case '(':
			m = ')';
		    n = '(';
		    break;
		case '[':
		    m = ']';
		    n = '[';
		    break;
		case '{':
		    m = '}';
		    n = '{';
		    break;
		case ')':
			m = '(';
			n = ')';
			break;
		case ']':
			m = '[';
			n = ']';
			break;
		case '}':
			m = '{';
			n = '}';
			break;
	}
	stack.pop();
	if(stack.empty()){
		return false;
	} else {
		if(m == stack.top()){
			stack.pop();
			return true;
		} else {
			return false;
		}
	}
}

