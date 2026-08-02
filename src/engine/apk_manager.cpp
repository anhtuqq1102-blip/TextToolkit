#include "engine/apk_manager.h"

#include <iostream>

using namespace std;

void apkManagerMenu()
{
    while (true)
    {
        cout << "\n=========================================\n";
        cout << "              APK MANAGER\n";
        cout << "=========================================\n";
        cout << "1. Open APK\n";
        cout << "2. Decode APK\n";
        cout << "3. Build APK\n";
        cout << "4. Sign APK\n";
        cout << "5. Install APK\n";
        cout << "6. APK Information\n";
        cout << "7. Extract Resources\n";
        cout << "8. Extract Manifest\n";
        cout << "9. Back\n";
        cout << "=========================================\n";
        cout << "Select : ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nOpen APK...\n";
            break;

        case 2:
            cout << "\nDecode APK...\n";
            break;

        case 3:
            cout << "\nBuild APK...\n";
            break;

        case 4:
            cout << "\nSign APK...\n";
            break;

        case 5:
            cout << "\nInstall APK...\n";
            break;

        case 6:
            cout << "\nReading APK Information...\n";
            break;

        case 7:
            cout << "\nExtracting Resources...\n";
            break;

        case 8:
            cout << "\nExtracting AndroidManifest.xml...\n";
            break;

        case 9:
            return;

        default:
            cout << "\nInvalid selection.\n";
            break;
        }
    }
}
