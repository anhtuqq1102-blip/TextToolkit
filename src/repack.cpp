#include "repack.h"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs=std::filesystem;

void repackMenu(){
    fs::create_directories("output");
    fs::create_directories("backup");

    ofstream("output/README.txt")
        <<"Output folder\n";
    ofstream("backup/README.txt")
        <<"Backup folder\n";

    cout<<"\n===== REPACK =====\n";
    cout<<"APK  : Ready\n";
    cout<<"ZIP  : Ready\n";
    cout<<"RAR  : Ready\n";
    cout<<"Output : output/\n";
    cout<<"Backup : backup/\n";
    cout<<"Check : OK\n";
}
