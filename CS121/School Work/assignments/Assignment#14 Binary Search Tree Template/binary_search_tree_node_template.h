    /*
	Andrew Plum
	CS 121-01
	Assignment #14
	4/30/22
	*/

        // !!! I have not completed the assignment as of yet. !!!
		// I have completed the template for the binary search tree and its insert, find, and visit function.
		// I have code demonstrating the functions.
		// I demonstrated it with the string, integer, and fraction binary search trees using the templates.
		// I still need to implement the code for it using one more class - I was going to do mixed numbers.


	/* binary_search_tree_node_template.h */

#include<iostream>
#include<string>
using namespace std;

template <typename T>

class node{
    public:
    	T value;
        node<T>* left;
        node<T>* right;
        node();
        void insert(T);
        bool find(T, T &);
		void visit(void (*func)(T));
		void print();
    private:
};

template <typename T>

node<T>::node(){
    left = right = NULL;
}

template <typename T>

void node<T>::insert(T data){
	if(value == data){ // prevets duplicates
		return;
	}
	if(value > data){ // condition for inserting on the left branch
		if(left == NULL){
			left = new node();
			left->value = data;
		} else {
			left->insert(data);
		}
	}
	if(value < data){ // condition for inserting on the right branch
		if(right == NULL){
		    right = new node();
		    right->value = data;
		} else {
			right->insert(data);
		}
	}
}

template <typename T>

bool node<T>::find(T search_key, T &found_key){
    if(value == search_key){
        found_key = value;
        return true;
    }
    if(left != NULL){
		return left->find(search_key, found_key);
	}
	if(right != NULL){
		return right->find(search_key, found_key);
	}
    return false;
}

template <typename T>

void node<T>::visit(void (*func)(T)){
	if(left != NULL){
		left->visit(func);
	}
	func(value);
	if(right != NULL){
		right->visit(func);
	}
}

template <typename T>

void node<T>::print(){
    if(left != NULL){
        left->print();
    }
    cout << value << ", ";
    if(right != NULL){
        right->print();
    }
}
