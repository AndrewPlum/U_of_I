    /*
	Andrew Plum
	CS 121-01
	Assignment #8
	3/10/22
	*/

		// I did all of the regular assignment. Outputs of both programs have data on the speed of the algorithms.

	/* link_list_algorithms.cpp */

#include<iostream>
typedef int entrytype; // entrytype set to int
#include<ctime>
#include"node.h"
#include"link_list_algorithms.h"
using namespace std;

int main(){

    // Intro

    cout << endl;
    cout << "This is program which demonstrates a random insert function for a link list and performs a linear search." << endl;
    cout << endl;

    // Create link list of integers

    link_list my_link_list;

    // Appending all even numbers from 0 to 10 to link list, printing the link list, inserting 3 random elements, printing link list again, and then emptying it

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Appending all even numbers from 0 to 10 to the link list, printing the link list, inserting 3 random elements and sorting them, printing link list again, and then emptying it." << endl;
	cout << endl;

	for(int i = 0; i <= 10; i += 2){
		my_link_list.append(i);
	}

	cout << "Link list before random elements inserted and sorted." << endl;
	my_link_list.print();
	cout << endl;

	my_link_list.insert_sorted(5, 10); // 3 random elements inserted and sorted

	cout << "Link list after random elements inserted and sorted." << endl;
	my_link_list.print();
	cout << endl;

	for(int i = 0; i <= 10; i += 1){
		my_link_list.pop();
	}

	// Appending all even numbers from 0 to 1000 to link list

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Appending all even numbers from 0 to 1000 to the link list." << endl;
	cout << endl;

	for(int i = 0; i <= 1000; i += 2){
		my_link_list.append(i);
	}

	// Timing the linear search function with 501 elements

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Using the linear search function to find an element in a 501 element long link list and timing its execution." << endl;
	cout << endl;

	int search = 1000;
	int result = 10; // set to some arbitrary value which isn't 0 or 1
	cout << "Was " << search << " in the link list(1 for yes and 0 for no): ";
	clock_t t; // create timer
	t = clock(); // start timer
	result = my_link_list.linear_search(search);
	t = clock() - t; // end timer
	cout << result << endl << endl;
	cout << "Time to complete linear search on link list of size " << my_link_list.return_size() << ": " << t << " ms" << endl;
    cout << endl;

    // Appending all even numbers so 0 to 10000 are in the link list

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Appending all even numbers so 0 to 10000 are in the link list" << endl;
	cout << endl;

	for(int i = 1002; i <= 10000; i += 2){
		my_link_list.append(i);
	}

	// Timing the linear search function with 5001 elements

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Using the linear search function to find an element in a 5001 element long link list and timing its execution." << endl;
	cout << endl;

	search = 9999;
	result = 10; // set to some arbitrary value which isn't 0 or 1
	cout << "Was " << search << " in the link list(1 for yes and 0 for no): ";
	t = clock(); // start timer
	result = my_link_list.linear_search(search);
	t = clock() - t; // end timer
	cout << result << endl << endl;
	cout << "Time to complete linear search on link list of size " << my_link_list.return_size() << ": " << t << " ms" << endl;
    cout << endl;

    // Appending all even numbers so 0 to 100000 are in the link list

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Appending all even numbers so 0 to 100000 are in the link list" << endl;
	cout << endl;

	for(int i = 10002; i <= 100000; i += 2){
		my_link_list.append(i);
	}

	// Timing the linear search function with 50001 elements

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Using the linear search function to find an element in a 50001 element long link list and timing its execution." << endl;
	cout << endl;

	search = 100000;
	result = 10; // set to some arbitrary value which isn't 0 or 1
	cout << "Was " << search << " in the link list(1 for yes and 0 for no): ";
	t = clock(); // start timer
	result = my_link_list.linear_search(search);
	t = clock() - t; // end timer
	cout << result << endl << endl;
	cout << "Time to complete linear search on link list of size " << my_link_list.return_size() << ": " << t << " ms" << endl;
    cout << endl;

    return 0;

}
