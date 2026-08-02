#include <filesystem>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
namespace fs=std::filesystem;

void fileListMenu(){
    string dir;
    // Try HOME (POSIX)
    {
        size_t requiredSize = 0;
        char buffer[1024];
        errno_t err = getenv_s(&requiredSize, buffer, sizeof(buffer), "HOME");
        if (err == 0 && requiredSize > 0) {
            dir = string(buffer) + "/storage/downloads";
        }
    }
    // If not set, try USERPROFILE (Windows)
    if (dir.empty()) {
        size_t requiredSize = 0;
        char buffer[1024];
        errno_t err = getenv_s(&requiredSize, buffer, sizeof(buffer), "USERPROFILE");
        if (err == 0 && requiredSize > 0) {
            dir = string(buffer) + "\\storage\\downloads";
        }
    }
    // Fallback to current directory
    if (dir.empty()) dir = ".";

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
