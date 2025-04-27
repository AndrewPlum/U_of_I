/*
Andrew Plum
Professor Wilder
CS 240
11/19/2022
*/

    /*
    ***Assignment #4 - ksim_link_list_node.h***
    */

#include<stdlib.h>
#include<string.h>

// Node class

class node{
    private:
    public:
		node *next;
		char *name;
		int initial_blocked_tick_time;
    	node(); // constructor
		node(char *, node *next = NULL); // constructor with two arguments and next node pointer defaulted to node
    	~node(); // destructor
};

node::node(){
    next = NULL;
	strcpy(name, "");
	initial_blocked_tick_time = -1;
}

node::node(char *x, node *temp){
	name = (char *) malloc((strlen(x) + 1) * sizeof(char));
	strcpy(name, x);
	initial_blocked_tick_time = -1;
	next = temp;
}

node::~node(){ // called in link_list destructor
    if(next != NULL){
    	next->~node();
    }
    free(this);
}
