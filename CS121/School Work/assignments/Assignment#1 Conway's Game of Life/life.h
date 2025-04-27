    /*
    Andrew Plum
    CS 121-01
    Assignment #1
    1/12/22
    */

        // I did all of the regular assignment

    /* Conway's Game of Life -
    * a program which is review of cs 120 topics.
    */

#include<iostream> // include a library
#include<ctime> // include for time()
#include<cstdlib> // include for rand()
using namespace std;

const int width = 40;
const int height = 15;

class life{
    public:
        void initialize();
        void print();
        void run();
    private:
        int grid[height + 2][width + 2];
       	int next_grid[height + 2][width + 2];
        void update();
        int neighbors(int,int);
};

void life::initialize(){

    srand(time(NULL));

	int choice = 0;
    do{
        cout << "Do you want: random values(0) or entered values(1)." << endl;
        cin >> choice;
    }while(choice != 0 && choice != 1);

	for(int i = 0; i < height + 2; i++){
        for(int j = 0; j < width + 2; j++){
            grid[i][j] = 0;
			next_grid[i][j] = grid[i][j];
        }
    }

	// choice is random numbers

	if(choice == 0){
        for(int i = 1; i < height + 1; i++){
            for(int j = 1; j < width + 1; j++){
                grid[i][j] = (rand() % 2);
                next_grid[i][j] = grid[i][j];
            }
        }
    }

	// choice is entered numbers

	if(choice == 1){
		int n1, n2;
		cout << "Enter the x coordinate and then the y coordinate seperately." << endl;
		cout << "Only positive coordinates work." << endl;
		cout << "Enter -1 and -1 for the x and y coordinates to stop entering coordinates." << endl;
		do{
			cout << "Enter the x coordinate:" << endl;
			cin >> n1;
			cout << "Enter the y coordinate:" << endl;
			cin >> n2;
			grid[n2][n1] = 1;
		}while(n1 != -1 && n2 != -1);
        for(int i = 1; i < height + 1; i++){
            for(int j = 1; j < width + 1; j++){
                next_grid[i][j] = grid[i][j];
            }
        }
    }
}

void life::print(){
	for(int i = 1; i < height + 1; i++){
        for(int j = 1; j < width + 1; j++){
            if(grid[i][j] == 1){
                cout << "*";
            }
            if(grid[i][j] == 0){
                cout << "-";
			}
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < width; i++){
        cout << "X";
    }
    cout << endl << endl;
}

void life::run(){
    int steps;
    do{
        cout << "How many steps?" << endl;
        cin >> steps;
        cout << endl;
        for(int i = 0; i < steps; i++){
            update();
            print();
        }
    }while(steps != 0);
}

void life::update(){
	int count = 0;
	int next_grid[height + 2][width + 2];
	for(int i = 1; i < height + 1; i++){
        for(int j = 1; j < width + 1; j++){
			count = neighbors(i,j);
			next_grid[i][j] = 0;
			if(count == 3){
				next_grid[i][j] = 1;
			}
			if(count == 2){
				next_grid[i][j] = grid[i][j];
			}
        }
	}
	for(int i = 1; i < height + 1; i++){
        for(int j = 1; j < width + 1; j++){
            grid[i][j] = next_grid[i][j];
        }
	}
}

int life::neighbors(int row, int col){
	int count = 0;
	for(int dr = -1; dr <= 1; dr++){
		for(int dc = -1; dc <= 1; dc++){
			count += grid[row + dr][col + dc];
		}
	}
	count -= grid[row][col];
	return count;
}
