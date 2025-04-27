	/*
    Andrew Plum
    CS 120-06
    Lab #8
    10/18/21
    */

	// I did all of the regular lab assignment; there was no extra credit.

	/*
    This is a simple program which calculates weather metrics based off the data from weather.txt
    */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int HighTemp(double a[]);
int LowTemp(double a[]);
double AverageHighTemp(double a[]);
double AverageLowTemp(double a[]);
void DailyChangeSnowDepth(double a[]);
double AverageDailyChangeSnowDepth(double a[]);

int main(){
    ifstream infile; // this creates an ifstream object called infile

    infile.open("weather.txt"); // this connects infile to the text file

    string x;
    for(int i = 0; i < 6; i++){ // reads the header of weather.txt
        infile >> x;
        //cout << x << endl;
    }

    int day[31];
    string month[31];
    int year[31];
    double high[31];
    double low[31];
    double precip[31];
    double snow[31];
    double snowDepth[31];

    // gather data into arrays from weather.txt

    for(int i = 0; i < 31; i++){
        infile >> day[i];
        infile >> month[i];
        infile >> year[i];
        infile >> high[i];
        infile >> low[i];
        infile >> precip[i];
        infile >> snow[i];
        infile >> snowDepth[i];
    }
    infile.close();

    cout << endl << "Weather Metrics for Month of January 2016:" << endl << endl; // what the data is

    int i = HighTemp(high); // get highest temp
    cout << "Highest Temperature: " << high[i] << " degrees fahrenheit" << endl;

    int j = LowTemp(low); // get lowest temp
    cout << "Lowest Temperature: " << low[j] << " degrees fahrenheit" << endl;

    cout << "Average High Temperature: "<< AverageHighTemp(high) << " degrees fahrenheit" << endl; // print average high temperature

    cout << "Average Low Temperature: "<< AverageLowTemp(low) << " degrees fahrenheit" << endl; // print average low temperature

	cout << "Daily Change in Snow Depth: "; 
	DailyChangeSnowDepth(snowDepth);
	cout << " all mesurments in inches" << endl; // print daily change in snow depth

    cout << "Average Daily Change in Snow Depth: " << AverageDailyChangeSnowDepth(snowDepth) << " inches" << endl; // print average daily change in snow depth

    return 0;
}

// function for getting highest temperature

int HighTemp(double a[]){
    int index = 0;
    for(int i = 0; i < 31; i++){
        if(a[index] < a[i]){
            index = i;
        }
    }
    return index;
}

// function for getting lowest temperature

int LowTemp(double a[]){
    int index = 0;
    for(int i = 0; i < 31; i++){
        if(a[index] > a[i]){
            index = i;
        }
    }
    return index;
}

// function for getting average high temperature

double AverageHighTemp(double a[]){
    double sum = 0;
    int num_of_objects = 31;
    double average;
    for(int i = 0; i < 31; i++){
        sum = sum + a[i];
    }
    average = sum / num_of_objects;
    return average;
}

// function for getting average low temperature

double AverageLowTemp(double a[]){
    double sum = 0;
    int num_of_objects = 31;
    double average;
    for(int i = 0; i < 31; i++){
        sum = sum + a[i];
    }
    average = sum / num_of_objects;
    return average;
}

// function for getting daily change in snow depth

void DailyChangeSnowDepth(double a[]){
	double daily_change;
    for(int i = 0; i < 30; i++){
    	daily_change = a[i + 1] - a[i];
    	if(i < 29){
    		cout << daily_change << ", ";
    	}
    	if(i == 29){
    		cout << daily_change;
    	}
    }
}

// function for getting average daily change in snow depth

double AverageDailyChangeSnowDepth(double a[]){
    double daily_change;
    double sum = 0;
    int num_of_objects = 30;
    double average;
    for(int i = 0; i < 30; i++){
        daily_change = a[i + 1] - a[i];
        sum = sum + daily_change;
    }
    average = sum / num_of_objects;
    return average;
}

