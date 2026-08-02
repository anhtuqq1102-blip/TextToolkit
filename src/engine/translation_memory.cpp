#include "engine/translation_memory.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

struct TranslationEntry
{
    string source;
    string target;
};

void translationMemoryMenu()
{
    fs::create_directories("translation");

    string database = "translation/memory.db";

    if (!fs::exists(database))
    {
        ofstream(database).close();
    }

    while (true)
    {
        cout << "\n=========================================\n";
        cout << "          TRANSLATION MEMORY\n";
        cout << "=========================================\n";
        cout << "1. List Memory\n";
        cout << "2. Add Entry\n";
        cout << "3. Search\n";
        cout << "4. Clear Memory\n";
        cout << "0. Back\n";
        cout << "=========================================\n";
        cout << "Select : ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ifstream in(database);

            string line;

            cout << "\n========== MEMORY ==========\n";

            while (getline(in, line))
            {
                cout << line << '\n';
            }

            break;
        }

        case 2:
        {
            cin.ignore();

            string source;
            string target;

            cout << "Source : ";
            getline(cin, source);

            cout << "Target : ";
            getline(cin, target);

            ofstream out(database, ios::app);

            out << source
                << '|'
                << target
                << '\n';

            cout << "\nSaved.\n";

            break;
        }

        case 3:
        {
            cin.ignore();

            string keyword;

            cout << "Keyword : ";

            getline(cin, keyword);

            ifstream in(database);

            string line;

            cout << '\n';

            while (getline(in, line))
            {
                if (line.find(keyword) != string::npos)
                {
                    cout << line << '\n';
                }
            }

            break;
        }

        case 4:
        {
            ofstream(database).close();

            cout << "\nMemory cleared.\n";

            break;
        }

        case 0:
            return;

        default:
            cout << "\nInvalid.\n";
            break;
        }
    }
}
