#include "game.h"
#include "slot.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void saveHistory(string r[3]){

    ofstream file("history.txt",ios::app);

    file<<r[0]<<" "<<r[1]<<" "<<r[2]<<endl;
}

void doubleOrNothing(int &reward){

    char choice;

    cout<<"Double or Nothing? (y/n): ";
    cin>>choice;

    if(choice=='y'){

        int r=rand()%10;

        if(r%2==0){
            reward*=2;
            cout<<"Lucky! Reward doubled\n";
        }
        else{
            reward=0;
            cout<<"Lose everything!\n";
        }
    }
}

void playGame(Player &p){

    string slot[3];

    int bossBank=500;

    char play;

    while(p.token>0 && bossBank>0){

        cout<<"\nToken: "<<p.token<<endl;
        cout<<"Boss money: "<<bossBank<<endl;

        cout<<"Play? (y/n): ";
        cin>>play;

        if(play!='y')
            break;

        int bet;

        cout<<"Bet token: ";
        cin>>bet;

        if(bet>p.token){

            cout<<"Not enough token\n";
            continue;
        }

        spinSlot(slot);

        saveHistory(slot);

        int reward=0;

        if(slot[0]==slot[1] && slot[1]==slot[2]){

            if(slot[0]=="7"){

                reward=bet*10;
                cout<<"777 JACKPOT!!!\n";

            }else{

                reward=bet*5;
                cout<<"Triple match!\n";
            }

        }
        else if(slot[0]==slot[1] || slot[1]==slot[2] || slot[0]==slot[2]){

            reward=bet*2;
            cout<<"Double match!\n";

        }
        else{

            reward=-bet;
            cout<<"Lose\n";
        }

        if(reward>0)
            doubleOrNothing(reward);

        p.token+=reward;

        bossBank-=reward;

        if(p.token>p.maxToken)
            p.maxToken=p.token;

        p.round++;

        if(p.round%5==0){

            cout<<"Lucky Level! +20 token\n";
            p.token+=20;
        }
    }

    cout<<"\nGame Over\n";
    cout<<"Max token: "<<p.maxToken<<endl;
}