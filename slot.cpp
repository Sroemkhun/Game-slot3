#include "slot.h"
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

string randomSymbol(){

    int r = rand()%10;

    if(r==0) return "7";
    if(r<3) return "Cherry";
    if(r<6) return "A";
    if(r<8) return "@";

    return "฿";
}

void spinSlot(string result[3]){

    string a="?",b="?",c="?";

    cout<<"\nSpinning...\n";

    for(int i=0;i<15;i++){

        a=randomSymbol();
        b=randomSymbol();
        c=randomSymbol();

        cout<<"\r["<<a<<" | "<<b<<" | "<<c<<"]"<<flush;

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout<<endl;

    for(int i=0;i<3;i++)
        result[i]=randomSymbol();

    cout<<"Result: ["<<result[0]<<" | "<<result[1]<<" | "<<result[2]<<"]\n";
}