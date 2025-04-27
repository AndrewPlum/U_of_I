    /*
	Andrew Plum
	CS 121-01
	Assignment #13
	4/24/22
	*/

		// I did all of the regular assignment.

	/* binary_search_tree_node++.h */

#include<iostream>
#include<string>
#include"binary_search_tree_record++.h"
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
		void visit(void(* func)(record &, string), string); // new for assignment
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
    int l = 0;
    int r = 0;
    if(left == NULL && right == NULL){
		return 1;
    }
    if(left != NULL){
        l = left->max_depth();
    }
    if(right != NULL){
        r = right->max_depth();
    }
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

void node::visit(void(* func)(record &, string), string name){ // new for assignment
	if(left != NULL){
		left->visit(func, name);
	}
	if(right != NULL){
		right->visit(func, name);
	}
	func(villager, name);
}

