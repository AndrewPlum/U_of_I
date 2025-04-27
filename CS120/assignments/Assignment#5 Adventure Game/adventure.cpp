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
//----------- Global Variables -------------
    int torch_time = 130;
    int excalibur = 0;
//---------- Function Prototypes -----------
void intro();
int torch_light_time();
int room_1();
int room_2();
int room_3();
int room_4();
int room_5();
int room_6();
void torch_light_gone();
int death();
//--------------  Main -------------------
int main()
{

    // variables

    int choice = 1;
    int valid_choice;


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
        switch(choice){
        case 1:                     // first room - cave clearing
                torch_light_time();
                choice = room_1();
                break;
        case 2:                     // second room - two way split with torch materials
                torch_light_time();
                choice = room_2();
                break;
        case 3:                     // third room - three way split
                torch_light_time();
                choice = room_3();
                break;
        case 4:                     // fourth room - excalibur
                torch_light_time();
                choice = room_4();
                break;
        case 5:                     // fifth room - dragon
                torch_light_time();
                choice = room_5();
                break;
        case 6:                     // sixth room - exit and victory scene
                torch_light_time();
                choice = room_6();
                break;
        case 7:                     // death scene
                choice = death();
                break;
        default:
                valid_choice = 0;   // choice is invalid
                cout << "Invalid Choice." << endl;
        }

    }while(choice > 0 && choice < 8 && torch_time > 0);    // if not 0, loop back to start
    if(torch_time <= 0){
        torch_light_gone();         // scene when torch time runs out
    }
    return 0;
}

//--------------  Functions -------------------
int torch_light_time(){
    torch_time -= 10;
    cout << "\nTime left before torch dies (mins): " << torch_time << endl;
}
    // room 1 - cave clearing
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
    // room 2 - two way split with torch materials
int room_2(){
    static int torch_oil = 1;
    int temp_value, choice = 2;
    if(torch_oil == 1){
        cout << "\nFrom the bridge, you followed a tunnel until you arrived in a room with two entrances.\n";
        cout << "You see laying in the corner of the cave is some materials you think you could use for your torch.\n";
        cout << "The air of the entrance on the left smells stale.\n";
        cout << "And the one on the right from whence you came smells pungent.\n";
        cout << "You can choose to: go down the left tunnel (1), go down the right tunnel (2), \nor go down the left tunnel and take the torch materials with you (3), or go down the right tunnel and take the torch materials with you (4).\n";
        do{
            cout << "You choose to: ";
            cin >> temp_value;
            if(temp_value < 1 || temp_value > 4){
                cout << "Invalid choice; enter 1, 2, 3, or 4.";
            }
        }while(temp_value < 1 || temp_value > 4);
        if(temp_value == 1){
            choice -= 1;
        }
        if(temp_value == 2){
            choice += 3;
        }
        if(temp_value == 3){
            torch_time += 30;
            torch_oil = 0;
            choice -= 1;
        }
        if(temp_value == 4){
            torch_time += 30;
            torch_oil = 0;
            choice += 3;
        }
    }
    else{
        cout << "\nFrom the bridge, you followed a tunnel until you arrived in a room with two entrances.\n";
        cout << "The air of the entrance on the left smells stale.\n";
        cout << "And the one on the right from whence you came smells pungent.\n";
        cout << "You can choose to: go down the left tunnel (1) or go down the right tunnel (2).\n";
        do{
            cout << "You choose to: ";
            cin >> temp_value;
            if(temp_value < 1 || temp_value > 2){
                cout << "Invalid choice; enter 1 or 2.";
            }
        }while(temp_value < 1 || temp_value > 2);
        if(temp_value == 1){
            choice -= 1;
        }
        if(temp_value == 2){
            choice += 3;
        }
    }

    return choice;
}
    // room 3 - three way split
int room_3(){
    int temp_value, choice = 3;
    cout << "\nAfter following the narrow pathway, you arrived at a tunnel and decided to journey through it.\n";
    cout << "Eventually you arrived in a room full of artifacts with three entrances.\n";
    cout << "The air of the entrance on the left smells stale.\n";
    cout << "The one in the middle has a symbol above its stone arch with a dot and a circle drawn around it.\n";
    cout << "And the one on the right from whence you came smells pungent.\n";
    cout << "You can choose to: go down the left tunnel (1), go down the middle tunnel (2), or go down the right tunnel (3).\n";
    do{
        cout << "You choose to: ";
        cin >> temp_value;
        if(temp_value != 1 && temp_value != 2 && temp_value != 3){
                cout << "Invalid choice; enter 1, 2, or 3.\n";
        }
    }while(temp_value != 1 && temp_value != 2 && temp_value != 3);
    if(temp_value == 1){
        choice -= 2;
    }
    if(temp_value == 2){
        choice += 1;
    }
    if(temp_value == 3){
        choice += 2;
    }
    return choice;
}
    // room 4 - excalibur
