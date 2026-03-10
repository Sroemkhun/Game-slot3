#include "slot.h"
#include <cstdlib>

using namespace std;

string spinSlot()
{
    string symbols[] = {"7","A","Cherry","@","$"};

    int r = rand()%5;

    return symbols[r];
}