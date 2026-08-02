#include "engine/translation_engine.h"

#include <iostream>

using namespace std;

void translationEngineMenu()
{
    while (true)
    {
        cout << "\n=========================================\n";
        cout << "          TRANSLATION ENGINE\n";
        cout << "=========================================\n";
        cout << "1. Scan Project\n";
        cout << "2. Scan APK\n";
        cout << "3. Scan Folder\n";
        cout << "4. Translate Text\n";
        cout << "5. Export Translation\n";
        cout << "6. Import Translation\n";
        cout << "7. Statistics\n";
        cout << "8. Translation Memory\n";
        cout << "9. AI Translation\n";
        cout << "0. Back\n";
        cout << "=========================================\n";
        cout << "Select : ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nScanning Project...\n";
            break;

        case 2:
            cout << "\nScanning APK...\n";
            break;

        case 3:
            cout << "\nScanning Folder...\n";
            break;

        case 4:
            cout << "\nTranslation Engine Ready.\n";
            break;

        case 5:
            cout << "\nExport completed.\n";
            break;

        case 6:
            cout << "\nImport completed.\n";
            break;

        case 7:
            cout << "\nStatistics Ready.\n";
            break;

        case 8:
            cout << "\nTranslation Memory Ready.\n";
            break;

        case 9:
            cout << "\nAI Translation Preparing...\n";
            break;

        case 0:
            return;

        default:
            cout << "\nInvalid selection.\n";
            break;
        }
    }
}
