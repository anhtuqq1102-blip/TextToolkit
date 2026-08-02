#include "engine/translation_import.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void importTranslationMenu()
{
    fs::create_directories("translation");

    string input;

    cout << "\n=========================================\n";
    cout << "        TRANSLATION IMPORT\n";
    cout << "=========================================\n";

    cout << "File : ";
    cin >> input;

    if (!fs::exists(input))
    {
        cout << "\nFile not found.\n";
        return;
    }

    ifstream in(input);

    ofstream out(
        "translation/memory.db",
        ios::app
    );

    string line;

    while (getline(in, line))
    {
        if (!line.empty())
        {
            out << line << '\n';
        }
    }

    in.close();
    out.close();

    cout << "\nImport completed.\n";
}
