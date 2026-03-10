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
    cout << "\n";
    cout << "| " << r[0] << " | " << r[1] << " | " << r[2] << " |\n";
}

void doubleOrNothing(int &reward){
    char choice;
    cout << "Double or Nothing? Lose everything! (y/n): ";
    cin >> choice;

    if(choice == 'y' || choice == 'Y'){
        int r = rand() % 10;
        if(r < 3){ 
            reward *= 2;
            cout << "Lucky! Reward doubled!\n";
        }
        else {

            reward = -(reward * 2); 
            cout << "Lose everything! Double Penalty!\n";
        }
    }
}

void playGame(Player &p){
    string slot[3];
    int bossBank = 500;
    char play;

    while(p.token > 0 && bossBank > 0){
        cout << "\n========================\n";
        cout << "Token: " << p.token << endl;
        cout << "Boss money: " << bossBank << endl;
        cout << "Play? (y/n): ";
        cin >> play;
        if(play != 'y' && play != 'Y') break;
        int bet;
        cout << "Bet token: ";
        cin >> bet;
        if(bet > p.token){
            cout << "Not enough token\n";
            continue;
        }
        p.token -= bet;
        cout << "\nSpinning...\n";
        this_thread::sleep_for(chrono::milliseconds(700));
        spinSlot(slot);
        showSlot(slot);
        saveHistory(slot);
        int reward = 0;
        if(slot[0] == slot[1] && slot[1] == slot[2]){
            if(slot[0] == "7") reward = bet * 10;
            else reward = bet * 5;
            cout << "Triple match!\n";
        }
        else if(slot[0] == slot[1] || slot[1] == slot[2] || slot[0] == slot[2]){
            reward = bet * 2;
            cout << "Double match!\n";
        }
        else {
            reward = -bet;
            cout << "Lose!\n";
        }
        if(reward > 0) {
            doubleOrNothing(reward);
        }
        p.token += reward;
        bossBank -= reward;
        cout << "Result Score: " << reward << endl;
        if(p.token > p.maxToken) p.maxToken = p.token;
        p.round++;
        if(p.round % 5 == 0){
            cout << "Lucky Level! +20 token\n";
            p.token += 20;
        }
    }
    cout << "\nGame Over\n";
    cout << "Max token: " << p.maxToken << endl;
}