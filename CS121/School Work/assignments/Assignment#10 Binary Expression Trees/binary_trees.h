    /*
	Andrew Plum
	CS 121-01
	Assignment #10
	3/25/22
	*/

		// I did all of the regular assignment.
		// NOTE: first generation (so the root) is index 0, second generation (root's children) index 1, and so on and so forth - need to know this for the grow function depth

	/* binary_trees.h */

#include<iostream>
#include"binary_trees_node.h"
#include<cstdlib> // srand
#include<ctime>
using namespace std;

enum error_code{success, underflow, overflow};

class tree{
    public:
        tree();
        void grow(int);  // first generation (so the root) is index 0, second generation (root's children) index 1, and so on and so forth
        error_code print();
        double evaluate();
        void clear(); //delete
    private:
        node* root;
};

tree::tree(){
    root = NULL;
}

void tree::grow(int x){ // first generation (so the root) is index 0, second generation (root's children) index 1, and so on and so forth
    root = new node();
    root->grow(x);
}

error_code tree::print(){
    if(root != NULL){
        root->print();
        return success;
    } else {
        return underflow;
    }
}

double tree::evaluate(){
    if(root != NULL){
        return root->evaluate();
    }
}

void tree::clear(){ // delete
    if(root != NULL){
        root->erase();;
        root = NULL;
    }
}
