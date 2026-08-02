#include "engine/project_restore.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

void restoreProject()
{
    fs::create_directories("projects/backup");

    vector<fs::path> backups;

    for (const auto& entry : fs::directory_iterator("projects/backup"))
    {
        if (!entry.is_regular_file())
            continue;

        backups.push_back(entry.path());
    }

    if (backups.empty())
    {
        cout << "\nNo backup found.\n";
        return;
    }

    cout << "\n========== RESTORE PROJECT ==========\n";

    for (size_t i = 0; i < backups.size(); ++i)
    {
        cout << i + 1
            << ". "
            << backups[i].filename().string()
            << '\n';
    }

    cout << "\nSelect : ";

    int id;
    cin >> id;

    if (id < 1 || id >(int)backups.size())
        return;

    fs::path target =
        "projects/" + backups[id - 1].stem().string();

    ifstream src(backups[id - 1], ios::binary);

    ofstream dst(target, ios::binary);

    dst << src.rdbuf();

    cout << "\nRestore completed.\n";
}
