#include "engine/project_database.h"

#include <filesystem>
#include <fstream>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

ProjectDatabase::ProjectDatabase()
{
    databaseFile = "projects/projects.db";
    currentProjectFile = "projects/current_project.txt";
}

bool ProjectDatabase::initialize()
{
    fs::create_directories("projects");

    if (!fs::exists(databaseFile))
    {
        ofstream(databaseFile).close();
    }

    if (!fs::exists(currentProjectFile))
    {
        ofstream(currentProjectFile).close();
    }

    return true;
}

bool ProjectDatabase::createProject(const string& name, const string& path)
{
    initialize();

    ofstream db(databaseFile, ios::app);

    if (!db)
        return false;

    db << name << "|" << path << '\n';

    return true;
}

bool ProjectDatabase::deleteProject(const string& name)
{
    initialize();

    ifstream in(databaseFile);

    vector<ProjectInfo> list;
    string line;

    while (getline(in, line))
    {
        size_t pos = line.find('|');

        if (pos == string::npos)
            continue;

        ProjectInfo p;
        p.name = line.substr(0, pos);
        p.path = line.substr(pos + 1);

        if (p.name != name)
            list.push_back(p);
    }

    in.close();

    ofstream out(databaseFile);

    for (const auto& p : list)
    {
        out << p.name << "|" << p.path << '\n';
    }

    return true;
}

bool ProjectDatabase::renameProject(const string& oldName,
    const string& newName)
{
    initialize();

    vector<ProjectInfo> list = getProjects();

    ofstream out(databaseFile);

    for (auto& p : list)
    {
        if (p.name == oldName)
            p.name = newName;

        out << p.name << "|" << p.path << '\n';
    }

    return true;
}

bool ProjectDatabase::setCurrentProject(const string& name)
{
    initialize();

    ofstream(currentProjectFile) << name;

    return true;
}

string ProjectDatabase::getCurrentProject() const
{
    ifstream in(currentProjectFile);

    string name;

    getline(in, name);

    return name;
}

vector<ProjectInfo> ProjectDatabase::getProjects() const
{
    vector<ProjectInfo> list;

    ifstream in(databaseFile);

    string line;

    while (getline(in, line))
    {
        size_t pos = line.find('|');

        if (pos == string::npos)
            continue;

        ProjectInfo p;

        p.name = line.substr(0, pos);
        p.path = line.substr(pos + 1);

        list.push_back(p);
    }

    return list;
}
