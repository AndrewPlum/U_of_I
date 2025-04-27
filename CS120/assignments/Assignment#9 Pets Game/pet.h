        /*
        Andrew Plum
        CS 120-06
        Assignment #9
        10/27/21
        */

        // I did all of the regular assignment. I did the middle and bottom bullet points of extra credit; I did not do the first bullet point of extra credit.

        /*
        This is a simple program where you have a pet.
        */

#include<iostream>
#include<string>
using namespace std;
// declaration of the pet class
class pet{
   private:
      int hunger;           // private data member
      string name;          // private data member
      int happy;            // private data member
      int tired;            // private data member
      int choice;           // new private data member
   public:
      pet();                // constructor
      void interact();      // public member function
      void after_interaction(); // public member function
      void play();          // public member function
      void feed();          // public member function
      void sleep();         // new public member function
      void print();         // public member function
      void print_name();    // new public member function
      void random_event();  // new public member function *** FOR EXTRA CREDIT ***
      int check_health();   // public member function
};

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     tired = 50;
     cout << "Pet's name?" << endl;
     getline(cin,name);  // allows spaces in the name
}

/* Member function interact(), allows player to interact with a pet. */
void pet::interact(){
    //print();
    print();
    cout << endl;
    cout << "What would you like to do with your pet?" << endl;
    cout << "(1) Play \n(2) Feed \n(3) Sleep \n" << endl;
    cout << "You choose: ";
    do{
    cin >> choice;
    }while(!(choice > 0 && choice < 4));
    switch(choice){
        case 1:
            play();
            break;
        case 2:
            feed();
            break;
        case 3:
            sleep();
            break;
    }
}

/* Member function after_interact(), pet object values changed after interaction. */
void pet::after_interaction(){
        happy -= 2;
        hunger += 2;
        tired += 2;
}

/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice_play = 0;
    cout << endl;
    cout << "What should we play?\n";
    cout << "(1) Fetch \n(2) Roll over \n";
    cout << "You choose: ";
    cin >> choice_play;
    switch(choice_play){
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
void pet::print_name(){
    cout << name;
}

/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << "\nYour pet " << name << " is\n";
    cout << "Happy: " << happy << endl;
    cout << "Hungry: " << hunger << endl;
    cout << "Tired: " << tired << endl;

    /*
    Messages from previous program

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
    */
}

/* Member function random_event(), checks the health of a pet. */
void pet::random_event(){
    int random_event = rand() % 2 + 1;
    if(random_event == 1){
        cout << "Your pet ";
        print_name();
        cout << " wandered off and made friends with the neighbor's pet." << endl;
        happy += 30;
        hunger += 5;
        tired += 5;
    }
    if(random_event == 2){
        cout << "Your pet ";
        print_name();
        cout << " has hurt itself." << endl;
        happy -= 20;
        hunger += 10;
        tired += 25;
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



