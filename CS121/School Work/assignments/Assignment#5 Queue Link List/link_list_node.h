    /*
    Andrew Plum
    CS 121-01
    Assignment #5
    2/12/22
    */

		// I did all of the regular assignment.
        // When reading the output, scroll near the bottom to see other queue functionality demonstrated because there are a lot of elements appended.

	/* link_list_queue.h */

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
};

node::node(){
	next = NULL;
}

node::node(const entrytype x, node *temp){
	nodedata = x;
    next = temp;
}

node::~node(){ // called in queue destructor
    if(next != NULL){
        next->~node();
    }
    free(this);
}
