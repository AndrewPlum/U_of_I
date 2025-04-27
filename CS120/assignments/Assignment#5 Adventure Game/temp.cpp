        /*
        Andrew Plum
        CS 120-06
        Assignment #5
        9/25/21
        */

        // I did all of the regular assignment; there was no extra credit.

        /*
        Adventure Game - This is a simple adventure game which utilizes switch statements and functions.
        */

#include<iostream> // include 2 libraries
using namespace std;

int key = 0;

//---------- Function Prototypes -----------
void intro();
int room_1();
int room_2();
int room_3();
int room_4();
int room_5();
int room_6();
//--------------  Main -------------------
int main()
{

    // variables

    int choice = 1;
    int valid_choice;
    int torch_time = 120;
    int excalibur = 0;

    // Opening program message

    cout << "\nThis is a simple adventure game.\n";
    cout << "You are a young prince in search of adventure.\n";
    cout << "One day during your father's reign over the kingdom, news of an unknown crypt discovered in your realm by miners deep underground reached the royal court.\n";
    cout << "Not ever knowing anything of its existence, your father sent a party of knights to go explore the crypt.\n";
    cout << "Being hungry for adventure, you volunteered to join the party and journey with them to the depths.\n";
    cout << "After hours of venturing underground in the crypt's tunnels, you and your party encounter traps which separates you from them and the way from whence you came.\n";
    cout << "The crypt is dark, wet, and dangerous, and you only have a limited amount of time before the flame of the torch you have with you burns out.\n";
    cout << "You must search for another way out of the crypt in hopes that you are not lost down here for eternity\n";

     // calculation code loop

    do{
        valid_choice = 1;           // assume choice is valid

	if(torch_time < 0){
            cout << "Your lose" << endl;
            break;
        }
 
       switch(choice){
        case 1:                     // first room - cave clearing
                cout << "\nTime left before torch dies (mins): " << torch_time << endl;
                choice = room_1();
                break;
        case 2:                     // second room - two way split (and torch not yet)
                cout << "\nTime left before torch dies (mins): " << torch_time << endl;
                choice = room_2();
                break;
        case 3:                     // third room - three way split
                cout << "\nTime left before torch dies (mins): " << torch_time << endl;
                choice = room_3();
                break;
        case 4:                     // fourth room - excalibur
		choice = room_4();
                break;
        case 5:                     // fifth room - dragon

                break;
        case 6:                     // sixth room - exit

                break;
        default:
                valid_choice = 0;   // choice is invalid
                cout << "Invalid Choice." << endl;
		break;
        }
        torch_time -= 10;
    }while(choice > 0 && choice < 7);    // if not 0, loop back to start
    return 0;
}

//--------------  Functions -------------------
    // room 1
int room_1(){
    int temp_value, choice = 1;
    cout << "\nYou come to a big open cave clearing with a large ravine running through the middle of it.\n";
    cout << "You see a stone bridge that travels across the ravine as well as a narrow pathway along the ravine.\n";
    cout << "You can choose to: go over the bridge (1) or travel on the narrow pathway along the ravine (2).\n";
    do{
        cout << "You choose to: ";
        cin >> temp_value;
        if(temp_value < 1 || temp_value > 2){
            cout << "Invalid choice; enter 1 or 2.\n";
        }
    }while(temp_value < 1 || temp_value > 2);
    if(temp_value == 1){
        choice += 1;
    }
    if(temp_value == 2){
        choice += 2;
    }
    return choice;
}
    // room 2
int room_2(){
    int temp_value, choice = 2;
    cout << "\nFrom the bridge, you followed a tunnel until you arrived in a room with two entrances.\n";
    cout << "The air of the entrance on the left smells stale.\n";
    cout << "And the one on the right from whence you came smells pungent.\n";
    cout << "You can choose to: go down the left tunnel (1) or go down the right tunnel (2).\n";
    do{
        cout << "You choose to: ";
        cin >> temp_value;
        if(temp_value != 1 && temp_value != 2){
            cout << "Invalid choice; enter 1 or 2.";
        }
    }while(temp_value != 1 && temp_value != 2);
    if(temp_value == 1){
        choice -= 1;
    }
    if(temp_value == 2){
        choice += 1;
    }
    if(temp_value == 3){
        choice += 2;
    }
    return choice;
}
    // room 3
int room_3(){
    int temp_value, choice = 3;
    cout << "\nAfter following the tunnel, eventually you arrived in a room with three entrances.\n";
    cout << "The air of the entrance on the left smells stale.\n";
    cout << "The one in the middle has a symbol above its stone arch with a dot and a circle drawn around it.\n";
    cout << "And the one on the right from whence you came smells pungent.\n";
    cout << "You can choose to: go down the left tunnel (1), go down the middle tunnel (2), or go down the right tunnel (3).\n";
    do{
        cout << "You choose to: ";
        cin >> temp_value;
    }while(temp_value != 1 || temp_value != 2);
    if(temp_value == 1){
        choice -= 2;
    }
    if(temp_value == 2){
        choice += 3;
    }
    return choice;
}
    // room 4
int room_4(){
    static int sword = 1;
    int temp_value, choice = 4;
    if(sword == 1){
        cout << "SWORD ROOM\n"; 
        cout << "You come to a big opening with a big rock in the center of it.\n";
        cout << "You see atop the rock is a sword with a ray of light cast through the cave on it.\n";
        cout << "At the opposite end of the cave is an entrance to another tunnel.\n";
        cout << "You can choose to: go to the tunnel (1) or go to the tunnel and take the sword with you (2).\n";
        sword = 0;
    }
    else{
        cout << "No sword, go away" << endl;
    }
    do{
        cout << "You choose to: ";
        cin >> temp_value;
        if(temp_value < 1 || temp_value > 2){
            cout << "Invalid choice; enter 1 or 2.\n";
        }
    }while(temp_value < 1 || temp_value > 2);
    if(temp_value == 1){
        choice += 1;
    }
    if(temp_value == 2){
        choice += 2;
    }
    return choice;
}
//-------------------- print_menu function -------------
void intro(){
    cout << "\nThis is a simple adventure game.\n";
    cout << "You are a young prince in search of adventure.\n";
    cout << "One day during your father's reign over the kingdom, news of an unknown crypt discovered in your realm by miners deep underground reached the royal court.\n";
    cout << "Not ever knowing anything of its existence, your father sent a party of knights to go explore the crypt.\n";
    cout << "Being hungry for adventure, you volunteered to join the party and journey with them to the depths.\n";
    cout << "After hours of venturing underground in the crypt's tunnels, you and your party encounter traps which separates you from them and the way from whence you came.\n";
    cout << "The crypt is dark, wet, and dangerous, and you only have a limited amount of time before the flame of the torch you have with you burns out.\n";
    cout << "You must search for another way out of the crypt in hopes that you are not lost down here for eternity\n";
}
