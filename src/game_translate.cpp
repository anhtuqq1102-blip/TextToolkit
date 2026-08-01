#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void gameTranslateMenu(){
    ifstream in("config/project.txt");
    string apk;
    getline(in, apk);
    cout << "\n===== DICH THEO GAME =====\n";
    if(apk.empty()){
        cout << "Chua chon du an.\n";
        return;
    }
    cout << "Du an:\n" << apk << "\n";
    cout << "Dang chuan bi quet tep...\n";
}
