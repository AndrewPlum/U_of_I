        /*
        Andrew Plum
        CS 120-06
        Lab #2
        9/5/21
	*/

   //Boolean Operators Lab

#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
	cout << "1) ";		//print line number
	if(0){			//if the statement is...
    	cout << "It's true\n";	//true, print true 
	} else {		//or if
    	cout << "It's false\n";	//false, print false
	}
				//repeat... until 23 statements processed	
	cout << "2) ";
        if(-7){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "3) ";
        if(-1 + -2){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "4) ";
        if(-7 + 7){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "5) ";
        if(7 < 8){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "6) ";
        if(10 > 10){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "7) ";
        if((7 < 10) || (7 > 10)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "8) ";
        if((7 < 10) && (7 > 10)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "9) ";
        if(-5 >= 5){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "10) ";
        if((7 > 10) || (-5 == 5)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "11) ";
        if(!(6 == 7)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "12) ";
        if((10 != 11) && (7 > 8)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "13) ";
        if((7 == 6) || (7 == 7) || (7 == 8)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "14) ";
        if((6 < (8 && 9))){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "15) ";
        if((1 == (6 < 8))){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "16) ";
        if((0 == (0 || 1))){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "17) ";
        if(6 < (5 + 2)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "18) ";
        if(6 + (5 == 5)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "19) ";
        if((6 < 7) + (7 >= 5)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "20) ";
        if((0 < 7) - (0 < 7)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "21) ";
        if(!(10 - 7)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "22) ";
        if(!((10 != 10) - 1)){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

        cout << "23) ";
        if(!((5 < 7) - (7 > 5))){
        cout << "It's true\n";
        } else {
        cout << "It's false\n";
        }

	return 0;
}

/*
Evaluated Hypotheses
1)      0
        False
2)      -7
        True
3)      -1 + -2
        True
4)      -7 + 7
        False
5)      7 < 8
        True
6)      10 > 10
        False
7)      (7 < 10) || (7 > 10)
        True
8)      (7 < 10) && (7 > 10)
        False
9)      -5 >= 5
        False
10)     (7 > 10) || (-5 == 5)
        False
11)     !(6 == 7)
        True
12)     (10 != 11) && (7 > 8)
        False
13)     (7 == 6) || (7 == 7) || (7 == 8)
        True
14)     (6 < (8 && 9)) [This one is tricky.]
        True
	Wrong
15)     (1 == (6 < 8)) [Also tricky.]
        True
16)     (0 == (0 || 1)) [Still more trickiness.]
        True
	Wrong
17)     6 < (5 + 2)
        True
18)     6 + (5 == 5)
        True
19)     (6 < 7) + (7 >= 5)
        True
20)     (0 < 7) - (0 < 7)
	False
21)     !(10 - 7)
        False
22)     !((10 != 10) - 1)
        False
23)     !((5 < 7) - (7 > 5))
        True
*/
