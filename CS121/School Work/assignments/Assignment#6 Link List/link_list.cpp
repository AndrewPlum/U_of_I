    /*
	Andrew Plum
	CS 121-01
	Assignment #6
	2/19/22
	*/

		// I did all of the regular assignment.
		// When reading the output, scroll near the bottom to see where the final list is printed and reverse printed - before that is just output showing the functions are working and affecting the list.

	/* link_list.cpp */

#include<iostream>
typedef int entrytype; // entrytype set to int
#include"node.h"
#include"link_list.h"
using namespace std;

    // *** IMPORTANT: for insert() and remove() the first index of the link list is 1 not 0 ***

int main(){

    // Intro

    cout << endl;
    cout << "This is program which demonstrates how a link list works." << endl;
    cout << endl;

    // Create link list of integers

    link_list my_link_list;

	// Appending all odd numbers from 1 to 19 to link list

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Appending all odd numbers from 1 to 19 to the link list." << endl;
	cout << endl;

	for(int i = 1; i <= 19; i += 2){ // should append 10 elements because 1 and 19 are inclusive
		my_link_list.append(i);
	}

	// Demonstrate pop function and returning error codes

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrating pop function and return error codes." << endl;
	cout << endl;

	int ec; // returned error code
    ec = my_link_list.pop();
	cout << "Error code returned from first pop function: " << ec << endl << endl; // should print 0
	cout << endl;

    // Using the insert function

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Using the insert function." << endl;
	cout << endl;

        // *** IMPORTANT: for the insert() the first index of the link list is 1 not 0 ***
	ec = my_link_list.insert(4,8); // 8 will now be at location 4
	cout << "Error code returned from insert function: " << ec << endl << endl; // should print 0

    // Using the remove function

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Using the remove function." << endl;
	cout << endl;

        // *** IMPORTANT: for the remove() the first index of the link list is 1 not 0 ***
	ec = my_link_list.remove(7); // should remove 7th element which is 13 because list index starts at 1 not 0 like an array
	cout << "Error code returned from remove function: " << ec << endl << endl; // should print 0


	// Appending the number 22 to the link list

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Appending the number 22 to the link list." << endl;
	cout << endl;

    my_link_list.append(22);

    // Demonstrating the find function searching for the value 2 and 15

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrating find function." << endl;
	cout << endl;

	cout << "The find function will return 1 for true and 0 for false" << endl;
	cout << "Is 2 in the link list: ";
	cout << my_link_list.find(2); // should return 0 because 2 is not in the link list
	cout << endl << endl;

	cout << "The find function will return 1 for true and 0 for false" << endl;
	cout << "Is 15 in the link list: ";
	cout << my_link_list.find(15); // should return 1 because 15 is in link list
	cout << endl << endl;

	// Using the print function to print all of the elements in the link list

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Using the print function to print all of the elements in the link list." << endl;
	cout << endl;

	my_link_list.print();
	cout << endl;

	// Using the reverse print function to print all of the elements backwards in the link list

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Using the reverse print function to print all of the elements backwards in the link list." << endl;
	cout << endl;

	my_link_list.reverse_print();
	cout << endl;

	/*
    // Clearing and then printing the list *** ASSIGNMENT DID NOT SAY TO USE IT IN OUTPUT ***

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Using the insert function 3 times and then printing all of the elements in the link list." << endl;
	cout << endl;

    my_link_list.clear();
    cout << "List after clearing it." << endl;
    cout << endl;
	my_link_list.print(); // should be empty

	return 0;
	*/

}
