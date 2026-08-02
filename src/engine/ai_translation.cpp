#include "engine/ai_translation.h"
#include "engine/translation_memory.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
namespace fs = std::filesystem;

static unordered_map<string, string> memory;

static void loadMemory()
{
    memory.clear();

    fs::create_directories("translation");

    ifstream in("translation/memory.db");

    string line;

    while (getline(in, line))
    {
        size_t pos = line.find('|');

        if (pos == string::npos)
            continue;

        string src = line.substr(0, pos);
        string dst = line.substr(pos + 1);

        memory[src] = dst;
    }
}

void aiTranslationMenu()
{
    loadMemory();

    while (true)
    {
        cout << "\n=========================================\n";
        cout << "            AI TRANSLATION\n";
        cout << "=========================================\n";
        cout << "1. Translate Text\n";
        cout << "2. Translate File\n";
        cout << "3. Reload Memory\n";
        cout << "4. Memory Status\n";
        cout << "0. Back\n";
        cout << "=========================================\n";
        cout << "Select : ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cin.ignore();

            string text;

            cout << "Input : ";

            getline(cin, text);

            auto it = memory.find(text);

            if (it != memory.end())
            {
                cout << "\nResult : "
                    << it->second
                    << "\n";
            }
            else
            {
                cout << "\nNo translation found.\n";
            }

            break;
        }

        case 2:
        {
            cin.ignore();

            string file;

            cout << "File : ";

            getline(cin, file);

            ifstream in(file);

            if (!in)
            {
                cout << "\nCannot open file.\n";
                break;
            }

            string line;

            cout << '\n';

            while (getline(in, line))
            {
                auto it = memory.find(line);

                if (it != memory.end())
                    cout << it->second << '\n';
                else
                    cout << line << '\n';
            }

            break;
        }

        case 3:
            loadMemory();
            cout << "\nMemory reloaded.\n";
            break;

        case 4:
            cout << "\nEntries : "
                << memory.size()
                << "\n";
            break;

        case 0:
            return;

        default:
            cout << "\nInvalid selection.\n";
            break;
        }
    }
}
