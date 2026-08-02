#include "engine/project_rename.h"
#include "engine/project_database.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void renameProject()
{
    ProjectDatabase db;
    db.initialize();

    vector<ProjectInfo> list = db.getProjects();

    if (list.empty())
    {
        cout << "\nNo project.\n";
        return;
    }

    cout << "\n========== RENAME PROJECT ==========\n";

    for (size_t i = 0; i < list.size(); ++i)
    {
        cout << i + 1 << ". "
            << list[i].name
            << '\n';
    }

    cout << "\nSelect : ";

    int id;
    cin >> id;

    if (id < 1 || id >(int)list.size())
        return;

    string newName;

    cout << "New name : ";
    cin >> newName;

    db.renameProject(list[id - 1].name, newName);

    cout << "\nRenamed successfully.\n";
}
