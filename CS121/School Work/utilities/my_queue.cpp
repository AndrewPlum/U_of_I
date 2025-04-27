    /*
	Andrew Plum
	CS 121-01
	Assignment #3
	1/30/22
	*/

		// I did all of the regular assignment

	/* Queue.cpp */

#include<iostream>
typedef int queue_type; // typedef gives an additional name to an existing type
#include"my_queue.h"
using namespace std;

int main(){

    // Intro

    cout << endl;
    cout << "This is program which demonstrates how a queue using a circular array works." << endl;
    cout << "The index of front corresponds to the index of first element in the array." << endl;
    cout << "So the first element in the queue could be at array index 0." << endl;
    cout << "The index of back corresponds to the index of the one after the last element in the queue." << endl;
    cout << "If the index of the last element in the queue is 4 and the queue can hold more than 5 elements, then back would correspond to array index 5." << endl;
    cout << "The only exception where the index of back does not correspond to the index of the one after the last element in the array is when there are no elements in the array." << endl;
    cout << "For instance, if the of the array has a size of 0, then the index for back will have the same index as the index for front." << endl;
    cout << endl;

    // create queue object

    queue my_queue;

    // declare variables

    int x = 0;

	// demonstrate constructor makes an empty queue

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate empty function and that constructor makes an empty queue." << endl;
	cout << endl;

	cout << "Is the queue empty:" << endl;
    if(my_queue.empty()){
        cout << "Queue is empty." << endl;
        cout << endl;
    } else {
        cout << "Queue is not empty." << endl;
        cout << endl;
    }

	// demonstrate push function

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate push function." << endl;
	cout << endl;

	my_queue.push(5);
	my_queue.push(7);
	my_queue.push(9);
	my_queue.push(11);
    my_queue.push(3); // 5 elements right now in the queue

	my_queue.push(8);
	my_queue.push(1);
	my_queue.push(2);
	my_queue.push(6);
	my_queue.push(4); // 10 elements right now in queue

	my_queue.push(8); // Demonstrate overflow
	my_queue.push(3);
	my_queue.push(6);
	my_queue.push(9);
	my_queue.push(7);

	// demonstrate pop function

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate pop function." << endl;
	cout << endl;

	my_queue.pop();

	// demonstrate push function returning success, should return 0

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate push function returning success; 0 should be returned." << endl;
	cout << endl;

	x = my_queue.push(5);
	cout << "Push function success demonstrated: " << x << endl;
	cout << endl;

	// demonstrate push function returning overflow, should return 2

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate push function returning overflow; 2 should be returned." << endl;
	cout << endl;

	x = my_queue.push(5);
	cout << "Push function overflow demonstrated: " << x << endl;
	cout << endl;

	// // demonstrate pop function returning success, should return 0

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate pop function returning success; 0 should be returned." << endl;
	cout << endl;

    x = my_queue.pop();
	cout << "Pop function success demonstrated: " << x << endl;
	cout << endl;

	// demonstrate pop function returning underflow, should return 3

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate pop function returning underflow; 3 should be returned." << endl;
	cout << endl;

	my_queue.pop();
	my_queue.pop();
	my_queue.pop();
	my_queue.pop();
	my_queue.pop(); // pop 5 times

	my_queue.pop();
	my_queue.pop();
	my_queue.pop();
	my_queue.pop(); // pop 9 times clearing list

	x = my_queue.pop(); // pop 1 more time which should result in an underflow error
	cout << "Pop function underflow demonstrated: " << x << endl; // should print 3
	cout << endl;

	// demonstrate front function underflow, should return 3

    cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate front function returning underflow; 3 should be returned." << endl;
	cout << endl;

	queue_type data = 0;

	x = my_queue.front(data);

    cout << "Front function underflow demonstrated: " << x << endl; // should print 3
	cout << endl;

	// demonstrate front function success, should return 0

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrate front function returning success; 0 should be returned." << endl;
	cout << endl;

	my_queue.push(23463);
    x = my_queue.front(data);
    cout << "Front function success demonstrated: " << x << endl; // should print 0
	cout << "Value at front of Queue is " << data << endl;

	cout << endl;

	// demonstrating the front and back array indices wrap around

	cout << "--------------------------------------------------------------------" << endl; // this is to parse the demonstration sections so the output looks better
	cout << endl;
	cout << "Demonstrating that the front and back queue indicies wrap around." << endl;
	cout << endl;

	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop(); // pushed and popped 5 times

	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop(); // pushed and popped 5 more times

	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop(); // pushed and popped 5 more times

	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop();
	my_queue.push(1);
	my_queue.pop(); // pushed and popped 5 more times, for a total of two full cycles through the queue

	my_queue.push(1);
	my_queue.push(1);
	my_queue.push(1);
	my_queue.push(1);
    my_queue.push(1);
	my_queue.push(1);
	my_queue.push(1);
	my_queue.push(1);
	my_queue.push(1);
	my_queue.push(1);
	my_queue.push(1); // the queue can be filled up again and will still get overflows










}
