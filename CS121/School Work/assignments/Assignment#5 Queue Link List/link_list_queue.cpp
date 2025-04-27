    /*
	Andrew Plum
	CS 121-01
	Assignment #5
	2/12/22
	*/

		// I did all of the regular assignment.
		// When reading the output, scroll near the bottom to see other queue functionality demonstrated because there are a lot of elements appended.

	/* link_list_queue.cpp */

#include<iostream>
typedef int entrytype; // entrytype set to int
#include"link_list_node.h"
#include"link_list_queue.h"
using namespace std;

int main(){

    // Intro

    cout << endl;
    cout << "This is program which demonstrates how a queue using a link list works." << endl;
    cout << endl;

    // Create queue of integers

    queue my_queue;

	// Appending all even numbers from 8 to 398 to queue

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Appending all even numbers from 8 to 398 to the queue." << endl;
	cout << endl;

	for(int i = 8; i <= 398; i += 2){ // should append 196 elements because 8 and 398 are inclusive
		my_queue.append(i);
	}

	// Demonstrate front function

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrating front function." << endl;
	cout << endl;

	entrytype x;
	my_queue.front(x);
	cout << "Data at the front of the queue: " << x << endl;
	cout << endl;

	// Demonstrate pop function 2 times and returning error codes

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrating pop function 2 times and return error codes." << endl;
	cout << endl;

	int ec; // returned error code
    ec = my_queue.pop();
	cout << "Error code returned from first pop: " << ec << endl << endl; // should print 0
	ec = my_queue.pop();
	cout << "Error code returned from second pop: " << ec << endl << endl; // should print 0
	cout << endl;

	// Demonstrating the find function searching for the value 8 and 200

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrating find function." << endl;
	cout << endl;

	cout << "The find function will return 1 for true and 0 for false" << endl;
	cout << "Is 8 in the queue: ";
	cout << my_queue.find(8); // should return 0 because 8 was popped from the queue
	cout << endl << endl;

	cout << "The find function will return 1 for true and 0 for false" << endl;
	cout << "Is 200 in the queue: ";
	cout << my_queue.find(200); // should return 1 because 200 is in queue still
	cout << endl << endl;

	// Demonstrate size function

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrating size function." << endl;
	cout << endl;

	cout << "Current size of queue: ";
	cout << my_queue.return_size(); // size should be 194
	cout << endl << endl;

	// Looping the pop function 10 times and reporting the size of the queue after 10 pops

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrating pop function 10 times and reporting queue size afterwards." << endl;
	cout << endl;

	for(int i = 0; i < 10; i++){
		my_queue.pop();
	}
	cout << "Current size of queue: ";
	cout << my_queue.return_size(); // size should be 184
	cout << endl << endl;

	// Using front function to print the value of the new first element of the queue

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Using front function to print the value of the new first element of the queue." << endl;
	cout << endl;

	my_queue.front(x); // should print 32
	cout << "Data at the front of the queue: " << x << endl;
	cout << endl;

	return 0;
}
