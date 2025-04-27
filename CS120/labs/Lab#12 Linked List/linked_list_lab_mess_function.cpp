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
     node *previous;
     string name;
   public:
     void setnext(node *n){next = n;} // inline function
     void setprevious(node *n){previous = n;} // inline function
     void setdata(string n){name = n;}  // inline function
     void print(); // defined below
     void reverseprint(); // defined below
};

void node::print(){

   if(next != NULL)
      next -> print();
    cout << name << endl;
}

void node::reverseprint(){
    cout << name << endl;
    if(previous != NULL)
        previous -> print();
}

int main(){
  node *head, *temp, *tail, *temp2;  // pointers to a node object
  temp = temp2 = new node();  // create a new node object
  temp -> setdata("Sally"); // add data
  temp -> setnext(NULL);  // make the next object Null
  temp2 -> setprevious(tail);  // point to the previous object
  head = temp;           // make head point to the beginning of the list
  tail = temp2;
  temp = new node();  // create another new node object
  temp -> setdata("Fred"); // add data
  temp -> setnext(head); // 'point' the new object to the beginning of the list
  temp2 -> setprevious(tail);  // point to the tail, the previous object
  head = temp;          // make head point to the new beginning of the list
  tail = temp2;
  temp = new node();    // repeat
  temp -> setdata("Anne");
  temp -> setnext(head);
  temp2 -> setprevious(tail);  // point to the tail, the previous object
  head = temp;
  tail = temp2;
  temp = new node();  // create a new node object
  temp -> setdata("Alan"); // add data
  temp -> setnext(head);  // make the next object Null
  temp2 -> setprevious(NULL);  // point to the tail, the previous object
  head = temp;
  tail = temp2;
  head->print();       // print the list
  tail->reverseprint();     // print the list in reverse order
}
