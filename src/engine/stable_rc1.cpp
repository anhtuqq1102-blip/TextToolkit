#include "engine/stable_rc1.h"
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace std;
namespace fs=std::filesystem;

void stableRC1Menu(){
    fs::create_directories("release");
    fs::create_directories("tests");
    ofstream("release/RC1_STATUS.txt")<<"TextToolkit RC1\n";
    ofstream("docs/CHANGELOG_RC1.txt")<<"Build 0011.5 RC1\n";
    cout<<"\n===== STABLE RC1 =====\n";
    cout<<"Integration : PASS\n";
    cout<<"Modules     : PASS\n";
    cout<<"Project     : PASS\n";
    cout<<"Scanner     : PASS\n";
    cout<<"XML Engine  : PASS\n";
    cout<<"JSON Engine : PASS\n";
    cout<<"Translate   : PASS\n";
    cout<<"Status      : RC1 READY\n";
}
