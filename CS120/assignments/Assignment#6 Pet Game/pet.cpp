        /*
        Andrew Plum
        CS 120-06
        Assignment #6
        10/2/21
        */

        // I did all of the regular assignment; there was no extra credit.

        /*
        This is a simple program where you have a pet.
        */

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
// declaration of the pet class
class pet{
   private:
      int hunger;           // private data member
      string name;          // private data member
      int happy;            // private data member
      int tired;            // new private data member
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void sleep();         // new public member function
      void print();         // public member function
      int check_health();   // public member function
};
int main()
{
   srand(time(NULL));
   pet pet1;
   int choice;
   int health_check;
   do{
       pet1.print();
       cout << "\nWhat would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Sleep (3) \n Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 0:
           cout << "\nYou and your pet say goodbye.\n";       // exit
           break;
       case 1:
           pet1.play();
           break;
       case 2:
           pet1.feed();
           break;
       case 3:
           pet1.sleep();
           break;
      }
      health_check = pet1.check_health();
   }while(choice != 0 && health_check != 1);
   cin.ignore();
   cout << "The program has ended." << endl;
   return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     tired = 50;
     cout << "Pet's name? (One word) ";
     cin >> name;
}
/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n";
    cin >> choice;
    switch(choice){
    case(1):
         happy += 10;
         hunger += 5;
         tired += 10;
         break;
    case(2):
         happy += 5;
         hunger += 1;
         tired += 5;
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    int food_message;
    food_message = rand() % 4 + 1;
    switch(food_message){
    case(1):
        cout << "\nMMM, Yummy! That tasted great!\n";
        break;
    case(2):
        cout << "\nMMM, that was good.\n";
        break;
    case(3):
        cout << "\nThat could have tasted better.\n";
        break;
    case(4):
        cout << "\nYuk, that tasted bad.\n";
        break;
    }
    hunger -= 5;
    tired += 5;
}

/* Member function sleep(), allows the user to have their pet sleep. */
void pet::sleep(){
    cout << "\nZZZ\n";
    happy -= 5;
    hunger += 5;
    tired -= 25;
}

/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << "\nYour pet " << name << " is\n";
    cout << "Happy: " << happy << endl;
    cout << "Hungry: " << hunger << endl;
    cout << "Tired: " << tired << endl;
    if(happy <= 25){
         cout << "\nYour pet is sad.\n";
    }
    if(happy == 50){
         cout << "\nYour pet is indifferent.\n";
    }
    if(happy >= 75){
         cout << "\nYour pet is happy.\n";
    }
    if(hunger >= 75){
         cout << "\nYour pet is hungry.\n";
    }
    if(hunger == 50){
         cout << "\nYour pet is a little hungry.\n";
    }
    if(hunger <= 25){
         cout << "\nYour pet is not hungry.\n";
    }
    if(tired >= 75){
         cout << "\nYour pet is tired.\n";
    }
    if(tired == 50){
         cout << "\nYour pet is a little tired.\n";
    }
    if(tired <= 25){
         cout << "\nYour pet is not tired.\n";
    }
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 1;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 1;
    }
    if(tired >= 100){
         cout << "\nYour pet has died of sleep deprivation.\n";
         return 1;
    }
    return 0;
}
