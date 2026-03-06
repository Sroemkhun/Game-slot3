#include <iostream>
#include "ui.h"

using namespace std;

void printSlot(string a, string b, string c)
{
    cout << "╔══════════════════════╗\n";
    cout << "║      SLOT MACHINE    ║\n";
    cout << "╠══════╦══════╦═══════╣\n";
    cout << "║  " << a << "  ║  " << b << "  ║  " << c << "   ║\n";
    cout << "╠══════╩══════╩═══════╣\n";
    cout << "║   🎰 SPIN RESULT 🎰  ║\n";
    cout << "╚══════════════════════╝\n";
}