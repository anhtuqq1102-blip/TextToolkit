#include "project_integration.h"
#include <fstream>
#include <string>

using namespace std;

string getActiveProject(){
    ifstream in("projects/current_project.txt");
    string path;
    getline(in,path);
    return path;
}

bool hasActiveProject(){
    return !getActiveProject().empty();
}
