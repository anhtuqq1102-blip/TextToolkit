#include "engine/project_loader.h"
#include <fstream>
#include <iostream>
using namespace std;

string autoLoadCurrentProject(){
    ifstream in("projects/current_project.txt");
    string path;
    getline(in,path);
    if(path.empty()){
        cout<<"[Project] Chua co du an duoc luu.\n";
    }else{
        cout<<"[Project] Dang su dung:\n"<<path<<"\n";
    }
    return path;
}
