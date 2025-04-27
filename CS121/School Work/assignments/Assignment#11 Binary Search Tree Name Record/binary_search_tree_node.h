    /*
	Andrew Plum
	CS 121-01
	Assignment #11
	4/11/22
	*/

		// I did all of the regular assignment.

	/* binary_search_tree_node.h */

#include<iostream>
#include<string>
#include"binary_search_tree_record.h"
using namespace std;

class node{
    public:
        node* left;
        node* right;
        record villager;
        node();
        void insert(string, string);
        void search(string, string &);
        void print();
        void erase(); // delete - unnecessary for the assignment
    private:
};

node::node(){
    left = right = NULL;
}

void node::insert(string name, string data){
	if(villager.name == name){
		return;
	}
	if(villager.name > name){ // condition for inserting on the left branch
		if(left == NULL){
			left = new node();
			left->villager.name = name;
			left->villager.data = data;
		} else {
			left->insert(name, data);
		}
	}
	if(villager.name < name){ // condition for inserting on the right branch
		if(right == NULL){
		    right = new node();
		    right->villager.name = name;
			right->villager.data = data;
		} else {
			right->insert(name, data);
		}
	}
}

void node::search(string name, string &answer){
	if(villager.name == name){ // found data
		answer = villager.data; // uses pass by reference
		return;
	} else {
		if(left != NULL){ // go left
            left->search(name, answer);
		}
		if(right != NULL){ // go right
			right->search(name, answer);
		}
    }
}

void node::print(){
    cout << villager.name << ", ";
    if(left != NULL){
        left->print();
    }
    if(right != NULL){
        right->print();
    }
}

void node::erase(){ // delete - unnecessary for the assignment
    if(left != NULL){
        left->erase();
    }
    if(right != NULL){
    	right->erase();
    }
    delete (this);
}
