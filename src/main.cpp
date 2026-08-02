#include <iostream>

using namespace std;

void projectDashboard();
void openProjectMenu();
void createProject();

int main()
{
    while (true)
    {
        cout << "\n";
        cout << "=============================================\n";
        cout << "            TEXTTOOLKIT v0014.1\n";
        cout << "=============================================\n";
        cout << "1. Project Manager\n";
        cout << "2. Open Project\n";
        cout << "3. Translation\n";
        cout << "4. APK Tools\n";
        cout << "5. Scanner\n";
        cout << "6. Settings\n";
        cout << "7. About\n";
        cout << "0. Exit\n";
        cout << "=============================================\n";
        cout << "Select : ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            while (true)
            {
                projectDashboard();

                cout << "\n";
                cout << "1. Create Project\n";
                cout << "2. Refresh\n";
                cout << "0. Back\n";
                cout << "Select : ";

                int c;
                cin >> c;

                if (c == 0)
                    break;

                if (c == 1)
                    createProject();
            }

            break;
        }

        case 2:
            openProjectMenu();
            break;

        case 3:
        {
            int t;

            while (true)
            {
                cout << "\n";
                cout << "=====================================\n";
                cout << "        TRANSLATION MODULE\n";
                cout << "=====================================\n";
                cout << "1. Scan Text\n";
                cout << "2. Translate Project\n";
                cout << "3. Export Language File\n";
                cout << "0. Back\n";
                cout << "=====================================\n";
                cout << "Select : ";

                cin >> t;

                if (t == 0)
                    break;

                switch (t)
                {
                case 1:
                    cout << "\n[Scan Text]\n";
                    break;

                case 2:
                    cout << "\n[Translate Project]\n";
                    break;

                case 3:
                    cout << "\n[Export Language File]\n";
                    break;

                default:
                    cout << "\nInvalid selection.\n";
                    break;
                }
            }

            break;
        }

        case 4:
            cout << "\n[APK Tools]\n";
            break;

        case 5:
            cout << "\n[Scanner]\n";
            break;

        case 6:
            cout << "\n[Settings]\n";
            break;

        case 7:
            cout << "\n";
            cout << "TextToolkit v0014.1\n";
            cout << "Developed with ChatGPT\n";
            break;

        case 0:
            return 0;

        default:
            cout << "\nInvalid selection.\n";
            break;
        }
    }

    return 0;
}
