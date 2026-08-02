#include "engine/repack_v2.h"
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace std;
namespace fs=std::filesystem;

void repackV2Menu(){
    fs::create_directories("output");
    fs::create_directories("signed");
    ofstream("output/README.txt")<<"Output APK\n";
    ofstream("signed/README.txt")<<"Signed APK\n";
    cout<<"\n===== APK REPACK V2 =====\n";
    cout<<"APK Repack : Ready\n";
    cout<<"ZIP        : Ready\n";
    cout<<"Sign APK   : Placeholder\n";
    cout<<"Verify     : Ready\n";
    cout<<"Output     : output/\n";
}
