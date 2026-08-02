#include "engine/project_settings.h"

#include <iostream>

using namespace std;

void projectSettings()
{
    while (true)
    {
        cout << "\n========== SETTINGS ==========\n";
        cout << "1. Project Database\n";
        cout << "2. Backup Folder\n";
        cout << "3. Translation Engine\n";
        cout << "4. APK Decode\n";
        cout << "5. APK Build\n";
        cout << "6. Clear Cache\n";
        cout << "7. System Info\n";
        cout << "0. Back\n";
        cout << "==============================\n";
        cout << "Select : ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nDatabase : projects/projects.db\n";
            break;

        case 2:
            cout << "\nBackup : projects/backup/\n";
            break;

        case 3:
            cout << "\nTranslation Engine : Ready\n";
            break;

        case 4:
            cout << "\nAPK Decode : Ready\n";
            break;

        case 5:
            cout << "\nAPK Build : Ready\n";
            break;

        case 6:
            cout << "\nCache cleared.\n";
            break;

        case 7:
            cout << "\nTextToolkit v0014.1\n";
            cout << "Project Manager : Ready\n";
            cout << "Project Database : Ready\n";
            cout << "Backup System : Ready\n";
            cout << "Translation : Ready\n";
            cout << "Scanner : Ready\n";
            cout << "APK Manager : Preparing\n";
            break;

        case 0:
            return;

        default:
            cout << "\nInvalid selection.\n";
            break;
        }
    }
}
