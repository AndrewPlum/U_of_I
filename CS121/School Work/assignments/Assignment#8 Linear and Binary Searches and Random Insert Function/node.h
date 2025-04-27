    /*
    Andrew Plum
    CS 121-01
    Assignment #8
	3/10/22
    */

		// I did all of the regular assignment. Outputs of both programs have data on the speed of the algorithms.

	/* link_list_algorithms.cpp */

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
