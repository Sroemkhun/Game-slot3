#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "player.h"

using namespace std;

int main(){

    srand(time(0));

    Player player;

    player.token = 100;
    player.maxToken = 100;
    player.round = 0;

    cout << "===== SLOT MACHINE GAME =====\n";

    playGame(player);

    return 0;
}