        /*
        Andrew Plum
        CS 120-06
        Assignment #13
        11/29/21
        */

        // I did all of the regular assignment; there was no extra credit.

        /*
        This is a simple program which uses linked lists.
        */

#include<iostream>
#include<string>
using namespace std;
#include"linkedlist.h"

int main(){

    // Animal list full of elements

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

   	// Print animal list

	cout << endl << "Animal list: " << endl << endl;
   	animals.print();

	// 2 new animals in animal list

	p = new node();
	p->setdata("cow");
	animals.push(p);

	p = new node();
	p->setdata("pig");
	animals.push(p);

	cout << endl << "Two new elements added to animal list: " << endl << endl;
   	animals.print();

	// getdata() function demonstrated with animal list

	cout << endl;

	cout << "Get data function demonstrated with animal list: ";
	p = new node();
	p->setdata("goat"); // not a part of the animals list
	cout << p->getdata();

	// length() function demonstrated with animal list

	cout << endl << endl;

	cout << "Length of animal list: " << animals.length();

   	// append() function demonstrated with animal list
   	cout << endl << endl;

	cout << "Append function demonstrated with animal list: " << endl << endl;
   	p = new node();
   	p->setdata("horse");
   	animals.append(p);
	animals.print();

	// length() function demonstrated with animal list after append() function

	cout << endl;

	cout << "Length of animal list after append function: " << animals.length();

	cout << endl;

	// find() function demonstrated with animal list

	cout << endl;

	cout << "Does the animal list have a horse? (0) means no and (1) means yes: ";
	cout << animals.find("horse");

	cout << endl << endl;

	cout << "Does the animal list have a chicken? (0) means no and (1) means yes: ";
	cout << animals.find("chicken");

	// get() function demonstrated with animal list

	cout << endl << endl;

	cout << "Name of the first element in the animal list: ";
	cout << animals.get(0); // 0 refers to the first element

	cout << endl << endl;

	cout << "Name of the third element in the animal list: ";
	cout << animals.get(2); // 2 refers to the third element

	cout << endl << endl;

	cout << "Name of the fifth element in the animal list: ";
	cout << animals.get(4); // 4 refers to the fifth element

	cout << endl << endl;

	cout << "Name of the tenth element in the animal list: ";
	cout << animals.get(9); // 9 refers to the tenth element

	cout << endl << endl;



	// Empty car list



	linkedlist cars;

	// Print car list

	cout << endl << endl << "Car list: " << endl;
   	cars.print();

	// getdata() function demonstrated with car list

	cout << endl;

	cout << "Get data function demonstrated with car list: ";
	p = new node();
	p->setdata("Toyota"); // not a part of the car list
	cout << p->getdata();

	// length() function demonstrated with car list

	cout << endl << endl;

	cout << "Length of car list: " << cars.length();

   	// append() function demonstrated with car list
   	cout << endl << endl;

	cout << "Append function demonstrated with car list: " << endl << endl;
   	p = new node();
   	p->setdata("Ford");
   	cars.append(p);
	cars.print();

	// length() function demonstrated with car list after append() function

	cout << endl;

	cout << "Length of car list after append function: " << cars.length();

	cout << endl;

	// find() function demonstrated with car list

	cout << endl;

	cout << "Does the car list have a ford? (0) means no and (1) means yes: ";
	cout << cars.find("Ford");

	cout << endl << endl;

	cout << "Does the car list have a chevrolet? (0) means no and (1) means yes: ";
	cout << cars.find("chevrolet");

	// get() function demonstrated with car list

	cout << endl << endl;

	cout << "Name of the first element in the car list: ";
	cout << cars.get(0); // 0 refers to the first element

	cout << endl << endl;

	cout << "Name of the third element in the car list: ";
	cout << cars.get(2); // 2 refers to the third element

	cout << endl << endl;

	cout << "Name of the fifth element in the car list: ";
	cout << cars.get(4); // 4 refers to the fifth element

	cout << endl << endl;

	cout << "Name of the tenth element in the car list: ";
	cout << cars.get(9); // 9 refers to the tenth element

	cout << endl << endl << endl;
}
