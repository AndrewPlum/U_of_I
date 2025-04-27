    /*
    Andrew Plum
    CS 121-01
    Assignment #4
    2/9/22
    */

		// I did all of the regular assignment

	/* garbage.cpp - fills memory with grabage*/

#include<iostream>
using namespace std;

class garbage{
    public:
        garbage(){data = new double[1000]; cout << "constructing\n";}
        ~garbage(){delete data; cout << "destructing\n";}
    private:
        double *data;
};

int main(){
    int c = 0;
    while(true){
        garbage g;
        cout << c << "\n";
        c++;
    }
}
