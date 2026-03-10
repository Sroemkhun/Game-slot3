#include<iostream>
#include "slot.h"

using namespace std;

string spin(){

    int r = rand()%100;

    if(r < 5) return "7";
    else if(r < 25) return "A";
    else if(r < 45) return "฿";
    else if(r < 70) return "@";
    else return "Cherry";
}

void showSlot(string s[3]){

    cout << "----------------\n";
    cout << "| " << s[0] << " | " << s[1] << " | " << s[2] << " |\n";
    cout << "----------------\n";
}

int checkReward(string s[3], int bet){

    if(s[0]==s[1] && s[1]==s[2]){

        if(s[0]=="7"){
            cout << "SUPER JACKPOT\n";
            return bet*10;
        }

        cout << "JACKPOT\n";
        return bet*5;
    }

    if(s[0]==s[1] || s[0]==s[2] || s[1]==s[2]){
        cout << "Match 2\n";
        return bet*2;
    }

    cout << "Lose\n";
    return -bet;
}