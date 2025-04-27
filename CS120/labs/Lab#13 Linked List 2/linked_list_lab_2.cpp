        /*
        Andrew Plum
        CS 120-06
        Lab #13
        11/29/21
        */

        // I did all of the regular lab assignment; there was no extra credit.

        /*
        This is a simple program which uses linked lists.
        */

#include<iostream>
using namespace std;
#include"linkedlist.h"

int main(){
    linkedlist animals;
    node *p;
   	p = new node();
   	p->setdata("cat");
   	animals.push(p);

   	p = new node();
   	p->setdata("dog");
   	animals.push(p);

   	p = new node();
   	p->setdata("unicorn");
   	animals.push(p);

	cout << endl << "Animal list: " << endl << endl;
   	animals.print();

	// 2 new animals in animals list

	p = new node();
	p->setdata("cow");
	animals.push(p);

	p = new node();
	p->setdata("pig");
	animals.push(p);

	cout << endl << "Two new elements added to animal list: " << endl << endl;
   	animals.print();

   	// Reverse print demonstrated

   	cout << endl << "Reverse order of animal list: " << endl << endl;
   	animals.reverseprint();

   	// Pop function demonstrated

   	cout << endl << "Pop function demonstrated with animal list: " << animals.pop() << endl << endl; // getdata() function demonstrated in pop() function definition
   	cout << "Animal list printed after pop function: " << endl << endl;
   	animals.print();

   	// Demonstration of functions with empty linked lists

   	linkedlist cars;
   	cout << endl << "Empty car list: " << endl;
   	cars.print();

   	cout << endl << "Reverse order of empty car list: " << endl;
   	cars.reverseprint();

   	cout << endl << "Pop function demonstrated with empty car list: " << cars.pop() << endl << endl; // getdata() function demonstrated in pop() function definition
   	cout << "Car list printed after pop function: " << endl << endl;
   	cars.print();
}
