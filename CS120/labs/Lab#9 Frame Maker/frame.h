        /*
        Andrew Plum
        CS 120-06
        Lab #9
        10/25/21
        */

        // I did all of the regular lab assignment; there was no extra credit.

        /*
        This is a simple program which creates frames.
        */

#include<iostream>
using namespace std;

// Declaration of frame class

class frame{
    private:
        int width;
        int height;
    public:
        frame();
        frame(int);
        frame(int, int);
        void set(int, int);
        void draw();
};

//--------------  Class Functions -------------------

    // frame() constructor

frame::frame(){
    width = 1;
    height = 1;
}

    // frame(int x) constructor

frame::frame(int x){
    if(x < 1){
        x = 1;
    }
    width = x;
    height = x;
}

    // frame(int, int) constructor

frame::frame(int w, int h){
    if(w < 1){
        w = 1;
    }
    if(h < 1){
        h = 1;
    }
    width = w;
    height = h;
}

    // set() frame function

void frame::set(int w, int h){
    if(w < 1){
        w = 1;
    }
    if(h < 1){
        h = 1;
    }
    width = w;
    height = h;
}

    // draw() frame function

void frame::draw(){

    // top of frame

    cout << "*";
    for(int i = 1; i <= width; i++){
        cout << "*";
    }
    cout << "*";
    cout << endl;

    // middle of frame

    for(int i = 1; i <= height; i++){
        cout << "*";
        for(int i = 1; i <= width; i++){
            cout << " ";
        }
        cout << "*";
        cout << endl;
    }

    // bottom of frame

    cout << "*";
    for(int i = 1; i <= width; i++){
        cout << "*";
    }
    cout << "*";
}











