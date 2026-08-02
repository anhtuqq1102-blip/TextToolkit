#include "engine/project_manager_ui.h"
#include "engine/project_database.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void projectManagerMenu()
{
    ProjectDatabase db;
    db.initialize();

    while (true)
    {
        cout << "\n";
        cout << "=========================================\n";
        cout << "         PROJECT MANAGER v2\n";
        cout << "=========================================\n";

        string current = db.getCurrentProject();

        cout << "Current Project : ";

        if (current.empty())
            cout << "<none>\n";
        else
            cout << current << "\n";

        cout << "\n";
        cout << "1. List Projects\n";
        cout << "2. Create Project\n";
        cout << "3. Rename Project\n";
        cout << "4. Delete Project\n";
        cout << "5. Select Project\n";
        cout << "6. Continue Current Project\n";
        cout << "0. Back\n";

        cout << "\nSelect : ";

        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            auto list = db.getProjects();

            cout << "\n========== PROJECT LIST ==========\n";

            if (list.empty())
            {
                cout << "No projects.\n";
            }
            else
            {
                for (size_t i = 0; i < list.size(); i++)
                {
                    cout << i + 1 << ". "
                        << list[i].name
                        << "\n";
                }
            }

            break;
        }

        case 2:
        {
            string name;
            string path;

            cout << "Project name : ";
            cin >> name;

            cout << "Project path : ";
            cin >> path;

            if (db.createProject(name, path))
                cout << "Created.\n";
            else
                cout << "Failed.\n";

            break;
        }

        case 3:
        {
            string oldName;
            string newName;

            cout << "Old name : ";
            cin >> oldName;

            cout << "New name : ";
            cin >> newName;

            if (db.renameProject(oldName, newName))
                cout << "Renamed.\n";
            else
                cout << "Failed.\n";

            break;
        }

        case 4:
        {
            string name;

            cout << "Delete : ";
            cin >> name;

            if (db.deleteProject(name))
                cout << "Deleted.\n";
            else
                cout << "Failed.\n";

            break;
        }

        case 5:
        {
            string name;

            cout << "Select : ";
            cin >> name;

            db.setCurrentProject(name);

            cout << "Current project updated.\n";

            break;
        }

        case 6:
        {
            cout << "\nContinue : "
                << db.getCurrentProject()
                << "\n";

            break;
        }

        case 0:
            return;

        default:
            cout << "Invalid.\n";
            break;
        }
    }
}
