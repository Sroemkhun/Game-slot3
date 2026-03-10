#include "game.h"
#include "slot.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

void saveHistory(string r[3]){
    ofstream file("history.txt", ios::app);
    file << r[0] << " " << r[1] << " " << r[2] << endl;
}

void showSlot(string r[3]){
    cout << "-----------------\n";
    cout << r[0] << " | " << r[1] << " | " << r[2] << endl;
    cout << "-----------------\n";
}

int checkReward(string r[3], int bet){

    if(r[0] == r[1] && r[1] == r[2]){

        if(r[0] == "7"){
            cout << "JACKPOT 777 !!!\n";
            return bet * 10;
        }

        cout << "Triple Match!\n";
        return bet * 5;
    }

    else if(r[0] == r[1] || r[1] == r[2] || r[0] == r[2]){
        cout << "Double match!\n";
        return bet * 2;
    }

    cout << "Lose\n";
    return -bet;
}

int doubleOrNothing(int reward, int bet){

    char choice;
    cout << "Double or Nothing? (y/n): ";
    cin >> choice;

    if(choice != 'y'){
        return reward;
    }

    int n = rand() % 10;

    if(n % 2 == 0){
        cout << "Lucky! Reward x2\n";
        return reward * 2;
    }
    else{
        cout << "Lose everything!\n";
        return -(bet * 2);
    }
}

void playGame(){

    int token = 100;
    int round = 0;

    while(token > 0){

        cout << "\nToken: " << token << endl;

        char play;
        cout << "Play? (y/n): ";
        cin >> play;

        if(play != 'y'){
            break;
        }

        int bet;
        cout << "Bet token: ";
        cin >> bet;

        if(bet > token){
            cout << "Not enough token\n";
            continue;
        }

        cout << "\nSpinning...\n";
        this_thread::sleep_for(chrono::milliseconds(500));

        string result[3];

        spinSlot(result);

        cout << "Result: ["
            << result[0] << " | "
            << result[1] << " | "
            << result[2] << "]\n";

        int reward = checkReward(result, bet);

        if(reward > 0){
            reward = doubleOrNothing(reward, bet);
        }

        token += reward;

        saveHistory(result);

        round++;

        if(round % 5 == 0){
            cout << "Lucky Level Bonus +10 token\n";
            token += 10;
        }
    }

    cout << "\nGame Over\n";
}