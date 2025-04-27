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
        rectangle();
        int get_width();
        int get_height();
        int area(int,int);
        int perimeter(int,int);
        void print_rectangle(int,int);
        void draw_rectangle(int,int);
};



int main(){

    // beginning program prompt message

    cout << "\nThis is a simple program which creates rectangles based off user input.\n";
    cout << "You will be asked what to input and you will enter a number for side lengths and a letter for what the shape should be made out of.\n";
    cout << "The program then calculates and outputs a rectangle.\n";

    // original program

    int w, h, a, p;
    rectangle r1, r2, r3;

    // rectangle one

    cout << "\nRectangle 1:\n";
    w = r1.get_width();
    h = r1.get_height();
    a = r1.area(w,h);
    p = r1.perimeter(w,h);
    r1.print_rectangle(w,h);
    r1.draw_rectangle(w,h);
	cout << r1.area() << endl;
	cout << r1.perimeter() << endl;

    // rectangle two

    cout << "\nRectangle 2:\n";
    w = r2.get_width();
    h = r2.get_height();
    a = r2.area(w,h);
    p = r2.perimeter(w,h);
    r2.print_rectangle(w,h);
    r2.draw_rectangle(w,h);
    cout << r2.area() << endl;
    cout << r2.perimeter() << endl;

    // rectangle three

    cout << "\nRectangle 3:\n";
    w = r3.get_width();
    h = r3.get_height();
    a = r3.area(w,h);
    p = r3.perimeter(w,h);
    r3.print_rectangle(w,h);
    r3.draw_rectangle(w,h);
    cout << r3.area() << endl;
    cout << r3.perimeter() << endl;

}

//--------------  Functions -------------------

    // Rectangle Constructor

rectangle::rectangle(){
        width = 0;
        height = 0;
}

    // Get Rectangle Width

int rectangle::get_width(){
    cout << "Please enter a number for the width between 1 and 10 (inclusive): ";
    do{
        cin >> width;
        if(width < -10 || width > 10){
            cout << "The side must be between 1 and 10.\n";
            cout << "Please try again: ";
        }
        if(width > -11 && width < 1){
            width = width * -1;
        }
    }while(width < -10 || width > 10);
    return width;
}

    // Get Rectangle Height

int rectangle::get_height(){
    cout << "Please enter a number for the width between 1 and 10 (inclusive): ";
    do{
        cin >> height;
        if(height < -10 || height > 10){
            cout << "The side must be between 1 and 10.\n";
            cout << "Please try again: ";
        }
        if(height > -11 && height < 1){
            height = height * -1;
        }
    }while(height < -10 || height > 10);
    return height;
}

    // Rectangle Area

int rectangle::area(int width, int height){
    int area;
    area = width * height;
    return area;
}

    // Rectangle Perimeter

int rectangle::perimeter(int width, int height){
    int perimeter;
    perimeter = (2 * width) + (2 * height);
    return perimeter;
}

    // Print rectangle

void rectangle::print_rectangle(int width, int height){
    int num_symbols;
    num_symbols = width * height;
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Number of symbols: " << num_symbols << endl;
}


    // Draw Rectangle

void rectangle::draw_rectangle(int width, int height){
    for(int i = 1; i <= height; i++){
        cout << "*";
        for(int j = 2; j <= width; j++){
            cout << "*";
        }
        cout << "\n";
    }
}











