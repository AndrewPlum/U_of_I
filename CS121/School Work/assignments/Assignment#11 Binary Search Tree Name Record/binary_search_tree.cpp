    /*
	Andrew Plum
	CS 121-01
	Assignment #11
	4/11/22
	*/

		// I did all of the regular assignment.

	/* binary_search_tree.cpp */

#include<iostream>
#include<string>
#include"binary_search_tree.h"
#include<fstream>
using namespace std;

int main(){

    // intro

    cout << endl;
    cout << "This is a program which reads in names from the records.csv file and sorts them into a binary tree." << endl;
    cout << "You can then search for names in the binary tree and if it finds a match, the program will print the data associated with the name." << endl;

    // create tree and variables

    tree root;
    string input;
    string name;
    string data;
    int firstcomma;
    string search_name;
    string answer = "DEFAULT";
    int keep_searching = 1;

	// get info from records.csv and put in binary tree

	ifstream infile;

	infile.open("records.csv");

	while(infile.eof() != true){
		getline(infile,input);
		firstcomma = input.find_first_of(",",0);
		name = input.substr(0,firstcomma);
		data = input.substr(firstcomma + 1);
		root.insert(name,data);
	}

	infile.close();

	// print the names stored in the binary tree

	cout << endl << "Names stored in the binary tree:" << endl;
	root.print();
	cout << endl;

	// search for names stored in the binary tree

	do{
		cout << endl << "Enter name of the person you wish to search for:" << endl;
		getline(cin,search_name);
		if(search_name.empty()){
            keep_searching = 0; // this here is technically unnecessary
            break; // exits the loop if nothing is entered
		}
		root.search(search_name, answer);
		cout << answer << endl;
	}while(keep_searching);

	return 0;

}
