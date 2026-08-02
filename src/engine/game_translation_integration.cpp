#include "engine/game_translation_integration.h"
#include <fstream>
#include <iostream>
using namespace std;

bool startGameTranslation(){
    ifstream in("projects/current_project.txt");
    string project;
    getline(in, project);

    if(project.empty()){
        cout << "[Game Translation] Chua chon du an.\n";
        return false;
    }

    cout << "\n===== GAME TRANSLATION =====\n";
    cout << "Project : " << project << "\n";
    cout << "Status  : Ready\n";
    cout << "Next    : Resource Scan\n";
    return true;
}
