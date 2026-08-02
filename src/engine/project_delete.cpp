#include "engine/project_delete.h"
#include "engine/project_database.h"

#include <iostream>
#include <vector>

using namespace std;

void deleteProject()
{
    ProjectDatabase db;
    db.initialize();

    vector<ProjectInfo> list = db.getProjects();

    if (list.empty())
    {
        cout << "\nNo project.\n";
        return;
    }

    cout << "\n========== DELETE PROJECT ==========\n";

    for (size_t i = 0; i < list.size(); ++i)
    {
        cout << i + 1 << ". " << list[i].name << '\n';
    }

    cout << "\nDelete : ";

    int id;
    cin >> id;

    if (id < 1 || id >(int)list.size())
        return;

    db.deleteProject(list[id - 1].name);

    cout << "\nDeleted : "
        << list[id - 1].name
        << "\n";
}
