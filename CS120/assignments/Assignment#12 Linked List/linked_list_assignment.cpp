        /*
        Andrew Plum
        CS 120-06
        Assignment #12
        11/17/21
        */

        // I did all of the regular assignment; there was no extra credit.

        /*
        This is a simple program which uses linked lists.
        */

#include<iostream>
#include<string>
using namespace std;

class node{
    private:
        node *next;
        string name;
        int ID;
        char initial;
    public:
        void setnext(node *n){next = n;} // inline function
        void setdata(string n, int id, char c){name = n; ID = id; initial = c;}  // inline function
        void print(); // defined below
        void reverseprint(); // defined below
        void append(node*);
        int length();
        void clear();
};

void node::print(){
    cout << name << ", " << ID << ", " << initial << endl;
    if(next != NULL){
        next -> print();
    }
}

void node::reverseprint(){
    if(next != NULL){
        next -> reverseprint();
    }
    cout << name << ", " << ID << ", " << initial << endl;
}

void node::append(node *new_node){
    if(next != NULL){
        next -> append(new_node);
    }
    if(next == NULL){
        next = new_node;
    }
}

int node::length(){
    static int counter = 0;
    int ret_val;
    if(next != NULL){
        counter++;
        next -> length();
    } else {
    	counter++;
    	ret_val = counter;
    	counter = 0;
    	return ret_val;
    }
}

void node::clear(){
	if(next != NULL){
		next -> clear();
	}
	delete this;
}

int main(){
    int bob_num;
    node *head, *temp;  // pointers to a node object
    temp = new node();  // create a new node object
    temp -> setdata("Sally", 7, 'R'); // add data
    temp -> setnext(NULL);  // make the next object Null
    head = temp;           // make head point to the beginning of the list
    temp = new node();  // create another new node object
    temp -> setdata("Fred", 13, 'Q'); // add data
    temp -> setnext(head); // 'point' the new object to the beginning of the list
    head = temp;          // make head point to the new beginning of the list
    temp = new node();    // repeat
    temp -> setdata("Anne", 14, 'W');
    temp -> setnext(head);
    head = temp;
    temp = new node();  // create a new node object
    temp -> setdata("Alan", 17, 'G'); // add data
    temp -> setnext(head);  // make the next object Null
    head = temp;
    cout << "Printed forward:" << endl;
    head->print();       // prints the list
    cout << endl;
    cout << "Printed reverse:" << endl;
    head -> reverseprint(); // prints the list in reverse order

    // Bob loop from lab
/*
    cout << endl;
    cout << "How many elements in the list do you want to be named Bob: ";
    do{
        cin >> bob_num;
        if(bob_num < 0){
            cout << "Enter a reasonable number which is not negative: ";
        }
    }while(bob_num < 0);
    for(int i = 0; i < bob_num; i++){
        temp = new node();      // same method as above of creating new nodes
        temp -> setdata("Bob", 10, 'C');// except name them Bob
        temp -> setnext(head);
        head = temp;
    }
    cout << "Printed forward:" << endl;
    head -> print();
    cout << endl;
    cout << "Printed reverse:" << endl;
    head -> reverseprint();
*/
    // Append function

    temp = new node();
    temp -> setdata("John", 25, 'E'); // add data
    temp -> setnext(NULL);  // make the next object Null
    head -> append(temp);
	cout << endl;
    cout << "Printed forward:" << endl;
    head -> print();
    cout << endl;
	cout << "Printed reverse:" << endl;
	head -> reverseprint();

    // Length function

	cout << endl;
    cout << "Number of nodes in list: ";
    cout << head -> length();
	cout << endl;

	// Clear function - NOT PRINTED IN OUTPUT

	head -> clear();
}
