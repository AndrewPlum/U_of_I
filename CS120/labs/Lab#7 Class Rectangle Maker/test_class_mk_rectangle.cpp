        /*
        Andrew Plum
        CS 120-06
        Lab #7
        10/8/21
        */

        // I did all of the regular lab assignment; there was no extra credit.

        /*
        This is a simple program which creates squares and rectangles based off user input using classes.
        */

#include<iostream>
using namespace std;
// *** Prototypes of functions ****
class rectangle{
    private:
        int width;
        int height;
    public:
        int area();
        int perimeter();
        void set_rectangle(int,int);
        void print_rectangle();
        void draw_rectangle();
};



int main(){

    // beginning program prompt message

    cout << "\nThis is a simple program which creates rectangles based off user input.\n";
    cout << "The program then calculates and outputs a rectangle as well as its area and perimeter.\n";

    // original program

    rectangle r1, r2, r3;

    // rectangle one

    cout << "\nRectangle 1:\n";
    r1.print_rectangle();
    r1.draw_rectangle();
	cout << "Area = " << r1.area() << endl;
	cout << "Perimeter = " << r1.perimeter() << endl;

    // rectangle two

    cout << "\nRectangle 2:\n";
    r2.set_rectangle(9,-3);
    r2.print_rectangle();
    r2.draw_rectangle();
    cout << "Area = " << r2.area() << endl;
    cout << "Perimeter = " << r2.perimeter() << endl;

    // rectangle three

    cout << "\nRectangle 3:\n";
    r3.set_rectangle(-5,3);
    r3.print_rectangle();
    r3.draw_rectangle();
    cout << "Area = " << r3.area() << endl;
    cout << "Perimeter = " << r3.perimeter() << endl;

}

//--------------  Functions -------------------

    // Rectangle Constructor


    // Rectangle Area

int rectangle::area(){
    int area;
    area = width * height;
    return area;
}

    // Rectangle Perimeter

int rectangle::perimeter(){
    int perimeter;
    perimeter = (2 * width) + (2 * height);
    return perimeter;
}

	// Set rectangle values
	
void rectangle::set_rectangle(int w, int h){
		width = w;
		if(w < 0){
			width = w * -1;
		}
		height = h;
		if(h < 0){
			height = h * -1;
		}
	}

    // Print rectangle

void rectangle::print_rectangle(){
    int num_symbols;
    num_symbols = width * height;
    cout << "Width = " << width << endl;
    cout << "Height = " << height << endl;
    cout << "Number of symbols: " << num_symbols << endl;
}

    // Draw Rectangle

void rectangle::draw_rectangle(){
    for(int i = 1; i <= height; i++){
        cout << "*";
        for(int j = 2; j <= width; j++){
            cout << "*";
        }
        cout << "\n";
    }
}











