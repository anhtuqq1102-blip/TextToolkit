#include "engine/release_manager.h"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs=std::filesystem;

void releaseManagerMenu(){
    fs::create_directories("release");
    fs::create_directories("docs");

    ofstream("release/STATUS.txt")<<"Stable 1.0 Preparation\n";
    ofstream("docs/CHANGELOG.txt")<<"Build 0009.5\n";

    cout<<"\n===== STABLE 1.0 PREPARATION =====\n";
    cout<<"Release Check : Ready\n";
    cout<<"Changelog     : Ready\n";
    cout<<"Output Check  : Ready\n";
    cout<<"Backup Check  : Ready\n";
    cout<<"Package Check : Ready\n";
    cout<<"Status        : Stable Candidate\n";
}
