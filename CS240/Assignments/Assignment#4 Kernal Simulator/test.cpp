/*
Andrew Plum
Professor Wilder
CS 240
10/21/22
*/

    /*
    ***Assignment #3 - msh.c***
    */

#include<iostream>
using namespace std;

int main(){

    // variable declarations

    int x;

    // work

    x = 99;
    while(x > 0){
        x = x / 10;
        cout << x << endl;
    }

    // end of program

    return 0;

}
