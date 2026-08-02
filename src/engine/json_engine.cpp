#include "engine/json_engine.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace fs = std::filesystem;

static bool isJson(const fs::path& file)
{
    return file.extension() == ".json";
}

void jsonEngineMenu()
{
    string folder;

    cout << "\n=========================================\n";
    cout << "             JSON ENGINE\n";
    cout << "=========================================\n";

    cout << "Folder : ";
    cin >> folder;

    if (!fs::exists(folder))
    {
        cout << "\nFolder not found.\n";
        return;
    }

    vector<fs::path> jsonFiles;

    for (const auto& entry : fs::recursive_directory_iterator(folder))
    {
        if (!entry.is_regular_file())
            continue;

        if (isJson(entry.path()))
            jsonFiles.push_back(entry.path());
    }

    cout << "\n========== JSON FILES ==========\n";
    cout << "Total : " << jsonFiles.size() << "\n\n";

    for (const auto& file : jsonFiles)
    {
        cout << file.string() << '\n';
    }

    cout << "\nJSON Scan completed.\n";
}
