        /*
        Andrew Plum
        CS 120-06
        Lab #5
        9/24/21
        */

        // I did all of the regular lab assignment; there was no extra credit.

        /* A simple calculator program,
        controlled by a menu and
        divided into separate functions */

#include<iostream> // include 2 libraries
#include<cmath>
using namespace std;
//---------- Function Prototypes -----------
void print_menu();
double get_value();
double divide(double,double);
double sa_cylinder();
double volume_cylinder();
double sa_cone();
//--------------  Main -------------------
int main()
{

     // variables

     double operand1, operand2, answer;
     int choice, valid_choice;

     // Opening program message

     cout << "\nThis is a simple calculator with limited operations.\n";
     cout << "You will enter your choice of which operation you want to perform.\n";
     cout << "Then you will enter in the values you want calculated.\n";
     cout << "Finally, you will get an answer based off the operator and values chosen.\n";

     // calculation code loop

     do{
           print_menu();
           cin >> choice;
           valid_choice = 1;           // assume choice is valid
           switch(choice){
           case 0:                    // program will exit
                  break;
           case 1:                    // addition
                  operand1 = get_value();
                  operand2 = get_value();
                  answer = operand1 + operand2;
                  cout << endl << operand1 << " + " << operand2 << " = " << answer << endl;// if choice is valid, print the answer
                  break;
           case 2:                    // subtraction
                  operand1 = get_value();
                  operand2 = get_value();
                  answer = operand1 - operand2;
                  cout << endl << operand1 << " - " << operand2 << " = " << answer << endl;// if choice is valid, print the answer
                  break;
           case 3:                    // multiplication
                  operand1 = get_value();
                  operand2 = get_value();
                  answer = operand1 * operand2;
                  cout << endl << operand1 << " * " << operand2 << " = " << answer << endl;// if choice is valid, print the answer
                  break;
           case 4:                    // division
                  operand1 = get_value();
                  operand2 = get_value();
                  answer = divide(operand1,operand2);
                  cout << endl << operand1 << " / " << operand2 << " = " << answer << endl;// if choice is valid, print the answer
                  break;
           case 5:                    // surface area of right circular cylinder
                  sa_cylinder();
                  break;
           case 6:                    // volume of right circular cylinder
                  volume_cylinder();
                  break;
           case 7:                    // surface area of right circular cone
                  sa_cone();
                  break;
           default:
                  valid_choice = 0;   // choice is invalid
                  cout << "Invalid Choice." << endl;
            }
      }while(choice != 0);    // if not 0, loop back to start
      return 0;
}

//--------------  Functions -------------------
    // divide function
double divide(double dividend, double divisor){
      if(divisor == 0){
            return 0;  // avoids divide by zero errors
      }
      else
            return (dividend/divisor);
}
    // surface area of right circular cylinder function
double sa_cylinder(){
      double operand1, operand2, answer;
      cout << "First value entered will be the radius (r) of the cylinder.\n";
      operand1 = get_value();
      cout << "Second value entered will be the height (h) of the cylinder.\n";
      operand2 = get_value();
      answer = (2 * 3.14 * operand1 * operand2) + (2 * 3.14 * operand1 * operand1);
      cout << endl << "(2 * 3.14 * " << operand1 << " * " << operand2 << ") + (2 * 3.14 * " << operand2 << "^2) = " << answer << endl;// if choice is valid, print the answer
      return answer;
}
    // volume of right circular cylinder function
double volume_cylinder(){
      double operand1, operand2, answer;
      cout << "First value entered will be the radius (r) of the cylinder.\n";
      operand1 = get_value();
      cout << "Second value entered will be the height (h) of the cylinder.\n";
      operand2 = get_value();
      answer = (2 * 3.14 * operand1 * operand1 * operand2);
      cout << endl << "2 * 3.14 * (" << operand1 << ")^2 * " << operand2 << " = " << answer << endl;// if choice is valid, print the answer
      return answer;
}
    // surface area of right circular cone function
double sa_cone(){
      double operand1, operand2, answer;
      cout << "First value entered will be the radius (r) of the cone.\n";
      operand1 = get_value();
      cout << "Second value entered will be the height (h) of the cone.\n";
      operand2 = get_value();
      answer = (3.14 * operand1 * (operand1 + sqrt((operand1 * operand1) + (operand2 * operand2))));
      cout << endl << "3.14 * " << operand1 << " * (" << operand1 << " + sqrt(" << operand1 << "^2 + " << operand2 << "^2)) = " << answer << endl;// if choice is valid, print the answer
      return answer;
}
//----------------- get_value function ----------------
double get_value(){
      double temp_value;
      cout << "Please, enter a value: ";
      cin >> temp_value;
      cout << "Thanks." << endl;
      return temp_value;
}
//-------------------- print_menu function -------------
void print_menu(){
     cout << endl;
     cout << "Add (1)" << endl;
     cout << "Subtract (2)" << endl;
     cout << "Multiply (3)" << endl;
     cout << "Divide (4)" << endl;
     cout << "Surface Area of Right Circular Cylinder (5)" << endl;
     cout << "Volume of Right Circular Cylinder (6)" << endl;
     cout << "Surface Area of Right Circular Cone (7)" << endl;
     cout << "Exit (0)" << endl;
     cout << "Enter your choice: ";
}
