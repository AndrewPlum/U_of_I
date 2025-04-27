    /*
	Andrew Plum
	CS 121-01
	Assignment #10
	3/25/22
	*/

		// I did all of the regular assignment.
		// NOTE: first generation (so the root) is index 0, second generation (root's children) index 1, and so on and so forth - need to know this for the grow function depth

	/* binary_trees.cpp */

#include<iostream>
#include"binary_trees.h"
#include<cstdlib> // srand
#include<ctime> // time
#include<cmath> // x^y, sin, and cos
#include<string> // for operator names more than 1 character like sin and cos
using namespace std;

int main(){

	// Seed with time

    srand(time(NULL)); // set random seed

    // Intro

    cout << endl;
    cout << "This is program which demonstrates binary expression trees and their functionality." << endl;
    cout << endl;

    // create node

    tree root;

    // create random binary

    root.grow(3); // first generation (so the root) is index 0, second generation (root's children) index 1, and so on and so forth

    // print node

    root.print();
    cout << endl;

	// evaluate

	double answer = 0;
	answer = root.evaluate();
	cout << endl << "Answer (if answer is \"inf\" the answer is undefined): " << answer << endl;

	// delete binary tree and printing afterwards

	root.clear(); // delete
	cout << endl;
    root.print(); // shouldn't print anything
    cout << endl;

	return 0;

}
