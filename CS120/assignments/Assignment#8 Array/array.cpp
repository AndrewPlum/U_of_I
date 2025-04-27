        /*
        Andrew Plum
        CS 120-06
        Assignment #8
        10/19/21
        */

        // I did all of the regular assignment and the extra credit.

        /*
        This is a simple program which works with arrays and calculates their metrics.
        */

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

// *** Prototypes of functions ***

void generate(double [], int, double, double);
void print(double [], int);
double average(double [], int);
double min(double [], int);
double max(double [], int);
double addX(double [], int, double);
int num_less(double [], int);
int num_more(double [], int);
int num_less(double [], int, double);
double range(double [], int);
double std_dev(double [], int);


// main

int main(){

    srand(time(NULL));

    // variables

    int x;
    int size;
    double first_bound;
    double second_bound;
    double threshold_value;

    // intro and gather basic array data

    cout << "This is a program which does things with arrays based off user input." << endl;
    cout << "Enter a positive number for what length you want the array to be: ";
    cin >> size;
    cout << "Enter a number for the first bound of the number: ";
    cin >> first_bound;
    cout << "Enter a number for the second bound of the number: ";
    cin >> second_bound;

    // create the array from basic array data gathered

    double data[size];

    // array functions in use

    generate(data, size, first_bound, second_bound);

    cout << "Array: ";
    print(data, size);

    cout << "Average of the data in the array: ";
    cout << average(data, size) << endl;

    cout << "Lowest value from data in the array: ";
    cout << min(data, size) << endl;

    cout << "Highest value from data in the array: ";
    cout << max(data, size) << endl;

    cout << "What value would you like to add to the values in the array: ";
    cin >> x;
    data[size] = addX(data, size, x);
    cout << "Array after values are added: ";
    print(data, size);

    cout << "New average of the data in the array: ";
    cout << average(data, size) << endl;

    cout << "Number of values less than the average: ";
    cout << num_less(data, size) << endl;

    cout << "Number of values more than the average: ";
    cout << num_more(data, size) << endl;

    cout << "Next, you will enter a value and will be shown how many values of the array are less than that value." << endl;
    cout << "Enter a value: ";
    cin >> threshold_value;
    cout << "Number of values less than the threshold value: ";
    cout << num_less(data, size, threshold_value) << endl;

    cout << "Range of the array: ";
    cout << range(data, size) << endl;

    cout << "Standard deviation of the array: ";
    cout << std_dev(data, size) << endl;

    return 0;
}

// functions code defined

// generates a data set of values for the array passed through

void generate(double a[], int b, double x, double y){
    a[b];
    double z;
    if(x < y){
        z = y - x;
        for(int i = 0; i < b; i++){
            a[i] = x + ((rand() % 1000) / 1000.0) + rand() % (int)z;
        }
    }
    if(x > y){
        z = x - y;
        for(int i = 0; i < b; i++){
            a[i] = y + ((rand() % 1000) / 1000.0) + rand() % (int)z;
        }
    }
}

// function which prints the array data values

void print(double a[], int b){
    cout << "Array: ";
    for(int i = 0; i < b; i++){
        if(i+1 < b){
            cout << a[i] << ", ";
        }
        if(i+1 == b){
            cout << a[i];
        }
    }
    cout << endl;
}

// average of the values in the array

double average(double a[], int b){
    double sum = 0;
    for(int i = 0; i < b; i++){
        sum = sum + a[i];
    }
    double average = sum / b;
    return average;
}

// minimum value in array

double min(double a[], int b){
    double low = a[1];
    for(int i = 0; i < b; i++){
        if(low > a[i]){
            low = a[i];
        }
    }
    return low;
}

// maximum value in array

double max(double a[], int b){
    double high = a[1];
    for(int i = 0; i < b; i++){
        if(high < a[i]){
            high = a[i];
        }
    }
    return high;
}

// add value to array values

double addX(double a[], int b, double x){
    for(int i = 0; i < b; i++){
        a[i] = a[i] + x;
    }
    return a[b];
}

// numbers less than average

int num_less(double a[], int b){
    int count = 0;
    double sum = 0;
    for(int i = 0; i < b; i++){
        sum = sum + a[i];
    }
    double average = sum / b;
    for(int i = 0; i < b; i++){
        if(a[i] < average){
                count++;
        }
    }
    return count;
}

// numbers more than average

int num_more(double a[], int b){
    int count = 0;
    double sum = 0;
    for(int i = 0; i < b; i++){
        sum = sum + a[i];
    }
    double average = sum / b;
    for(int i = 0; i < b; i++){
        if(a[i] > average){
                count++;
        }
    }
    return count;
}

// numbers less than threshold value

int num_less(double a[], int b, double threshold_value){
    int count = 0;
    for(int i = 0; i < b; i++){
        if(a[i] < threshold_value){
                count++;
        }
    }
    return count;
}

// range

double range(double a[], int b){
    double range;
    double high = a[1];
    for(int i = 0; i < b; i++){
        if(high < a[i]){
            high = a[i];
        }
    }
    double low = a[1];
    for(int i = 0; i < b; i++){
        if(low > a[i]){
            low = a[i];
        }
    }
    range = high - low;
    return range;
}

// standard deviation

double std_dev(double a[], int b){
    double sum1 = 0;
    for(int i = 0; i < b; i++){
        sum1 = sum1 + a[i];
    }

    double mean = sum1 / b;

    double sum2 = 0;
    for(int i = 0; i < b; i++){
        sum2 = sum2 + ((a[i] - mean) * (a[i] - mean));
    }

    double variance;
    variance = (1.00 / (double)b) * sum2;

    double standard_deviation;
    standard_deviation = sqrt(variance);

    return standard_deviation;
}











