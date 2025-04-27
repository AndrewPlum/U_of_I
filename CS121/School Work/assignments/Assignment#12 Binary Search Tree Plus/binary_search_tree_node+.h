    /*
	Andrew Plum
	CS 121-01
	Assignment #12
	4/17/22
	*/

		// I did all of the regular assignment plus 5 points extra credit.

	/* binary_search_tree_node+.h */

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
#include"binary_search_tree_record+.h"
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
        void count_nodes(int &);
        int max_depth();
        //int max_depth(int, int);
        void find_num_strings(string, int &);
        void find_keys(string, string &);
        void erase(); // delete tree function - unecessary
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
    if(left != NULL){
        left->print();
    }
    cout << villager.name << ", ";
    if(right != NULL){
        right->print();
    }
}

void node::count_nodes(int &count){
	if(left != NULL){
		count++;
		left->count_nodes(count);
	}
	if(right != NULL){
		count++;
		right->count_nodes(count);
	}
}

int node::max_depth(){
    if(left == NULL){
        return 0;
    }
    if(right == NULL){
        return 0;
    }
    int l = left->max_depth();
    int r = right->max_depth();
    if(l > r){
        return (l + 1);
    } else {
        return (r + 1);
    }
}

void node::find_num_strings(string search_name, int &num_names){
	if(!villager.data.find(search_name)){ // .find is a string method which searchs for the parameter passed in and returns -1 if the parameter passed in is not found
		num_names++;
	}
	if(left != NULL){
		left->find_num_strings(search_name, num_names);
	}
	if(right != NULL){
		right->find_num_strings(search_name, num_names);
	}
}

void node::find_keys(string search_data, string &rel_keys){
    if(left != NULL){
		left->find_keys(search_data, rel_keys);
	}
	if(right != NULL){
		right->find_keys(search_data, rel_keys);
	}
	if(!villager.data.find(search_data)){
        rel_keys = (rel_keys + ", " + villager.name);
    }
}

void node::erase(){ // delete tree function - unecessary
    if(left != NULL){
        left->erase();
    }
    if(right != NULL){
    	right->erase();
    }
    delete (this);
}
