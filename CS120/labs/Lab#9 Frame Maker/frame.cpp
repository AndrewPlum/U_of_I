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
#include"frame.h"

int main(){
   frame  f1, f2(3), f3(5,3), f4(5,-7);
   frame vframes;
   f1.draw();
   cout << endl;
   f2.draw();
   cout << endl;
   f3.draw();
   cout << endl;
   f4.draw();
   cout << endl;
   cout << "Varing sizes:\n";
   for(int w = 4; w < 8; w++){
      vframes.set(w,w-4);
      vframes.draw();
      cout << endl;
   }
}
