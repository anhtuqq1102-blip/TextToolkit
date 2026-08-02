#include "engine/translation_export.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void exportTranslationMenu()
{
    fs::create_directories("translation");

    string source = "translation/memory.db";
    string output = "translation/export.txt";

    cout << "\n=========================================\n";
    cout << "        TRANSLATION EXPORT\n";
    cout << "=========================================\n";

    if (!fs::exists(source))
    {
        cout << "No translation database.\n";
        return;
    }

    ifstream in(source);

    ofstream out(output);

    string line;

    while (getline(in, line))
    {
        out << line << '\n';
    }

    in.close();
    out.close();

    cout << "Export completed.\n";
    cout << "File: " << output << "\n";
}
