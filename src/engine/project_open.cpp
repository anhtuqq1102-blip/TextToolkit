#include "engine/project_open.h"
#include "engine/project_database.h"

#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void openProjectMenu()
{
    ProjectDatabase db;
    db.initialize();

    vector<fs::path> files;

    cout << "\n========== OPEN PROJECT ==========\n";

#ifdef _WIN32
    fs::path root = fs::current_path();
#else
    fs::path root = string(getenv("HOME")) + "/storage/downloads";
#endif

    for (auto& e : fs::recursive_directory_iterator(root))
    {
        if (!e.is_regular_file())
            continue;

        string ext = e.path().extension().string();

        if (ext == ".apk" ||
            ext == ".zip" ||
            ext == ".rar")
        {
            files.push_back(e.path());
        }
    }

    if (files.empty())
    {
        cout << "No project found.\n";
        return;
    }

    for (size_t i = 0; i < files.size(); i++)
    {
        cout << i + 1 << ". "
            << files[i].filename().string()
            << "\n";
    }

    cout << "\nSelect : ";

    int n;
    cin >> n;

    if (n < 1 || n >(int)files.size())
        return;

    string name = files[n - 1].stem().string();
    string path = files[n - 1].string();

    db.createProject(name, path);
    db.setCurrentProject(name);

    cout << "\nCurrent Project : "
        << name
        << "\n";
}
