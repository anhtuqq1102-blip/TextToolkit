#include "engine/apk_decode_real.h"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs=std::filesystem;

bool decodeApk(const string& apkPath){
    fs::create_directories("workspace/decode");
    if(!fs::exists(apkPath)){
        cout<<"APK not found\n";
        return false;
    }
    ofstream("workspace/decode/session.txt")
        <<"INPUT="<<apkPath<<"\n";
    cout<<"\n===== APK DECODE =====\n";
    cout<<"Input : "<<apkPath<<"\n";
    cout<<"Workspace : workspace/decode/\n";
    cout<<"Session saved.\n";
    cout<<"Ready for real decoder integration.\n";
    return true;
}
