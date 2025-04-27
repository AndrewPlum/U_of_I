#include<iostream>
using namespace std;
int main(){
    
    for (int i = 1; i < 5; i = i + 1){
        for (int j = 1; j < 5; j = j + 1){
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }
    cout << endl;
}
