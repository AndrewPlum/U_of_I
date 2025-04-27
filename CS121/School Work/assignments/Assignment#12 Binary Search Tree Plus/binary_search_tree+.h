    /*
	Andrew Plum
	CS 121-01
	Assignment #12
	4/17/22
	*/

		// I did all of the regular assignment plus 5 points extra credit.

	/* binary_search_tree+.h */

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
#include"binary_search_tree_node+.h"
using namespace std;

enum error_code{success, underflow, overflow};

class tree{
    public:
        tree();
        void insert(string, string);
        void search(string, string &);
        void print();
        void count_nodes(int &);
        void max_depth(int &);
        void find_num_strings(string, int &);
        void find_keys(string, string &);
        void clear(); // delete tree function - unecessary
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

void tree::count_nodes(int &count){
	count = 0;
	if(root != NULL){
		count++;
		root->count_nodes(count);
	} else {
		return;
	}
}

void tree::max_depth(int &max_d){
	max_d = 0;
	if(root != NULL){
		max_d = root->max_depth();
	} else {
		return;
	}
}

void tree::find_num_strings(string search_name, int &num_names){
	num_names = 0;
	if(root != NULL){
		root->find_num_strings(search_name, num_names);
	} else {
		return;
	}
}

void tree::find_keys(string search_name, string &rel_keys){
    if(root != NULL){
        rel_keys = "";
        root->find_keys(search_name, rel_keys);
    } else {
        rel_keys = "None";
        return;
    }
}

void tree::clear(){ // delete tree function - unecessary
    if(root != NULL){
        root->erase();
        root = NULL;
    }
}
