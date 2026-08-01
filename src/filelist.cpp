#include <filesystem>
#include <iostream>
#include <vector>
using namespace std;
namespace fs=std::filesystem;

void fileListMenu(){
    string dir=string(getenv("HOME"))+"/storage/downloads";
    cout<<"\n===== TAP TIN HO TRO =====\n";
    int i=1;
    for(auto &e:fs::directory_iterator(dir)){
        if(!e.is_regular_file()) continue;
        string ext=e.path().extension().string();
        if(ext==".apk"||ext==".zip"||ext==".rar")
            cout<<i++<<". "<<e.path().filename().string()<<"\n";
    }
    if(i==1) cout<<"Khong tim thay APK/ZIP/RAR\n";
}
