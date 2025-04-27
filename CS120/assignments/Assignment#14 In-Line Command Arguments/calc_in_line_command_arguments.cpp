        /*
        Andrew Plum
        CS 120-06
        Assignment #14
        12/3/21
        */

        // I did all of the regular assignment AND THE EXTRA CREDIT.

        /*
        This is a simple program which uses in-line command arguments.
        */

#include<cstdlib> // for atoi(): ascii to integer
#include<iostream>  // for cout
#include<string.h>   // for strcmp()
using namespace std;

//Functions

void printf(string); // was included in initial assignment download

// Main

int main(int argc, char *argv[]){
    if(argc != 4){  // check if there are the right number of inputs
        printf("Error calculations should be of the form __ (operator) __.\n");
        return 0;
    }
    int answer = 0;
    int operand1, operand2;
    operand1 = atoi(argv[1]); // change the arguments from ascii to ints
    operand2 = atoi(argv[3]);

    // Addition

    if(strcmp("+",argv[2]) == 0){
        answer = operand1 + operand2;
    }

    // Subtraction

    if(strcmp("-",argv[2]) == 0){
        answer = operand1 - operand2;
    }

    // Multiplication

    if(strcmp("x",argv[2]) == 0){
        answer = operand1 * operand2;
    }

    // Division

    if(strcmp("/",argv[2]) == 0){
        if(operand2 == 0){
            printf("\nError calculations second operand can't be 0.\n");
            return 0;
        }
        answer = operand1 / operand2;
    }

    // Modulus

    if(strcmp("%",argv[2]) == 0){
        if(operand2 == 0){
            printf("\nError calculations second operand can't be 0.\n");
            return 0;
        }
        answer = operand1 % operand2;
    }

    // Print answer

    cout << operand1 << " " << argv[2] << " " << operand2 << " = " << answer << endl;
}

// Function definitions

void printf(string a){
    cout << a << endl;
}
