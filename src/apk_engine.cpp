#include "apk_engine.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;
using namespace std;

void apkEngineMenu(){
    fs::create_directories("workspace");
    fs::create_directories("output");
    fs::create_directories("backup");

    cout << "\n===== APK ENGINE =====\n";
    cout << "Workspace : Ready\n";
    cout << "Extract   : Placeholder\n";
    cout << "Scan      : Ready\n";
    cout << "Repack    : Placeholder\n";
    cout << "Output    : output/\n";
}
