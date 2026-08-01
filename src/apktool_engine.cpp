#include "apktool_engine.h"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs=std::filesystem;

void apktoolEngineMenu(){
    fs::create_directories("workspace");
    fs::create_directories("output");
    fs::create_directories("signed");

    cout<<"\n===== APKTOOL ENGINE =====\n";
    cout<<"APKTool Integration : READY\n";
    cout<<"Decode APK          : Placeholder\n";
    cout<<"Build APK           : Placeholder\n";
    cout<<"Sign APK            : Placeholder\n";
    cout<<"Verify APK          : READY\n";
    cout<<"Workspace           : workspace/\n";
    cout<<"Output              : output/\n";
}
