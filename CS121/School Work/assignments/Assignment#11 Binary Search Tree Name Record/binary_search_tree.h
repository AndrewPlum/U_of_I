    /*
	Andrew Plum
	CS 121-01
	Assignment #11
	4/11/22
	*/

		// I did all of the regular assignment.

	/* binary_search_tree.h */

#include<iostream>
#include<string>
#include"binary_search_tree_node.h"
using namespace std;

enum error_code{success, underflow, overflow};

class tree{
    public:
        tree();
        void insert(string, string);
        void search(string, string &);
        void print();
        void clear(); // delete - unnecessary for the assignment
    private:
        node* root;
};

tree::tree(){
    root = NULL;
}

void tree::insert(string name, string data){
	if(root == NULL){
		root = new node();
		root->villager.name = name;
		root->villager.data = data;
	}else{
	    root->insert(name, data);
	}
}

void tree::search(string name, string &answer){
	if(root != NULL){
        answer = "";
		root->search(name, answer);
		if(answer == ""){
			answer = name + " not found.";
		} else {
			return;
		}
	}
}

void tree::print(){
    if(root != NULL){
        root->print();
    }
}

void tree::clear(){ // delete - unnecessary for the assignment
    if(root != NULL){
        root->erase();
        root = NULL;
    }
}
