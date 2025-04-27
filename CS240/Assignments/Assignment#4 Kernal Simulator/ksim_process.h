/*
Andrew Plum
Professor Wilder
CS 240
11/19/22
*/

    /*
    ***Assignment #4 - ksim_process.h***
    */


                    //#include<stdio.h>

#include<stdlib.h>

// process class

class process{ // process class created
	private:
	public:
		enum state{ready, running, blocked, exit}; // ready:0 running:1 blocked:2 exit:3
		process(); // constructor with no arguments
};

process::process(){
    state st = ready;
}
