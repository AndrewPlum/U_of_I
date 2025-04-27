        /*
        Andrew Plum
        CS 120-06
        Lab #14
        12/7/21
        */

        // I did all of the regular lab assignment; there was no extra credit.

        /*
        This is a review of arrays where the program does simple things with them
        */

#include<iostream>
#include<cstdlib>
using namespace std;

// Put prototypes here

void print(int [], int);
int average(int [], int);
void summation(int [], int, int &);

// Main

int main(){
   int array[10];
   int len = 10;
   for(int i = 0; i < len; i++){
      array[i] = rand()%100;  // Fill the array with random elements
   }
   cout << "The array values are:\n";
   print(array, len); // This function should print each element of the array

   double avg = 0;
   avg = average(array, len);
   // Here the program should call a function called average()
   // That calculates the average and stores the result in avg to be printed
   cout << "The average value is: " << avg << endl;

   int sum = 0;
   summation(array, len, sum); // This should calculate the sum of the values and
                   // Store the answer in sum to be printed.
   cout << "The sum of the values is: " << sum << endl;
}

// Put the function code here

void print(int array[], int len){
    for(int i = 0; i < len; i++){
        cout << array[i] << endl;
    }
}

int average(int array[], int len){
    int sum = 0;
    int average = 0;
    for(int i = 0; i < len; i++){
        sum = sum + array[i];
    }
    average = sum / len;
    return average;
}

void summation(int array[], int len, int &sum){
    sum = 0;
    for(int i = 0; i < len; i++){
        sum = sum + array[i];
    }
}
