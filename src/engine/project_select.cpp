#include "engine/project_select.h"
#include "engine/project_database.h"

#include <iostream>
#include <vector>

using namespace std;

void selectProject()
{
    ProjectDatabase db;
    db.initialize();

    vector<ProjectInfo> list = db.getProjects();

    if (list.empty())
    {
        cout << "\nNo project.\n";
        return;
    }

    cout << "\n========== SELECT PROJECT ==========\n";

    for (size_t i = 0; i < list.size(); ++i)
    {
        cout << i + 1 << ". " << list[i].name << '\n';
    }

    cout << "\nSelect : ";

    int id;
    cin >> id;

    if (id < 1 || id >(int)list.size())
        return;

    db.setCurrentProject(list[id - 1].name);

    cout << "\nCurrent Project : "
        << list[id - 1].name
        << "\n";
}
