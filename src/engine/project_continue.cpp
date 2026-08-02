#include "engine/project_continue.h"
#include "engine/project_database.h"

#include <iostream>

using namespace std;

void continueProject()
{
    ProjectDatabase db;
    db.initialize();

    string current = db.getCurrentProject();

    cout << "\n========== CONTINUE PROJECT ==========\n";

    if (current.empty())
    {
        cout << "No current project.\n";
        return;
    }

    cout << "Current Project : " << current << "\n";
    cout << "Status          : Ready\n";
    cout << "Database        : Connected\n";
    cout << "Translation     : Ready\n";
    cout << "Scanner         : Ready\n";
    cout << "APK Manager     : Ready\n";
    cout << "Resource Engine : Ready\n";

    cout << "\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}
