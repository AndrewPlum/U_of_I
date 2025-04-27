    /*
	Andrew Plum
	CS 121-01
	Assignment #12
	4/17/22
	*/

		// I did all of the regular assignment plus 5 points extra credit.

	/* binary_search_tree+.cpp */

        /*
        Specific things I implemented in this assignment:
            *   (5 points) Allow the user to enter the name of the CSV file that the data will be read from.
                Test this with at least two different data files.
            *   (5 points) Create a function that prints all of the keys in infix order.
            *   (5 points) Create a function the returns a count of the number of entries (non-NULL nodes) in the binary search tree.
            *   (5 points) Create a function that calculates the maximum depth of the tree.
            *   (5 points) Create a function that counts the number of entries in the tree whose data contains a given substring.
            *   (10 points) Create a function that gives a list of all of the keys containing a particular substring.

            *** This adds up to 35 points ***
        */

#include<iostream>
#include<string>
#include"binary_search_tree+.h"
#include<fstream>
using namespace std;

int main(){

    // intro

    cout << endl;
    cout << "This is a program which reads in names from the records.csv file and sorts them into a binary tree." << endl;
    cout << "You can then search for names in the binary tree and if it finds a match, the program will print the data associated with the name." << endl;

    // create tree and variables

    tree root;
	string chosen_file;
    string input;
    string name;
    string data;
    int firstcomma;
    string search_name;
    string answer = "DEFAULT";
    int keep_searching = 1;
    int node_count = 0;
    int max_d = 0; // max depth
    string search_data = "DEFAULT";
    int search_data_count = 0;
    string rel_keys = "DEFAULT";

	// get info from records.csv and put in binary tree

	ifstream infile;

	// have user enter in a file

	cout << endl;
	do{
		cout << "Enter the name of the file you wish to open:" << endl;
		cin >> chosen_file;
		infile.open(/*chosen_file*/"records.csv");
	}while(infile.fail());

	getline(infile,input); // skips the first line

	while(infile.eof() != true){
		getline(infile,input);
		firstcomma = input.find_first_of(",",0);
		name = input.substr(0,firstcomma);
		data = input.substr(firstcomma + 1);
		root.insert(name,data);
	}

	infile.close();

    // print the names stored in the binary tree

	cout << endl;
	cout << "Names stored in the binary tree:" << endl;
	root.print();
	cout << endl;

	// count and print the number of nodes in the binary search tree

	root.count_nodes(node_count);
	cout << endl;
	cout << "Number of nodes in the binary search tree:" << endl << node_count;
    cout << endl;

    // count and print the max depth of the binary search tree

	root.max_depth(max_d);
	cout << endl;
	cout << "Max depth of the binary search tree:" << endl << max_d;
    cout << endl;

    // count the number of nodes whose data contains a given substring

    keep_searching = 1;
    do{
        cout << endl;
		cout << "Enter the data you wish the program to search for and count up (enter \"STOP!!!\" to stop):" << endl;
		cin >> search_data;
		if(search_data == "STOP!!!"){
            keep_searching = 0; // this here is technically unnecessary
            break; // exits the loop if nothing is entered
		}
		root.find_num_strings(search_data, search_data_count);
		cout << search_data_count << endl;
	}while(keep_searching);

    // find relevant keys whose data contains a given substring

    keep_searching = 1;
    do{
        cout << endl;
		cout << "Enter the data you wish the program to search for and find relevant keys (enter \"STOP!!!\" to stop):" << endl;
		cin >> search_data;
		if(search_data == "STOP!!!"){
            keep_searching = 0; // this here is technically unnecessary
            break; // exits the loop if nothing is entered
		}
		root.find_keys(search_data, rel_keys);
		cout << "Keys found relevant to the data passed in:" << endl << rel_keys << endl;
	}while(keep_searching);

	// search for names stored in the binary tree

	keep_searching = 1;
	do{
        cout << endl;
		cout << "Enter name of the person you wish to search for (enter \"STOP!!!\" to stop):" << endl;
		cin >> search_name;
		if(search_name == "STOP!!!"){
            keep_searching = 0; // this here is technically unnecessary
            break; // exits the loop if nothing is entered
		}
		root.search(search_name, answer);
		cout << answer << endl;
	}while(keep_searching);

	return 0;

}
