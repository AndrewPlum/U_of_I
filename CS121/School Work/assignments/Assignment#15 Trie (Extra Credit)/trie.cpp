    /*
	Andrew Plum
	CS 121-01
	Assignment #15
	5/5/22
	*/

		// I did only part of the extra credit assignment

	/* trie.cpp */

        /*
        Note:
        (10 points) An insert function for inserting strings and a print function that will print every string in the trie (useful for debugging)
        (5 points) A find function that returns true if the string is in the trie and false otherwise.
        (5 points) A size function that returns the number of unique strings currently stored in the trie.
        */

#include<iostream>
#include<string>
#include"trie_node.h"
using namespace std;

int main(){

    // intro

    cout << "This is a program which demonstrates tries and some of their functionality." << endl;

    // create trie

    trie_node root;

    // create variables

    string search_data = "DEFUALT";

    // insert data into trie

    root.insert("bob");
    root.insert("bobby");
    root.insert("bot");
    root.insert("bog");
    root.insert("boggy");
    root.insert("zeldon");
    root.insert("carl");
    root.insert("fredrickson");

    // print trie

    cout << endl;
    cout << "Printing trie using the print function after inserting data:" << endl ;
    root.print();
    cout << endl;

    // find data in tree/

    cout << "Using the find function to search for data in the trie:" << endl;

    search_data = "bob";
    cout << "Searching for " << search_data << ":" << endl;
   	if(root.find(search_data, 0)){
   		cout << "Found " << search_data << "." << endl;
   	} else {
        cout << search_data << " not found." << endl;
   	}

   	search_data = "tom";
   	cout << "Searching for " << search_data << ":" << endl;
   	if(root.find(search_data, 0)){
   		cout << "Found " << search_data << "." << endl;
   	} else {
        cout << search_data << " not found." << endl;
   	}

   	search_data = "zeldon";
   	cout << "Searching for " << search_data << ":" << endl;
   	if(root.find(search_data, 0)){
   		cout << "Found " << search_data << "." << endl;
   	} else {
        cout << search_data << " not found." << endl;
   	}

   	search_data = "george";
   	cout << "Searching for " << search_data << ":" << endl;
   	if(root.find(search_data, 0)){
   		cout << "Found " << search_data << "." << endl;
   	} else {
        cout << search_data << " not found." << endl;
   	}

   	// count number of unique strings in the trie

    cout << endl;
    cout << "Counting the number of unique strings in the trie using the count function:" << endl;
    cout << "There are " << root.count() << " unique strings in the trie." << endl;

    // printing and counting the number of unique strings in the trie after adding two unique strings

    root.insert("james");
    root.insert("harry");

    cout << endl;
    cout << "Printing trie using the print function after inserting two unique strings:" << endl ;
    root.print();
    cout << endl;

    cout << endl;
    cout << "Counting the number of unique strings in the trie using the count function after inserting two unique strings:" << endl;
    cout << "There are " << root.count() << " unique strings in the trie." << endl;


}
