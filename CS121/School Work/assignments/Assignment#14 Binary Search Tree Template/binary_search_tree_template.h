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


	/* binary_search_tree_template.h */

#include<iostream>
#include<string>
#include"binary_search_tree_node_template.h"
using namespace std;

template <typename T>

class tree{
    public:
		node<T>* root;
        tree();
        void insert(T);
        bool find(T, T &);
		void visit(void (*func)(T));
        void print();
    private:
};

template <typename T>

tree<T>::tree(){
    root = NULL;
}

template <typename T>

void tree<T>::insert(T data){
	if(root == NULL){
		root = new node<T>();
		root->insert(data);
	}else{
	    root->insert(data);
	}
}

template <typename T>

 bool tree<T>::find(T search_key, T &found_key){
    if(root != NULL){
        return root->find(search_key, found_key);
    } else {
        return false;
    }
}

template <typename T>

void tree<T>::visit(void (*func)(T)){
	if(root != NULL){
		root->visit(func);
	}
}

template <typename T>

void tree<T>::print(){
    if(root != NULL){
        root->print();
    }
}
