#include "engine/project_dashboard.h"
#include "engine/project_database.h"

#include <iostream>
#include <vector>

using namespace std;

void projectDashboard()
{
    ProjectDatabase db;
    db.initialize();

    cout << "\n=====================================\n";
    cout << "          PROJECT DASHBOARD\n";
    cout << "=====================================\n";

    string current = db.getCurrentProject();

    if (current.empty())
    {
        cout << "Current Project : <none>\n";
    }
    else
    {
        cout << "Current Project : " << current << "\n";
    }

    cout << "\nSaved Projects\n";
    cout << "-----------------------------\n";

    vector<ProjectInfo> projects = db.getProjects();

    if (projects.empty())
    {
        cout << "No project.\n";
    }
    else
    {
        for (size_t i = 0; i < projects.size(); i++)
        {
            cout
                << i + 1
                << ". "
                << projects[i].name
                << "\n";

            cout
                << "   "
                << projects[i].path
                << "\n";
        }
    }

    cout << "=====================================\n";
}
