#include "engine/translation_search.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void translationSearchMenu()
{
    string keyword;

    cout << "\n=========================================\n";
    cout << "        TRANSLATION SEARCH\n";
    cout << "=========================================\n";

    cout << "Keyword : ";
    cin >> keyword;

    ifstream in("translation/memory.db");

    if (!in)
    {
        cout << "\nTranslation database not found.\n";
        return;
    }

    string line;
    bool found = false;

    cout << "\n========== RESULT ==========\n";

    while (getline(in, line))
    {
        if (line.find(keyword) != string::npos)
        {
            cout << line << '\n';
            found = true;
        }
    }

    if (!found)
    {
        cout << "No result.\n";
    }

    cout << "============================\n";
}
