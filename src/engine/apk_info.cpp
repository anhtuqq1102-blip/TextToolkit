#include "engine/apk_info.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void apkInfoMenu()
{
    string file;

    cout << "\n=========================================\n";
    cout << "              APK INFORMATION\n";
    cout << "=========================================\n";

    cout << "APK File : ";
    cin >> file;

    if (!fs::exists(file))
    {
        cout << "\nAPK not found.\n";
        return;
    }

    cout << "\n========== APK DETAILS ==========\n";
    cout << "Name : "
        << fs::path(file).filename().string()
        << "\n";

    cout << "Size : "
        << fs::file_size(file)
        << " bytes\n";

    cout << "Extension : "
        << fs::path(file).extension().string()
        << "\n";

    cout << "Status : Ready for decode\n";

    cout << "=================================\n";
}
