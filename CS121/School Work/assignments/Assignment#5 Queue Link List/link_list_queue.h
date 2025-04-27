    /*
    Andrew Plum
    CS 121-01
    Assignment #5
    2/12/22
    */

		// I did all of the regular assignment.
        // When reading the output, scroll near the bottom to see other queue functionality demonstrated because there are a lot of elements appended.

	/* link_list_queue.h */

#include<iostream>
#include<stdlib.h>
using namespace std;

enum error_code{success, fail, overflow, underflow}; // success:0 fail:1 overflow 2 underflow 3

// Queue class

class queue{
    private:
        node *first; // first in line to leave queue - so first will point to the node whose next pointer points to NULL
        node *back; // last in line to leave queue - thinking this way of back and front helped me when writing the program
        int size;
    public:
        queue();  // constructor
 		~queue(); // destructor
        error_code append(const entrytype); // we were told that we did not need to do the overflow error case by the way for the append function
        error_code front(entrytype&);
        error_code pop();
        int return_size();
        bool find(const entrytype);
        bool empty(); // not needed for the assignment
		void print(); // not needed for the assignment
};

queue::queue(){
    size = 0;
    first = NULL;
    back = NULL;
}

queue::~queue(){
	if(first != NULL){
		back->~node();
	}
}

error_code queue::append(const entrytype c){
    error_code ec = success;
    if(size == 0){ // if empty
    	node *temp = new node(c);
    	first = back = temp;
    	size++;
   		cout << "Element successfully appended into queue!" << endl;
    	cout << "Queue size: " << size << endl;
    	cout << endl;
    } else {
    	node *temp = new node(c, back);
    	back = temp;
    	size++;
   		cout << "Element successfully appended into queue!" << endl;
    	cout << "Queue size: " << size << endl;
    	cout << endl;
    }
    return ec;
}

error_code queue::front(entrytype &data){
    error_code ec = success;
    if(size > 0){
        data = first->nodedata;
        return ec;
    } else {
        ec = underflow;
        cout << "Underflow error!" << endl;
        cout << "Queue size: " << size << endl;
        cout << endl;
    }
    return ec;
}

error_code queue::pop(){
    error_code ec = success;
    if(!empty()){

        // first method - not chosen

        /*
        node *temp = first;
    	first = first->next;
    	free(temp);
 		size--;
 		*/

 		// second method - chosen

 		node *curr = back; // current
 		node *prev = back; // previous
 		while(curr != first){ // have curr and first point to the same thing and prev point to the one before curr
 			curr = curr->next;
 			if(curr != first){
 				prev = prev->next;
 			}
 		}
 		first = prev; // the new first will point to the node previous is pointed to
 		free(curr);
 		first->next = NULL;
 		size--;

        cout << "Element successfully popped from queue!" << endl;
        cout << "Queue size: " << size << endl;
        cout << endl;
    } else {
        ec = underflow;
        cout << "Underflow error!" << endl;
        cout << "Queue size: " << size << endl;
        cout << endl;
    }
    return ec;
}

int queue::return_size(){
	return size;
}

bool queue::find(const entrytype x){
	node *p = back;
	while(p != NULL){
		if(p->nodedata == x){
			return true;
		}
		p = p->next;
	}
	return false;
}

bool queue::empty(){ // not needed for the assignment
    if(size == 0){
        return true;
    }
    return false;
}

void queue::print(){ // not needed for the assignment
	cout << "\nPrinting from front of list\n";
	node *p = back;
	while(p != NULL){
		cout << p->nodedata << endl;
		p = p-> next;
	}
}
