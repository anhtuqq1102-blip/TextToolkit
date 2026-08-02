#include "engine/project_about.h"

#include <iostream>

using namespace std;

void projectAbout()
{
    cout << "\n";
    cout << "=========================================\n";
    cout << "            TEXTTOOLKIT v0014.1\n";
    cout << "=========================================\n";
    cout << "Project Name : TextToolkit\n";
    cout << "Version      : v0014.1\n";
    cout << "Language     : C++17\n";
    cout << "Build System : CMake\n";
    cout << "IDE          : Visual Studio 2026\n";
    cout << "Platform     : Windows\n";
    cout << "Repository   : GitHub\n";
    cout << "=========================================\n";
    cout << "Modules\n";
    cout << "-----------------------------------------\n";
    cout << "[OK] Project Manager\n";
    cout << "[OK] Project Database\n";
    cout << "[OK] Create Project\n";
    cout << "[OK] Delete Project\n";
    cout << "[OK] Rename Project\n";
    cout << "[OK] Select Project\n";
    cout << "[OK] Recent Project\n";
    cout << "[OK] Continue Project\n";
    cout << "[OK] Backup Project\n";
    cout << "[OK] Restore Project\n";
    cout << "[OK] Settings\n";
    cout << "[ ] APK Decode\n";
    cout << "[ ] APK Build\n";
    cout << "[ ] XML Engine\n";
    cout << "[ ] JSON Engine\n";
    cout << "[ ] Binary Scanner\n";
    cout << "[ ] Translation Engine\n";
    cout << "[ ] AI Translation\n";
    cout << "=========================================\n";
    cout << "\nPress ENTER...";
    cin.ignore();
    cin.get();
}
