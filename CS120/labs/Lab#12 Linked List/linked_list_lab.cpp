        /*
        Andrew Plum
        CS 120-06
        Lab #12
        11/17/21
        */

        // I did all of the regular lab assignment; there was no extra credit.

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
    public:
        void setnext(node *n){next = n;} // inline function
        void setdata(string n){name = n;}  // inline function
        void print(); // defined below
        void reverseprint(); // defined below
};

void node::print(){
    cout << name << endl;
    if(next != NULL)
        next -> print();
}

void node::reverseprint(){
    if(next != NULL)
        next -> reverseprint();
    cout << name << endl;
}

int main(){
    int bob_num;
    node *head, *temp;  // pointers to a node object
    temp = new node();  // create a new node object
    temp -> setdata("Sally"); // add data
    temp -> setnext(NULL);  // make the next object Null
    head = temp;           // make head point to the beginning of the list
    temp = new node();  // create another new node object
    temp -> setdata("Fred"); // add data
    temp -> setnext(head); // 'point' the new object to the beginning of the list
    head = temp;          // make head point to the new beginning of the list
    temp = new node();    // repeat
    temp -> setdata("Anne");
    temp -> setnext(head);
    head = temp;
    temp = new node();  // create a new node object
    temp -> setdata("Alan"); // add data
    temp -> setnext(head);  // make the next object Null
    head = temp;
    cout << "Printed forward:" << endl;
    head->print();       // prints the list
    cout << endl;
    cout << "Printed reverse:" << endl;
    head->reverseprint(); // prints the list in reverse order

    // Bob loop

    cout << endl;
    cout << "How many elements in the list do you want to be named Bob:";
    do{
        cin >> bob_num;
        if(bob_num < 0){
            cout << "Enter a reasonable number which is not negative: ";
        }
    }while(bob_num < 0);
    for(int i = 0; i < bob_num; i++){
        temp = new node();      // same method as above of creating new nodes
        temp -> setdata("Bob");// except name them Bob
        temp -> setnext(head);
        head = temp;
    }
    cout << "Printed forward:" << endl;
    head->print();
    cout << endl;
    cout << "Printed reverse:" << endl;
    head->reverseprint();
}
