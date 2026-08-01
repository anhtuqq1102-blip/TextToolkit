#include "resource_scanner_real.h"
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace std;
namespace fs=std::filesystem;

static bool match(const fs::path& p){
    auto e=p.extension().string();
    return e==".xml"||e==".json"||e==".txt"||e==".csv"||e==".lua"||e==".js";
}

bool scanResources(const string& workspace){
    if(!fs::exists(workspace)){
        cout<<"Workspace not found\n";
        return false;
    }
    fs::create_directories("workspace/report");
    ofstream report("workspace/report/resources.txt");
    size_t count=0;
    for(auto &i:fs::recursive_directory_iterator(workspace)){
        if(i.is_regular_file() && match(i.path())){
            report<<i.path().string()<<"\n";
            ++count;
        }
    }
    cout<<"\n===== RESOURCE SCANNER =====\n";
    cout<<"Workspace : "<<workspace<<"\n";
    cout<<"Resources : "<<count<<"\n";
    cout<<"Report    : workspace/report/resources.txt\n";
    return true;
}
