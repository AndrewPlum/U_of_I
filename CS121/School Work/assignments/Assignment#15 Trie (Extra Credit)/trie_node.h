    /*
	Andrew Plum
	CS 121-01
	Assignment #15
	5/5/22
	*/

		// I did only part of the extra credit assignment

	/* trie_node.h */

        /*
        Note:
        (10 points) An insert function for inserting strings and a print function that will print every string in the trie (useful for debugging)
        (5 points) A find function that returns true if the string is in the trie and false otherwise.
        (5 points) A size function that returns the number of unique strings currently stored in the trie.
        */

#include<iostream>
#include<string>
using namespace std;

const int length = 26;
class trie_node{
    public:
            trie_node *children[length];
            bool endofstring;
            trie_node();
            void insert(string);
            void insert(const char [], int, int);
            void print();
            bool find(string, int );
            int count();
            //entrytype data;
	private:
};

trie_node::trie_node(){
    for(int i = 0; i < length; i++){
        children[i] = NULL;
    }
    endofstring = false;
}

void trie_node::insert(string s){
    insert(s.c_str(), s.length(), 0);
}

void trie_node::insert(const char str[], int len, int d){ // d is the depth and the location in the string
    int loc;
    loc = int(str[d] - 97);
//    if(str[d] == 'a'){
//        loc = 0;
//    }
    if(len == d){
        endofstring = true;
        return;
    }
    if(children[loc] == NULL){
        children[loc] = new trie_node();
    }
    children[loc]->insert(str, len, d + 1);
}

void trie_node::print(){
    if(endofstring){
        cout << endl;
    }
    for(int i = 0; i < length; i++){
        if(children[i] != NULL){
            cout << char(i + 97) << " ";
            children[i]->print();
        }
    }
}

bool trie_node::find(string target, int d){
    if(d == target.length() && endofstring){
        return true;
    }
    int loc;
    loc = int(target[d] - 97);
    if(children[loc] == NULL){
        return false;
    } else {
        return children[loc]->find(target, d + 1);
    }
}

int trie_node::count(){
    int c = 0;
    if(endofstring == true){
        c++;
    }
    for(int i = 0; i < length; i++){
        if(children[i] != NULL){
            c = c + children[i]->count();
        }
    }
    return c;
}

//letters[i] += c;
