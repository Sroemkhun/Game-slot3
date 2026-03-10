#include <iostream>
#include "game.h"
#include "slot.h"

using namespace std;

void playGame(Player &player)
{
    while(player.token > 0)
    {
        int bet;

        cout<<"\nToken : "<<player.token<<endl;
        cout<<"Bet : ";
        cin>>bet;

        if(bet > player.token)
        {
            cout<<"Not enough token\n";
            continue;
        }

        player.token -= bet;

        string s1 = spinSlot();
        string s2 = spinSlot();
        string s3 = spinSlot();

        cout<<"["<<s1<<"] ["<<s2<<"] ["<<s3<<"]\n";

        if(s1==s2 && s2==s3)
        {
            cout<<"JACKPOT!\n";
            player.token += bet*5;
        }
        else if(s1==s2 || s2==s3 || s1==s3)
        {
            cout<<"WIN!\n";
            player.token += bet*2;
        }
        else
        {
            cout<<"LOSE\n";
        }

        player.round++;
    }

    cout<<"\nGame Over\n";
}