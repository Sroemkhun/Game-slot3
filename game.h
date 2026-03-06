#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <string>

void playGame(Player &p);
void saveHistory(std::string r[3]);
void doubleOrNothing(int &reward);

#endif