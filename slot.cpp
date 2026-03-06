#include "slot.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

string symbol[5] = {"A","B","C","Cherry","7"};

void spinSlot(string r[3]){

    cout<<"Spinning...\n";

    for(int i=0;i<5;i++){
        cout<<"| "<<symbol[rand()%5]<<" | "<<symbol[rand()%5]<<" | "<<symbol[rand()%5]<<" |\r";
        Sleep(200);
    }

    for(int i=0;i<3;i++){
        r[i] = symbol[rand()%5];
    }

    cout<<"| "<<r[0]<<" | "<<r[1]<<" | "<<r[2]<<" |\n";
}