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
     	string getdata(); // new function
     	void append(node *); // new function
		int find(string); // new function
		string get(int); // new function
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

string node::getdata(){
	return name;
}

void node::append(node *n){
    static node *curr;
	if(next != NULL){
		curr = next;
		next -> append(n);
	} else {
		curr -> setnext(n);
	}
}

int node::find(string s){
	if(name == s){
	        return 1;
	}
	if(next != NULL){
		if(next -> find(s) == 1){ // check to see if next name matches the input
			return 1;
		}
	}
	return 0;
}

string node::get(int n){
	static string temp = "";
	if(n != 0){
		n--;
		next -> get(n);
	}
	else{
		temp = name;
	}
	return temp;
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
     	int length(); // new function
     	void append(node *); // new function
		int find(string); // new function
		string get(int); // new function
};

linkedlist::linkedlist(){ // constructor
   	head = NULL;
   	len = 0;
}

void linkedlist::push(node *n){
  	n->setnext(head);
  	head = n;
  	len += 1;
}

void linkedlist::print(){
  	if(head != NULL){
     	head -> print();
  	}
}

void linkedlist::clear(){
  	if(head != NULL){
     	head -> clear();
  	}
  	head = NULL;
  	len = 0;
}

int linkedlist::length(){
	return len;
}

void linkedlist::append(node *n){
    n -> setnext(NULL);
	if(head != NULL){
		head -> append(n);
		len += 1;
	} else {
		len = 1; // only one element in list now
		head = n;
		head -> setnext(NULL);
	}
}

int linkedlist::find(string s){
	if(head != NULL){
		return head -> find(s);
	} else {
        return 0; // if nothing is in list return 0 because the name is not in the list
	}
}

string linkedlist::get(int n){
	if(head != NULL){
		if(n > (len - 1)){ // 0 refers to the first element in the list
			return "";
		}
		return head -> get(n);
	}
}

