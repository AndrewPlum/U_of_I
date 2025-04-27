    /*
    Andrew Plum
    CS 121-01
    Assignment #1
    1/12/22
    */

        // I did all of the regular assignment

    /* Conway's Game of Life -
    * a program which is review of cs 120 topics.
    */

#include<iostream> // include a library
#include"life.h"
using namespace std;

int main(){

    life board; // life is the class, board is the object
    board.initialize();
    board.print();
    board.run();

}



