    /*
	Andrew Plum
	CS 121-01
	Assignment #10
	3/25/22
	*/

		// I did all of the regular assignment.
		// NOTE: first generation (so the root) is index 0, second generation (root's children) index 1, and so on and so forth - need to know this for the grow function depth

	/* binary_trees_node.h */

#include<iostream>
#include<cstdlib> // srand
#include<ctime>
#include<cmath>
#include<string>
using namespace std;

class node{
    public:
        node* left;
        node* right;
        bool left_growth_check; // used to see if the node should have left branch children
        bool right_growth_check; // used to see if the node should have right branch children
        int value;
        string op;
        node();
        void grow(int); // first generation (so the root) is index 0, second generation (root's children) index 1, and so on and so forth
        double evaluate();
        void print();
        void erase(); // clear
    private:
};

node::node(){
    left = right = NULL;
    left_growth_check = right_growth_check = true;
    value = rand() % 5 + 1; // set max value, +1 for minimum value because zero causes undefined values
    switch(rand() % 7){
        case 0:
            op = "+";
            break;
        case 1:
            op = "-";
            break;
        case 2:
        	op = "*";
        	break;
      	case 3:
      		op = "/";
      		break;
        case 4:
            op = "^";
            break;
        case 5:
        	op = "sin";
        	right_growth_check = false;
        	break;
      	case 6:
      		op = "cos";
      		right_growth_check = false;
      		break;
        default:
            op = "!";
            break;
    }
}

void node::grow(int d){ // first generation (so the root) is index 0, second generation (root's children) index 1, and so on and so forth
    if(d <= 0){
        return; // leaf node
    }
    left = new node();
    if(left_growth_check && left != NULL){
        left->grow(d - 1);
    } else {
    	left = NULL;
    }
    right = new node();
    if(right_growth_check && right != NULL){
        right->grow(d - 1);
    } else {
    	right = NULL;
    }
}

double node::evaluate(){
    // if left and right are NULL then I'm a leaf node and return value
    double x = 0, y = 0, answer = 0;
    if((left == NULL) && (right == NULL)){
        return value;
    } else {
        if(left != NULL){
            x = left->evaluate();
        }
        if(right != NULL){
            y = right->evaluate();
        }
        if(op == "+"){
            answer = x + y;
        }
        if(op == "-"){
            answer = x - y;
        }
        if(op == "*"){
            answer = x * y;
        }
        if(op == "/"){
            answer = x / y;
        }
        if(op == "^"){
            answer = pow(x,y);
        }
        if(op == "sin"){
            answer = sin(x);
        }
        if(op == "cos"){
            answer = cos(x);
        }
    }
    return answer;
}

void node::print(){
    if(left == NULL && right == NULL){
        cout << " " << value << " ";
    } else {
        if(op != "sin" && op != "cos"){ // regular case
            if(left != NULL){
                cout << "(";
                left->print();
                cout << ")";
            }
            cout << " " << op << " ";
            if(right != NULL){
                cout << "(";
                right->print();
                cout << ")";
            }
        } else { // sin and cos cases
            if(left != NULL){
                cout << " " << op << " ";
                cout << "(";
                left->print();
                cout << ")";
            }
        }
    }
}

void node::erase(){ // clear
    if(left != NULL){
        left->erase();
    }
    if(right != NULL){
    	right->erase();
    }
    delete (this);
}
