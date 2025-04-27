    /*
	Andrew Plum
	CS 121-01
	Assignment #13
	4/24/22
	*/

		// I did all of the regular assignment.

	/* binary_search_tree++.h */

#include<iostream>
#include<string>
#include"binary_search_tree_node++.h"
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
		void visit(void(* func)(record &, string), string); // new for assignment
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

void tree::visit(void(* func)(record &, string), string name){ // new for assignment
	if(root != NULL){
		root->visit(func, name);
	} else {
		return;
	}
}

