#include "project_persistence.h"
#include <filesystem>
#include <fstream>
using namespace std;

bool saveCurrentProject(const string& path){
    filesystem::create_directories("projects");
    ofstream out("projects/current_project.txt");
    if(!out) return false;
    out<<path;
    return true;
}

string loadCurrentProject(){
    ifstream in("projects/current_project.txt");
    string p;
    getline(in,p);
    return p;
}
