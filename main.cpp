#include<iostream>
#include<cstdlib>
#include<ctime>

#include "slot.h"
#include "game.h"
#include "player.h"

using namespace std;

int main(){

    srand(time(0));

    Player p;
    p.token = 100;
    p.maxToken = 100;
    p.roundPlayed = 0;

    while(p.token > 0){

        cout << "Token: " << p.token << endl;

        int bet;

        cout << "Bet: ";
        cin >> bet;

        if(bet > p.token){
            cout << "Not enough token\n";
            continue;
        }

        string slot[3];

        for(int i=0;i<3;i++)
            slot[i] = spin();

        showSlot(slot);

        int reward = checkReward(slot,bet);

        if(reward > 0)
            reward = doubleOrNothing(reward);

        p.token += reward;

        if(p.token > p.maxToken)
            p.maxToken = p.token;

        saveHistory(slot);

        p.roundPlayed++;
    }

    cout << "Game Over\n";
    cout << "Max Token: " << p.maxToken << endl;

}