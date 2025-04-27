    /*
	Andrew Plum
	CS 121-01
	Assignment #12
	4/17/22
	*/

		// I did all of the regular assignment plus 5 points extra credit.

	/* binary_search_tree_record+.h */

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
using namespace std;

class record{
    public:
        string name;
        string data;
        // Could add these variables later if I want to:
        // string specie;
        // string gender;
        // string personality
        // ...
        // int happiness
    private:
};
