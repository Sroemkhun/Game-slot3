#ifndef GAME_H
#define GAME_H

#include <string>
using namespace std;

void playGame();
int checkReward(string r[3], int bet);
int doubleOrNothing(int reward, int bet);
void saveHistory(string r[3]);
void showSlot(string r[3]);

#endif