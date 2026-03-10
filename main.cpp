#include <iostream>
#include <ctime>
#include <cstdlib>
#include "game.h"

using namespace std;

int main()
{
    srand(time(0));

    Player player;

    player.token = 100;
    player.maxToken = 100;
    player.round = 0;

    cout<<"====== SLOT MACHINE GAME ======\n";

    playGame(player);

    return 0;
}