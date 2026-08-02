#include "engine/project_create.h"

#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void createProject()
{
    fs::create_directories("projects");

    string name;
    string path;

    cout << "\n========== CREATE PROJECT ==========\n";

    cout << "Project name : ";
    cin >> name;

    cout << "Project path : ";
    cin >> path;

    ofstream db("projects/projects.db", ios::app);

    db << name << "|" << path << "\n";

    db.close();

    ofstream current("projects/current_project.txt");

    current << name;

    current.close();

    cout << "\nProject created successfully.\n";
}
