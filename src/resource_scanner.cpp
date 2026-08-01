#include "resource_scanner.h"
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void resourceScannerMenu(){
    fs::create_directories("workspace/resources");
    cout << "\n===== RESOURCE SCANNER =====\n";
    cout << "strings.xml      : Detect\n";
    cout << "arrays.xml       : Detect\n";
    cout << "plurals.xml      : Detect\n";
    cout << "JSON             : Detect\n";
    cout << "TXT              : Detect\n";
    cout << "LUA              : Detect\n";
    cout << "Scan Workspace   : workspace/resources/\n";
    cout << "Scanner Engine   : Placeholder\n";
}
