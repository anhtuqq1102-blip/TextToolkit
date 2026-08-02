#include "engine/apk_rebuild_sign.h"
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs=std::filesystem;

void apkRebuildSignMenu(){
    fs::create_directories("rebuild");
    fs::create_directories("signed");
    fs::create_directories("output");
    cout<<"\n===== APK REBUILD & SIGN =====\n";
    cout<<"Rebuild APK : Placeholder\n";
    cout<<"Sign APK    : Placeholder\n";
    cout<<"Verify APK  : Ready\n";
    cout<<"Output APK  : output/\n";
    cout<<"Signed APK  : signed/\n";
}
