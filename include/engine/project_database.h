#pragma once

#include <string>
#include <vector>

struct ProjectInfo
{
    std::string name;
    std::string path;
};

class ProjectDatabase
{
public:
    ProjectDatabase();

    bool initialize();

    bool createProject(const std::string& name,
        const std::string& path);

    bool deleteProject(const std::string& name);

    bool renameProject(const std::string& oldName,
        const std::string& newName);

    bool setCurrentProject(const std::string& name);

    std::string getCurrentProject() const;

    std::vector<ProjectInfo> getProjects() const;

private:
    std::string databaseFile;
    std::string currentProjectFile;
};