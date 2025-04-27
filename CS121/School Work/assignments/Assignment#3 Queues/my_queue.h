    /*
    Andrew Plum
    CS 121-01
    Assignment #3
    1/30/22
    */

		// I did all of the regular assignment

	/* Queue.cpp */

#include<iostream>
using namespace std;

const int maxsize = 10;

enum error_code{success, fail, overflow, underflow}; // succes:0 fail:1 overflow 2 underflow 3

class queue{
    public:
        queue();  // constructor
        bool empty();
        error_code push(const queue_type);
        error_code pop();
        error_code front(queue_type &);
    private:
        queue_type que[maxsize];
        int size;
        int f; // front
        int b; // back
};

queue::queue(){
    size = 0;
    f = 0;
    b = 0;
}

bool queue::empty(){
    if(size == 0){
        return true;
    }
    return false;
}

error_code queue::push(const queue_type c){
    error_code ec = success;
    if(size < maxsize){
        que[size] = c;
        size++;
        b++;
        b = b % maxsize; // creates the circular array
        cout << "Element successfully pushed into queue!" << endl;
        cout << "Queue size: " << size << endl;
        cout << "Queue front index: " << f << endl;
        cout << "Queue back index: " << b << endl;
        cout << endl;
    } else {
        ec = overflow;
        cout << "Overflow error!" << endl;
        cout << "Queue size: " << size << endl;
        cout << "Queue front index: " << f << endl;
        cout << "Queue back index: " << b << endl;
        cout << endl;
    }
    return ec;
}

error_code queue::pop(){
    error_code ec = success;
    if(size > 0){
        size--;
        f++;
        f = f % maxsize; //creates the cirular array
        cout << "Element successfully popped from queue!" << endl;
        cout << "Queue size: " << size << endl;
        cout << "Queue front index: " << f << endl;
        cout << "Queue back index: " << b << endl;
        cout << endl;
    } else {
        ec = underflow;
        cout << "Underflow error!" << endl;
        cout << "Queue size: " << size << endl;
        cout << "Queue front index: " << f << endl;
        cout << "Queue back index: " << b << endl;
        cout << endl;
    }
    return ec;
}

error_code queue::front(queue_type &data){
    error_code ec = success;
    if(size > 0){
        data = que[size-1];
    } else {
        ec = underflow;
        cout << "Underflow error!" << endl;
        cout << "Queue size: " << size << endl;
        cout << "Queue front index: " << f << endl;
        cout << "Queue back index: " << b << endl;
        cout << endl;
    }
    return ec;
}
