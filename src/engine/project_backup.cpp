#include "engine/project_backup.h"
#include "engine/project_database.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

void backupProject()
{
    ProjectDatabase db;
    db.initialize();

    vector<ProjectInfo> list = db.getProjects();

    if (list.empty())
    {
        cout << "\nNo project.\n";
        return;
    }

    cout << "\n========== BACKUP PROJECT ==========\n";

    for (size_t i = 0; i < list.size(); ++i)
    {
        cout << i + 1 << ". " << list[i].name << '\n';
    }

    cout << "\nSelect : ";

    int id;
    cin >> id;

    if (id < 1 || id >(int)list.size())
        return;

    fs::create_directories("projects/backup");

    string backupFile =
        "projects/backup/" +
        list[id - 1].name +
        ".bak";

    ifstream src(list[id - 1].path, ios::binary);

    if (!src)
    {
        cout << "\nCannot open source file.\n";
        return;
    }

    ofstream dst(backupFile, ios::binary);

    dst << src.rdbuf();

    cout << "\nBackup completed.\n";
    cout << backupFile << "\n";
}
