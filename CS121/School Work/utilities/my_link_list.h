    /*
    Andrew Plum
    CS 121-01
    Assignment #6
    2/19/22
    */

		// I did all of the regular assignment.
        // When reading the output, scroll near the bottom to see where the final list is printed and reverse printed - before that is just output showing the functions are working and affecting the list.

	/* link_list.cpp */

#include<iostream>
#include<stdlib.h>
using namespace std;

enum error_code{success, fail, overflow, underflow}; // succes:0 fail:1 overflow 2 underflow 3

// Link list class

class link_list{
    private:
        node *first;
        node *back;
        int size;
    public:
        link_list();  // constructor
 		~link_list(); // destructor
        error_code append(const entrytype); // puts element at the end of the link list
        error_code front(entrytype&);
        error_code pop(); // takes first element out of the link list
        int return_size();
        bool find(const entrytype);
        void print();
		void reverse_print();
		error_code insert(int, entrytype);
        error_code remove(int);
        void clear();
        bool empty(); // not needed for the assignment
};

link_list::link_list(){
    size = 0;
    first = NULL;
    back = NULL;
}

link_list::~link_list(){
	if(first != NULL){
		first->~node(); //check
	}
}

error_code link_list::append(const entrytype c){
    error_code ec = success;
    if(size == 0){ // if empty
    	node *temp = new node(c);
    	first = back = temp;
    	size++;
   		cout << "Element successfully appended into link list!" << endl;
    	cout << "Link list size: " << size << endl;
    	cout << endl;
    } else {
    	node *temp = new node(c);
    	back->next = temp;
    	back = temp;
    	size++;
   		cout << "Element successfully appended into link list!" << endl;
    	cout << "Link list size: " << size << endl;
    	cout << endl;
    }
    return ec;
}

error_code link_list::front(entrytype &data){
    error_code ec = success;
    if(size > 0){
        data = first->nodedata;
        return ec;
    } else {
        ec = underflow;
        cout << "Underflow error!" << endl;
        cout << "Link list size: " << size << endl;
        cout << endl;
    }
    return ec;
}

error_code link_list::pop(){
    error_code ec = success;
    if(!empty()){
        node *temp = first;
    	first = first->next;
    	free(temp);
 		size--;
        cout << "Element successfully popped from link list!" << endl;
        cout << "Link list size: " << size << endl;
        cout << endl;
    } else {
        ec = underflow;
        cout << "Underflow error!" << endl;
        cout << "Link list size: " << size << endl;
        cout << endl;
    }
    return ec;
}

int link_list::return_size(){
	return size;
}

bool link_list::find(const entrytype x){
	node *p = first;
	while(p != NULL){
		if(p->nodedata == x){
			return true;
		}
		p = p->next;
	}
	return false;
}

void link_list::print(){
	node *p = first;
	while(p != NULL){
		cout << p->nodedata << endl;
		p = p-> next;
	}
}

void link_list::reverse_print(){
	if(first != NULL){
		first->reverse_print();
	}
}

// Note: inserts no matter what the index - will insert at the front if under, back if index is over, and in between where its supposed to if index is in between
error_code link_list::insert(int index, entrytype data){ // *** the first index is of the link list 1 and the function also inserts if there is an underflow or overflow because that wasn't fully clarified in the assignment ***
    error_code ec = success;
    if(first == NULL){ // if list is empty and index could be equal to anything
        ec = overflow;
        node *temp = new node(data);
    	first = back = temp;
    	size++;
    	cout << "Overflow error and link list was empty but still inserted at front!" << endl;
        cout << "Link list size: " << size << endl;
        cout << endl;
    	return ec;
    }
    if((first != NULL) && (index <= 0)){ // if list is not empty and index is less than or equal to 0
        ec = overflow;
        node *temp = new node(data);
    	temp->next = first;
    	first = temp;
    	size++;
    	cout << "Overflow error but still inserted at front!" << endl;
        cout << "Link list size: " << size << endl;
        cout << endl;
    	return ec;
    }
    if((first != NULL) && (index > size)){ // if list is not empty and index is greater than list size
        ec = underflow;
        node *temp = new node(data);
    	back->next = temp;
    	back = temp;
    	size++;
    	cout << "Underflow error but still inserted at back!" << endl;
        cout << "Link list size: " << size << endl;
        cout << endl;
    	return ec;
    }
    if((first != NULL) && ((index <= size) && (index > 0))){ // if list is not empty and index is equal or less than list size but also greater than 0
        node *temp = new node(data);
        node *curr = first;
        node *prev;
        while(index > 1){
            if(index == 2){
                prev = curr; // store previous node
            }
            curr = curr->next;
            index--;
        }
        prev->next = temp; // set previous next to equal the temp pointer
        temp->next = curr; // set inserted node to the one after previous
        size++;
        cout << "Element successfully inserted into link list!" << endl;
    	cout << "Link list size: " << size << endl;
    	cout << endl;
        return ec; // should return success
    }
    ec = fail; // 1
    return ec;
}

// Note: removes if list is not empty no matter what the index - will remove from the front if the index is under, back if the index is over, and in between where its supposed to if the index is in between
error_code link_list::remove(int index){ // *** the first index of the link list is 1 and the function also inserts if there is an underflow and overflow because that wasn't fully clarified in the assignment ***
    error_code ec = success;
    if(first == NULL){ // if list is empty and index could be equal to anything
        ec = overflow;
    	cout << "Overflow error and link list was empty so nothing was removed!" << endl;
        cout << "Link list size: " << size << endl;
        cout << endl;
    	return ec;
    }
    if((first != NULL) && (index <= 0)){ // if list is not empty and index is less than or equal to 0
        ec = overflow;
        node *temp = first;
    	first = first->next;
    	free(temp);
 		size--;
    	cout << "Overflow error but still removed first element!" << endl;
        cout << "Link list size: " << size << endl;
        cout << endl;
    	return ec;
    }
    if((first != NULL) && (index > size)){ // if list is not empty and index is greater than list size
        ec = underflow;
        node *temp = first;
        node *temp2 = back;
    	while(temp->next->next != back){ // point to the node that points to the node that points to NULL
            temp = temp->next;
    	}
    	temp->next = NULL;
    	back = temp;
    	free(temp2);
    	size--;
    	cout << "Underflow error but still removed last element!" << endl;
        cout << "Link list size: " << size << endl;
        cout << endl;
    	return ec;
    }
    if((first != NULL) && ((index <= size) && (index > 0))){ // if list is not empty and index is equal or less than list size but also greater than 0
        node *curr = first;
        node *prev;
        while(index > 1){
            if(index == 2){
                prev = curr; // store previous node
            }
            curr = curr->next;
            index--;
        }
        prev->next = curr->next; // set previous next to equal the temp pointer
        free(curr); // set inserted node to the one after previous
        size--;
        cout << "Element successfully removed from link list!" << endl;
    	cout << "Link list size: " << size << endl;
    	cout << endl;
        return ec; // should return success
    }
    ec = fail; // 1
    return ec;
}

void link_list::clear(){
    while(first != NULL){
        pop();
    }
}

bool link_list::empty(){ // not needed for the assignment
    if(size == 0){
        return true;
    }
    return false;
}
