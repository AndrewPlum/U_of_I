    /*
	Andrew Plum
	CS 121-01
	Assignment #14
	4/30/22
	*/

		// !!! I have not completed the assignment as of yet. !!!
		// I have completed the template for the binary search tree and its insert, find, and visit function.
		// I have code demonstrating the functions.
		// I demonstrated it with the string, integer, and fraction binary search trees using the templates.
		// I still need to implement the code for it using one more class - I was going to do mixed numbers.

	/* binary_search_tree_template.cpp */

#include<iostream>
#include<string>
#include"fraction.h"
#include"binary_search_tree_template.h"
using namespace std;

void print_string(string data);
void print_int(int data);
void print_fraction(fraction data);

int main(){

    // intro

    cout << endl;
    cout << "This is a program which creates and demonstrates the functionality of a binary search tree." << endl;

    // intro for string binary tree

    cout << endl;
	cout << "Demonstrating string binary tree:" << endl;

    // create tree and variables

    tree<string> root_string;

    int keep_searching = 1;
    string search_key = "DEFAULT";
    string found_key = "DEFAULT";
    string concat = "";
    bool find_return = false;

	// inserting data

	for(int i = 0; i < 10; i++){
        concat += "T";
		root_string.insert(concat);
	}

	// printing binary tree in infix order

	cout << endl;
	cout << "Printing binary tree in infix order:" << endl;
	root_string.visit(print_string);

    // find relevant keys whose data contains a given substring

    cout << endl;
    cout << "Find key:" << endl;
    do{
        found_key = "DEFAULT";
        cout << endl;
		cout << "Enter the key you wish the program to search for(enter \"STOP!!!\" to stop):" << endl;
		cin >> search_key;
		if(search_key == "STOP!!!"){
            keep_searching = 0; // this here is technically unnecessary
            break; // exits the loop if nothing is entered
		}
		find_return = root_string.find(search_key, found_key);
        if(found_key == "DEFAULT"){
            found_key = "None";
        }
        cout << "Truth value returned:" << endl;
		if(root_string.find(search_key, found_key)){
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
		cout << "Key found:" << endl << found_key << endl;
	}while(keep_searching);



    // intro for integer binary tree



    cout << endl;
	cout << "Demonstrating integer binary tree:" << endl;

    // create tree and variables

    tree<int> root_int;

    int search_num = -1;
    int found_num = -1;
    find_return = false; // used previously

	// inserting data

	for(int i = 0; i < 10; i++){
		root_int.insert(i);
	}

	// printing binary tree in infix order

	cout << endl;
	cout << "Printing binary tree in infix order:" << endl << endl;
	root_int.visit(print_int);

    // find relevant keys whose data contains a given substring

    cout << endl;
    cout << "Find number:" << endl;

    cout << endl;
    cout << "5 entered in find function:" << endl;
    search_num = 5;
    find_return = root_int.find(search_num, found_num);
    cout << "Truth value returned:" << endl;
    if(root_int.find(search_num, found_num)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "Key found:" << endl << found_num << endl;

        // find a second time

    found_num = -1;
    cout << endl;
    cout << "100 entered in find function:" << endl;
    search_num = 100;
    find_return = root_int.find(search_num, found_num);
    if(found_num == -1){
        found_key = "None";
    }
    cout << "Truth value returned:" << endl;
    if(root_int.find(search_num, found_num)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "Key found:" << endl;
    if(found_num != -1){
        cout << found_num << endl;
    } else {
        cout << found_key << endl;
    }



    // intro for fraction binary tree



    cout << endl;
	cout << "Demonstrating fraction binary tree:" << endl;

    // create tree and variables

    tree<fraction> root_fraction;

    fraction f1(1,2), f2(5,4), f3(9,6), f4(4,2), f5(7,2);

    fraction search_fraction(-1,1);
    fraction found_fraction(-1,1);
    fraction default_compare_fraction(-1,1);
    find_return = false; // used previously

	// inserting data

    root_fraction.insert(f1);
    root_fraction.insert(f2);
    root_fraction.insert(f3);
    root_fraction.insert(f4);
    root_fraction.insert(f5);

	// printing binary tree in infix order

	cout << endl;
	cout << "Printing binary tree in infix order:" << endl << endl;
	root_fraction.visit(print_fraction);

    // find relevant keys whose data contains a given substring

    cout << endl;
    cout << "Find fraction:" << endl;

    cout << endl;
    cout << "3/2 entered in find function:" << endl;
    search_fraction.set(3,2);
    find_return = root_fraction.find(search_fraction, found_fraction);
    cout << "Truth value returned:" << endl;
    if(root_fraction.find(search_fraction, found_fraction)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "Key found:" << endl;
    if(found_fraction != default_compare_fraction){
        found_fraction.print();
        cout << endl;
    } else {
        cout << found_key << endl;
    }

        // find a second time

    found_fraction.set(-1,1);
    cout << endl;
    cout << "100/3 entered in find function:" << endl;
    search_fraction.set(100,3);
    find_return = root_fraction.find(search_fraction, found_fraction);
    if(found_fraction == default_compare_fraction){
        found_key = "None";
    }
    cout << "Truth value returned:" << endl;
    if(root_fraction.find(search_fraction, found_fraction)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "Key found:" << endl;
    if(found_fraction != default_compare_fraction){
        found_fraction.print();
        cout << endl;
    } else {
        cout << found_key << endl;
    }

	return 0;

}

void print_string(string data){
	cout << data << endl;
}

void print_int(int data){
	cout << data << endl;
}

void print_fraction(fraction data){
	data.print();
}
