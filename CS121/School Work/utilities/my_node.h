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
#include<stdlib.h>
using namespace std;

// Node class

class node{
    private:
    public:
    	node *next;
    	entrytype nodedata;
    	node(); // constructor
    	node(const entrytype, node *next = NULL); // constructor with two arguments and next node pointer defaulted to node
    	~node(); // destructor
    	void reverse_print(); // used in link_list reverse_print()
};

node::node(){
    next = NULL;
}

node::node(const entrytype x, node *temp){
    nodedata = x;
	next = temp;
}

node::~node(){ // called in link_list destructor
    if(next != NULL){
    	next->~node();
    }
    free(this);
}

void node::reverse_print(){
	if(next != NULL){
		next->reverse_print();
	}
	cout << nodedata << endl;
}
