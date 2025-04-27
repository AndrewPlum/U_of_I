    /*
    Andrew Plum
    CS 121-01
    Assignment #2
    1/26/22
    */

        // I did all of the regular assignment

#include<iostream> // include a library
#include<stack>
using namespace std;

const int maxSize = 10;
enum errorNum{succes, fail, overflow, underflow}; // succes:0 fail:1 overflow 2 underflow 3

class stack{
    public:
        stack(); // constructor
        push(StackType);
        pop();
        top(StackType);
    private:
        StackType theStack[maxSize];
        int size;
};

stack::stack(){
    size = 0;
}

errorNum stack::push(StackType d){
    errorNum ec = success;
    if(size < maxSize){
        theStack[size] = d;
        size += 1;
    } else {
        ec = overflow;
    }
    return ec;
}

errorNum stack::pop(){
    errornNum ec = success;
    if(size > 0){
        size--;
    } else {
        ec = underflow;
    }
    return ec;
}

errorNum stack::top(StackType &data){ // & allows for change in main
    errorNum ec = success;
    if(size > 0){
        data = theStack[size - 1];
    } else {
        ec = underflow;
    }
    return ec;
}






