#include "game_translate.h"
#include <iostream>

using namespace std;

void translatorMenu() {
    while (true) {
        cout << "\n===== DICH =====\n";
        cout << "1. Dich nhanh\n";
        cout << "2. Dich theo game\n";
        cout << "3. Lich su\n";
        cout << "0. Quay lai\n> ";

        int c;
        cin >> c;

        switch (c) {
            case 1:
                cout << "[Dich nhanh]\n";
                break;
            case 2:
                gameTranslateMenu();
                break;
            case 3:
                cout << "[Lich su]\n";
                break;
            case 0:
                return;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
        }
    }
}
