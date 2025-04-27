    /*
    Andrew Plum
    CS 121-01
    Assignment #2
    1/28/22
    */

        // I did all of the regular assignment

    /* Conway's Game of Life -
    * a program which is review of cs 120 topics.
    * Rules change:
    * I chose to do one of the life-like cellular automaton.
    * I implemented the B2/S rule.
    * The cell becomes alive if there are two adjacent live cells otherwise the cell dies.
    */

#include<iostream> // include a library
#include"life_v2.h"
using namespace std;

int main(){

    life board; // life is the class, board is the object
    board.initialize();
    board.print();
    board.run();

}



