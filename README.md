# Game-slot3
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

struct Player {
    int token;
    int maxToken;
    int round;
};

int main() {

    srand(time(0));

    Player p;
    p.token = 100;
    p.maxToken = 100;
    p.round = 0;

    int boss = 100;
    int bet, choice;

    const string symbol[5] = {"7","A","฿","@","Cherry"};
    string history[100];   // array เก็บประวัติย้อนหลัง
    int historyIndex = 0;

    // ===== โหลดไฟล์ =====
    ifstream load("save.txt");
    if(load){
        load >> p.token >> p.maxToken >> p.round >> boss;
        load.close();
        cout << "Loaded previous game data.\n";
    }

    while(p.token > 0 && boss > 0) {

        cout << "\nToken: " << p.token << " | Boss: " << boss << endl;
        cout << "Play? (1=Yes 2=No): ";
        cin >> choice;

        if(choice != 1)
            break;

        cout << "Enter bet: ";
        cin >> bet;

        if(bet <= 0 || bet > p.token){
            cout << "Invalid bet!\n";
            continue;
        }

        p.round++;

        // ===== สุ่มแบบ 7 ออกยาก =====
        int r1 = rand()%100;
        int r2 = rand()%100;
        int r3 = rand()%100;

        int s1 = (r1<5)?0:(r1<30)?1:(r1<55)?2:(r1<75)?3:4;
        int s2 = (r2<5)?0:(r2<30)?1:(r2<55)?2:(r2<75)?3:4;
        int s3 = (r3<5)?0:(r3<30)?1:(r3<55)?2:(r3<75)?3:4;

        cout << "Result: "
             << symbol[s1] << " | "
             << symbol[s2] << " | "
             << symbol[s3] << endl;

        // บันทึกประวัติ
        history[historyIndex++] =
            symbol[s1] + string("-") +
            symbol[s2] + string("-") +
            symbol[s3];

        int reward = 0;

        // ===== ตรวจผล =====
        if(s1==s2 && s2==s3){
            if(s1==0){ // 7,7,7
                reward = bet * 10;
                cout << "SUPER JACKPOT 7,7,7 !!!\n";
            }
            else{
                reward = bet * 5;
                cout << "Jackpot!\n";
            }
        }
        else if(s1==s2 || s2==s3 || s1==s3){
            reward = bet * 2;
            cout << "Two matched!\n";
        }
        else{
            reward = -bet;
            cout << "You lose!\n";
        }

        // ===== Double or Nothing =====
        if(reward > 0){
            cout << "Double or Nothing? (1=Yes 2=No): ";
            cin >> choice;

            if(choice==1){
                int d = rand()%10;
                if(d%2==0){
                    reward *= 2;
                    cout << "Double Success!\n";
                }
                else{
                    reward = 0;
                    cout << "Lost everything!\n";
                }
            }
        }

        p.token += reward;
        boss -= reward;

        if(p.token > p.maxToken)
            p.maxToken = p.token;

        // ===== Lucky Level =====
        if(p.round % 5 == 0){
            cout << "Lucky Level Bonus +20 Tokens!\n";
            p.token += 20;
        }
    }

    if(p.token <= 0)
        cout << "\nGame Over! You are bankrupt!\n";
    else if(boss <= 0)
        cout << "\nYou defeated the Boss!\n";

    // ===== แสดงประวัติย้อนหลัง =====
    cout << "\n--- History ---\n";
    for(int i=0;i<historyIndex;i++)
        cout << history[i] << endl;

    cout << "\nMax Token: " << p.maxToken << endl;
    cout << "Total Rounds: " << p.round << endl;

    // ===== บันทึกไฟล์ =====
    ofstream save("save.txt");
    save << p.token << " "
         << p.maxToken << " "
         << p.round << " "
         << boss;
    save.close();

    cout << "Game Saved.\n";

    return 0;
}