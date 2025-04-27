        /*
        Andrew Plum
        CS 120-06
        Assignment #9
        10/22/21
        */

        // // I did all of the regular assignment. I did the middle and bottom bullet points of extra credit; I did not do the first bullet point of extra credit.

        /*
        This is a program where an array is used so you can have multiple pets.
        I also used my own previous pet assignment.
        */

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"pet.h"
using namespace std; // declaration of the pet class

int earn_money(int, pet[]);
int pet_show(int, pet[]);
int work_job();

int main(){

    srand(time(NULL));

    int choice = 0;
    int health_check;
    int size = 0;
    int money = 25;
    int earn_money_choice;
    int earn_money_again_choice;
    int random_event; // *** FOR EXTRA CREDIT ***

    // Ask the user how many pets they want

    cout << "How many pets do you want to have? Enter a positive integer between 1 and 100: ";
    do{
        cin >> size;
        if(size <= 1 || size >= 100){
            cout << "Enter a positive integer between 1 and 100: ";
        }
    }while(!(size >= 1 && size <= 100));

    // Create and initialize that many pets

    cin.ignore();
    pet herd[size];

    // Game loop:

    do{
        // Earn money loop *** EXTRA CREDIT ***
            cout << endl << "Money: $" << money << endl;
            if(money > 0){
                cout << "Do you want to earn money? \nIt is earned so you can take care of your pets, \nbut their health stats decline due to neglect while earning money.\nEnter \"1\" for yes or \"0\" for no: ";
                do{
                    cin >> earn_money_choice;
                    // code for earning money the first time
                    if(earn_money_choice == 1){
                        money += earn_money(size, herd);
                        for(int i = 0; i < size; i++){
                            herd[i].after_interaction();
                        }
                        // Use check_health to see if all of the pets are healthy
                        for(int i = 0; i < size; i++){
                            health_check = herd[i].check_health();
                            if(health_check == 1){
                                cout << "Your pet ";
                                herd[i].print_name();
                                cout << " has died." << endl;
                                cout << "Game over." << endl;
                                break;
                                break;
                            }
                        }
                    }
                }while(!(earn_money_choice == 0 || earn_money_choice == 1));
            }
        do{
            // code for earning money if you want to do it again
            if(earn_money_again_choice == 1){
                money += earn_money(size, herd);
                for(int i = 0; i < size; i++){
                    herd[i].after_interaction();
                }
                // Use check_health to see if all of the pets are healthy
                for(int i = 0; i < size; i++){
                    health_check = herd[i].check_health();
                    if(health_check == 1){
                        cout << "Your pet ";
                        herd[i].print_name();
                        cout << " has died." << endl;
                        cout << "Game over." << endl;
                        break;
                        break;
                    }
                }
            }
            cout << endl << "Money: $" << money << endl;
            if(money <= 0){
                earn_money_choice = 1;
                cout << "You must earn money so you can take care of your pets." << endl;
                money += earn_money(size, herd);
                    for(int i = 0; i < size; i++){
                        herd[i].after_interaction();
                    }
            }
            if(earn_money_choice == 1){
                cout << "Do you want to earn money again? Enter \"1\" for yes or \"0\" for no: ";
                do{
                    cin >> earn_money_again_choice;
                }while(!(earn_money_again_choice == 0 || earn_money_again_choice == 1));
            }
            if(earn_money_again_choice == 0){
                break;
            }
        }while(earn_money_again_choice == 1);

        // Print all of the pets stats so user knows which pet they want to interact with

        for(int i = 0; i < size; i++){
            herd[i].print();
        }

        // Ask the player which pet they want to interact with

        cout << endl;
        cout << "What pet do you want to interact with?" << endl;
        cout << "(0) Exit the game" << endl;
        for(int i = 0; i < size; i++){
            cout << "(" << i + 1 << ") ";
            herd[i].print_name();
            cout << endl;
        }
        cout << endl;
        do{
            cout << "You choose: ";
            cin >> choice;
            if(choice < 0 || choice > (size)){
                cout << "Enter a number between 0 and " << size << ": ";
            }
        }while(choice < 0 || choice > size);
        if(choice == 0){    // breaks do while loop and jumps to the end of the program
            break; // breaks out of game loop and ends game
        }

        // Have the player interact with that pet

        herd[choice - 1].interact();

        // Add 2 hunger and subtract 2 happy from every pet

        for(int i = 0; i < size; i++){
                herd[i].after_interaction();
        }
        money = money - 5;

        // Print all of the pets after the interaction has occurred

        for(int i = 0; i < size; i++){
            herd[i].print();
        }

        // Random event *** FOR EXTRA CREDIT ***

        random_event = rand() % 10 + 1;
        if(random_event == 9){
            cout << endl << "*** RANDOM EVENT ***" << endl << endl;
            cout << "Your pet ";
            int i = rand() % size;
            herd[i].print_name();
            cout << " found some money and brought it to you. You gain $25." << endl;
            money = money + 25;
        }
        if(random_event == 10){
            cout << endl << "*** RANDOM EVENT ***" << endl << endl;
            int i = rand() % size;
            herd[i].random_event();
        }

        // Use check_health to see if all of the pets are healthy

        for(int i = 0; i < size; i++){
            health_check = herd[i].check_health();
            if(health_check == 1){
                cout << "Your pet ";
                herd[i].print_name();
                cout << " has died." << endl;
                cout << "Game over." << endl;
                break;
                break;
            }
        }

        // If a pet died, or the player asked to quit, exit the loop, otherwise loop

    }while(choice != 0 && health_check != 1);

    // Print an appropriate exit message

    cout << "The program has ended." << endl;
    return 0;
}

