#include "project_manager_v2.h"
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace std;
namespace fs=std::filesystem;

void projectManagerV2Menu(){
    fs::create_directories("projects");
    cout<<"\n===== PROJECT MANAGER V2 =====\n";
    cout<<"Current : ";
    ifstream in("projects/current_project.txt");
    string p; getline(in,p);
    cout<<(p.empty()?"<none>":p)<<"\n";
    cout<<"Database : Ready\n";
    cout<<"Recent   : Ready\n";
    cout<<"Continue : Ready\n";
    cout<<"Rename   : Placeholder\n";
    cout<<"Delete   : Placeholder\n";
    cout<<"Backup   : Ready\n";
}
