    /*
	Andrew Plum
	CS 121-01
	Assignment #13
	4/24/22
	*/

		// I did all of the regular assignment.

	/* binary_search_tree++.cpp */

        /*
        Note: Most of the new functionality of this file is written at the bottom.
        */

#include<iostream>
#include<string>
#include"binary_search_tree++.h"
#include<fstream>
using namespace std;

void function_1(record &, string); // looks for applicable key
void function_2(record &villager, string search_data); // looks for applicable data



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
		infile.open(chosen_file);
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

	// printing all original names in the binary tree

	cout << endl;
	cout << "Printing all original names in the binary tree:" << endl;
	cout << endl;
	cout << "Names stored in the binary tree:" << endl;
	root.print();
	cout << endl;

	// printing all names in the binary tree after function one is applied

	root.visit(function_1, "Admiral");

	cout << endl;
	cout << "Printing all names in the binary tree after function 1 is applied. It is only applied to the villager named Admiral:" << endl;
	cout << endl;
	cout << "Names stored in the binary tree:" << endl;
	root.print();
	cout << endl;

	// printing all names in the binary tree after function two is applied

	root.visit(function_2, "Cat");

	cout << endl;
	cout << "Printing all names in the binary tree after function 2 is applied. It is only applied to the villagers who are cats:" << endl;
	cout << endl;
	cout << "Names stored in the binary tree:" << endl;
	root.print();
	cout << endl;

	return 0;

}

void function_1(record &villager, string name){
	if(villager.name == name){
		villager.name = villager.name + "_FUNCTION_1_APPLIED!!!";
	}
}

void function_2(record &villager, string search_data){
	if(villager.data.find(search_data) != -1){
		villager.name = villager.name + "_FUNCTION_2_APPLIED!!!";
	}
}