// functions not a part of pet.h

    // earn money

int earn_money(int size, pet herd[]){
    int choice;
    int money;
    cout << "Do you want to earn money by: \n(1) Working a job for a consistent wage. \n(2) By taking one of your pets to a pet show with a chance to earn money. \nEnter \"1\" or \"2\": ";
    do{
        cin >> choice;
        if(!(choice > 0 && choice < 3)){
            cout << "Enter \"1\" or \"2\": ";
        }
    }while(!(choice > 0 && choice < 3));
    if(choice == 1){
        money = work_job();
    }
    if(choice == 2){
        money = pet_show(size, herd);
    }
    return money;
}

    // specific way to earn money through work_job() function

int work_job(){
    int money;
    cout << "You work a job for 5 hours and earn $25" << endl;
    money = 25;
    return money;
}

    // specific way to earn money through pet_show() function

int pet_show(int size, pet herd[]){
    int choice;
    int money;
    cout << "Which pet do you want to take to the pet show. Enter its corresponding number: " << endl;
    for(int i = 0; i < size; i++){
        cout << "(" << i + 1 << ") ";
        herd[i].print_name();
        cout << endl;
    }
    cout << endl;
    do{
        cout << "You choose to take: ";
        cin >> choice;
        if(choice < 0 || choice > (size)){
            cout << "Enter a number between 0 and " << size << ": ";
        }
    }while(choice < 0 || choice > size);
    money = rand() % 101;
    if(money <= 25){
        cout << "Your pet did not make it to the finals. Hopefully, it does better next time." << endl;
        cout << "Your pet earned $" << money << "." << endl;
    }
    if(25 < money && money <= 75){
        cout << "Your pet made it to the finals, but did not win." << endl;
        cout << "Your pet earned $" << money << "." << endl;
    }
    if(75 < money){
        cout << "Your pet made it to the finals, and almost won first place." << endl;
        cout << "Your pet earned $" << money << "." << endl;
    }
    if(money == 100){
        cout << "Your pet one first place! It did great!" << endl;
        cout << "Your pet earned $" << money << "." << endl;
    }
    return money;
}






