#include "apk_decode.h"
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs=std::filesystem;

void apkDecodeMenu(){
    fs::create_directories("workspace/decode");
    cout<<"\n===== APK DECODE ENGINE =====\n";
    cout<<"Input APK        : Ready\n";
    cout<<"Decode Workspace : workspace/decode/\n";
    cout<<"AndroidManifest  : Detect\n";
    cout<<"resources.arsc   : Detect\n";
    cout<<"classes.dex      : Detect\n";
    cout<<"assets/          : Detect\n";
    cout<<"res/             : Detect\n";
    cout<<"Decode Engine    : Placeholder\n";
}
