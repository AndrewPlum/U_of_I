        /*
        Andrew Plum
        CS 120-06
        Assignment #2
        8/30/21
	*/

        // I did the regular lab assignment and the extra credit

   /* The calculator 
    * a more complicated version of the simple program 
    * introducing some fundimental programming concepts.
    */

#include<iostream> // include a library
using namespace std; 

int main(){ // main() starts the program
	double num1;
	double num2;
	int choice;
	int repeat;
        //int in1;
        //int in2;
	cout << "This is a simple calculator where\n";
	cout << "values and a choice of operators\n";
	cout << "are entered.\n";
	do
	{
		cout << "Enter value 1: ";
		cin >> num1;
		// get the first number
	
		cout << "Enter value 2: ";
        	cin >> num2;
		// get the second number
		cout << "Operators:\n";
		cout << "Addition --> 1\n";
 		cout << "Subtraction --> 2\n";
 		cout << "Multiplication --> 3\n";
 		cout << "Division --> 4\n";
		cout << "Summation of low and high values --> 5\n";
		// print the menu
		do
		{
			cout << "Your choice? ";
			cin >> choice;
			// get the users choice
			if(choice == 1){
				cout << num1 << " + " << num2 << " = ";
				cout << num1 + num2 << endl;
			}else if(choice == 2){
                		cout << num1 << " - " << num2 << " = ";
                		cout << num1 - num2 << endl;
        		}else if(choice == 3){
                		cout << num1 << " * " << num2 << " = ";
                		cout << num1 * num2 << endl;
        		}else if(choice == 4, num2 == 0){
        	       		cout << "Warning undefined\n";	// if divided by 0
       			}else if(choice == 4){
                		cout << num1 << " / " << num2 << " = ";
                		cout << num1 / num2 << endl;
        		}else if(choice == 5){
				if(num1 <= num2){
        				int in1 = num1;
       					int in2 = num2;
					int sum = 0;
					cout << "Sum of: ";
					for(in1; in1 <= in2; in1++)
					{
						sum += in1;
						if(in1 < in2){
							cout << in1 << " + ";
						}
						else{
							cout << in1;
						}
					}
					cout << " = " << sum << endl;
	                        }else if(num1 > num2){
                                        int in1 = num1;
                                        int in2 = num2;
                                        int sum = 0;
                                        for(in2; in2 <= in1; in2++)
                                        {
                                        	sum += in2;
						if(in2 < in1){
							cout << in2 << " + ";
						}
						else{
							cout << in2;
						}
                                        }
					cout << " = Sum = " << sum << endl;};
				// extra credit code here
			}else if(choice < 1 || choice > 5){
				cout << "Invalid operator\n"; // if number given is not 1-4, invalid
				}
			// use some ifs to do the right calculation
		}while(choice < 1 || choice > 5);
		// do while loop to repeat code if operator is invalid
		cout << "Would you like to do another calculation?\n";
		cout << "Enter \"1\" for yes and \"0\" for no.\n";
		cin >> repeat; 
	}while(repeat == 1);
	// do while loop if request for another calculation is true
	// print answer
	return 0;
}
