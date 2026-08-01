#include "project_auto_select.h"
#include <fstream>
#include <iostream>
using namespace std;

string autoSelectProject(){
    ifstream in("projects/current_project.txt");
    string path;
    getline(in,path);
    if(path.empty()){
        cout<<"[Auto Select] Khong co project.\n";
        return "";
    }
    cout<<"[Auto Select] "<<path<<"\n";
    return path;
}
