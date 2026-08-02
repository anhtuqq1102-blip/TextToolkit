#include "engine/resource_scanner.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace fs = std::filesystem;

static bool isSupported(const fs::path& p)
{
    string ext = p.extension().string();

    return ext == ".xml" ||
        ext == ".json" ||
        ext == ".txt" ||
        ext == ".ini" ||
        ext == ".csv" ||
        ext == ".lua" ||
        ext == ".js" ||
        ext == ".yml" ||
        ext == ".yaml";
}

void resourceScannerMenu()
{
    string folder;

    cout << "\n=========================================\n";
    cout << "           RESOURCE SCANNER\n";
    cout << "=========================================\n";

    cout << "Folder : ";
    cin >> folder;

    if (!fs::exists(folder))
    {
        cout << "\nFolder not found.\n";
        return;
    }

    vector<fs::path> files;

    for (auto& e : fs::recursive_directory_iterator(folder))
    {
        if (!e.is_regular_file())
            continue;

        if (isSupported(e.path()))
            files.push_back(e.path());
    }

    cout << "\n========== RESULT ==========\n";
    cout << "Files : " << files.size() << "\n\n";

    for (const auto& f : files)
    {
        cout << f.string() << '\n';
    }

    cout << "\nScan completed.\n";
}
