        /*
        Andrew Plum
        CS 120-06
        Lab #13
        11/29/21
        */

        // I did all of the regular lab assignment; there was no extra credit.

        /*
        This is a header file to a simple program which uses linked lists.
        */

// First Define a node class, then define a linked list class
class node{
    private:
        node *next;
        string name;
    public:
        void setnext(node *n){next = n;} // inline function
        void setdata(string n){name = n;}  // inline function
        void print(); // defined below
        void clear();
        void reverseprint(); // new function
        string getdata(); // new function
        node* getnext(); // new function
        string pop(); // new function
};

void node::clear(){
    if(next != NULL)
        next -> clear();
    delete this;
}

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

string node::getdata(){
    return name;
}

node* node::getnext(){
    return next;
}

string node::pop(){
    return getdata(); // getdata() function demonstrated
}

// Definition of the linked list class

class linkedlist{
    private:
        node *head;
        int len;
    public:
        linkedlist();
        void push(node *);
        void print();
        void clear();
        void reverseprint(); // new function
        string pop(); // new function
};

linkedlist::linkedlist(){ // constructor
    head = NULL;
    len = 0;
}

void linkedlist::push(node *n){
    n->setnext(head);
    head = n;
    len = len + 1;
}

void linkedlist::print(){
    if(head != NULL){
        head -> print();
    }
}

void linkedlist::clear(){
    if(head != NULL){
        head-> clear();
    }
    head = NULL;
    len = 0;
}

void linkedlist::reverseprint(){
    if(head != NULL){
        head -> reverseprint();
    }
}

string linkedlist::pop(){
    if(head != NULL){
        string name;
        node *temp;
        name = head -> pop();
        temp = head -> getnext();
        delete head;
        len -= 1; // decrement length because we are erasing an element from the list
        head = temp;
        return name;
    } else {
    	return "";
    }
}
