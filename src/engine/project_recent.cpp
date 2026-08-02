#include "engine/project_recent.h"
#include "engine/project_database.h"

#include <iostream>
#include <vector>

using namespace std;

void recentProjects()
{
    ProjectDatabase db;
    db.initialize();

    vector<ProjectInfo> list = db.getProjects();

    cout << "\n========== RECENT PROJECTS ==========\n";

    if (list.empty())
    {
        cout << "No recent project.\n";
        return;
    }

    int count = static_cast<int>(list.size());

    if (count > 10)
        count = 10;

    for (int i = count - 1, index = 1; i >= 0; --i, ++index)
    {
        cout << index << ". " << list[i].name << "\n";
        cout << "   " << list[i].path << "\n";
    }

    cout << "=====================================\n";
}
