#include "engine/text_scanner.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

static bool isTextFile(const fs::path& file)
{
    string ext = file.extension().string();

    return ext == ".xml" ||
        ext == ".json" ||
        ext == ".txt" ||
        ext == ".ini" ||
        ext == ".lua" ||
        ext == ".csv" ||
        ext == ".js" ||
        ext == ".yaml" ||
        ext == ".yml";
}

void textScannerMenu()
{
    string folder;

    cout << "\n=========================================\n";
    cout << "             TEXT SCANNER\n";
    cout << "=========================================\n";

    cout << "Folder : ";
    cin >> folder;

    if (!fs::exists(folder))
    {
        cout << "\nFolder not found.\n";
        return;
    }

    vector<fs::path> files;

    for (const auto& entry : fs::recursive_directory_iterator(folder))
    {
        if (!entry.is_regular_file())
            continue;

        if (isTextFile(entry.path()))
            files.push_back(entry.path());
    }

    cout << "\n========== TEXT FILES ==========\n";
    cout << "Total : " << files.size() << "\n\n";

    for (const auto& file : files)
    {
        cout << file.string() << '\n';

        ifstream in(file);

        string line;

        while (getline(in, line))
        {
            if (line.empty())
                continue;

            cout << "    " << line << '\n';
        }

        cout << '\n';
    }

    cout << "Scan completed.\n";
}
