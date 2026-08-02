#include "engine/project_manager_v2.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

void projectManagerV2Menu()
{
    // Tạo thư mục projects nếu chưa tồn tại
    fs::create_directories("projects");

    std::cout << "\n";
    std::cout << "=====================================\n";
    std::cout << "      TEXTTOOLKIT PROJECT MANAGER\n";
    std::cout << "=====================================\n";

    std::ifstream in("projects/current_project.txt");

    std::string currentProject;

    if (in.is_open())
    {
        std::getline(in, currentProject);
        in.close();
    }

    if (currentProject.empty())
    {
        currentProject = "<None>";
    }

    std::cout << "Current Project : " << currentProject << "\n";
    std::cout << "Database        : Ready\n";
    std::cout << "Recent Projects : Ready\n";
    std::cout << "Continue        : Ready\n";
    std::cout << "Rename          : Placeholder\n";
    std::cout << "Delete          : Placeholder\n";
    std::cout << "Backup          : Ready\n";

    std::cout << "=====================================\n";
}