int room_4(){
    static int sword = 1;
    int temp_value, choice = 4;
    if(sword == 1){
        cout << "\nYou see light at the end of the tunnel.\n";
        cout << "You come to a big opening with a big rock in the center of it.\n";
        cout << "You see atop the rock is a sword with a ray of light cast through the cave on it.\n";
        cout << "At the opposite end of the cave is an entrance to another tunnel.\n";
        cout << "You can choose to: go to the tunnel (1) or go to the tunnel and take the sword with you (2).\n";
        do{
            cout << "You choose to: ";
            cin >> temp_value;
            if(temp_value != 1 && temp_value != 2){
                cout << "Invalid choice; enter 1 or 2.\n";
            }
        }while(temp_value != 1 && temp_value != 2);
        if(temp_value == 1){
            choice -= 3;
        }
        if(temp_value == 2){
            choice -= 3;
            sword = 0;
            excalibur = 1;
        }
    }
    else{
        cout << "\nYou see light at the end of the tunnel.\n";
        cout << "You come to the big cave opening where you found and took that sword.\n";
        cout << "At the opposite end of the cave is an entrance to another tunnel.\n";
        cout << "You can choose to: go to the tunnel (1).\n";
        do{
            cout << "You choose to: ";
            cin >> temp_value;
            if(temp_value != 1){
                cout << "Invalid choice; enter 1.\n";
            }
        }while(temp_value != 1);
        if(temp_value == 1){
            choice -= 3;
        }
    }
    return choice;
}
    // room 5 - dragon
int room_5(){
    int temp_value, choice = 5;
    cout << "\nAfter a great deal of time following the smelly tunnel, you neared what looked to be the end of it.\n";
    cout << "The more you ventured through it the warmer and smellier the tunnel became.\n";
    cout << "After turning a corner, you are initially blinded as you see a bright yellow light at the end of the tunnel.\n";
    cout << "You regain your vision and as you near, the light becomes brighter and brighter until you find yourself in a gigantic well-lit room surrounded by a great treasure of gold, precious gems, and rare artifacts.\n";
    cout << "You look in awe of the wonders around you.\n";
    cout << "You see another tunnel entrance at the opposite end of the room from where your standing.";
    cout << "As you venture in that direction, you near the top of a mountain of gold where you are taken aback when see you see \n\nA DRAGON!!!\n\n";
    cout << "The dragon notices you and roars and instantly starts breathing a stream of fire at you.\n";
    cout << "You jump away behind a pile of treasure just in time for the stream of fire to miss you.\n";
    cout << "Currently, you are near the entrance you came in from, and the dragon is blocking the entrance on the other side of the room.\n";
    cout << "You can choose to: stay and face the dragon as you fight your way over to the other entrance (1) or you can run back to the entrance you came in from (2).\n";
    do{
        cout << "You choose to: ";
        cin >> temp_value;
        if(temp_value != 1 && temp_value != 2){
                cout << "Invalid choice; enter 1 or 2.\n";
        }
    }while(temp_value != 1 && temp_value != 2);
    if(temp_value == 1 && excalibur == 1){
        choice += 1;
    }
    if(temp_value == 1 && excalibur == 0){
        choice += 2;
    }
    if(temp_value == 2){
        cout << "\nAfter running to the entrance and barely escaping the dragon, you run so far away you lose track of where you are.\n";
        choice -= 4;
    }
    return choice;
}
    // room 6 - exit and victory scene
int room_6(){
    int temp_value, choice = 6;
    cout << "\nYou face the dragon.\n";
    cout << "The sword you found proves very useful as it is light and enables your technique to be nimble.\n";
    cout << "After a long glorious battle that taxed your strength and tested your skill, you sleighed the dragon, triumphing over it, and emerging victorious.\n";
    cout << "After killing the dragon, you make your way over to the tunnel at the opposite far side of the room.\n";
    cout << "After following it for a brief amount of time, you see green and sunlight at the end of the tunnel.\n";
    cout << "As you make you way out, you take in the fresh air seeming so long since you last breathed it.\n";
    cout << "Once outside, you make your way atop a nearby hill so you can get an idea of where you are.\n";
    cout << "You embark on your journey back to the kingdom's castle so you can tell your father of the news of your adventure.\n";
    cout << "\nYou won the game!\n";
    choice += 10;
    return choice;
}
    // scene when torch light is gone because torch time runs out
void torch_light_gone(){
    cout << "\nThe flame from your torch burns out taking all light with it.\n";
    cout << "Without any light, you are doomed to wander aimlessly through the dark caves for eternity.\n";
    cout << "\nGame over.\n";
}
    // death scene case 7
int death(){
    int temp_value, choice = 7;
    cout << "\nYou face the dragon.\n";
    cout << "After a long glorious battle, the dragon proved to worthy of an opponent and you die an honorable death of a chilvaric knight.\n";
    cout << "\nGame over.\n";
    choice += 10;
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
