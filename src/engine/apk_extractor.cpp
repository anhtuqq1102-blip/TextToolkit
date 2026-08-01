#include "apk_extractor.h"
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs=std::filesystem;

void apkExtractorMenu(){
    fs::create_directories("workspace");
    cout<<"\n===== APK EXTRACTOR =====\n";
    cout<<"AndroidManifest.xml : Ready\n";
    cout<<"resources.arsc      : Ready\n";
    cout<<"classes.dex         : Ready\n";
    cout<<"assets/             : Ready\n";
    cout<<"lib/                : Ready\n";
    cout<<"res/                : Ready\n";
    cout<<"Progress            : Ready\n";
    cout<<"Extract Engine      : Placeholder\n";
}
