#include "engine/xml_engine.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace fs = std::filesystem;

static bool isXml(const fs::path& file)
{
    return file.extension() == ".xml";
}

void xmlEngineMenu()
{
    string folder;

    cout << "\n=========================================\n";
    cout << "              XML ENGINE\n";
    cout << "=========================================\n";

    cout << "Folder : ";
    cin >> folder;

    if (!fs::exists(folder))
    {
        cout << "\nFolder not found.\n";
        return;
    }

    vector<fs::path> xmlFiles;

    for (auto& e : fs::recursive_directory_iterator(folder))
    {
        if (!e.is_regular_file())
            continue;

        if (isXml(e.path()))
            xmlFiles.push_back(e.path());
    }

    cout << "\n========== XML FILES ==========\n";
    cout << "Total : " << xmlFiles.size() << "\n\n";

    for (const auto& f : xmlFiles)
    {
        cout << f.string() << '\n';
    }

    cout << "\nXML Scan completed.\n";
}
