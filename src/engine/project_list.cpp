#include "engine/project_list.h"
#include "engine/project_database.h"

#include <iostream>
#include <vector>

using namespace std;

void listProjects()
{
    ProjectDatabase db;
    db.initialize();

    vector<ProjectInfo> list = db.getProjects();

    cout << "\n========== PROJECT LIST ==========\n";

    if (list.empty())
    {
        cout << "No projects.\n";
        return;
    }

    for (size_t i = 0; i < list.size(); ++i)
    {
        cout << i + 1 << ". " << list[i].name << "\n";
        cout << "   " << list[i].path << "\n";
    }

    cout << "==================================\n";
}
