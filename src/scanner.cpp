#include "scanner.h"
#include <filesystem>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
namespace fs=std::filesystem;

void scanMenu(){
    map<string,int> stat;
    vector<string> list;

    if(!fs::exists("projects")){
        cout<<"Chua co Project.\n";
        return;
    }

    for(auto &e:fs::recursive_directory_iterator("projects")){
        if(!e.is_regular_file()) continue;
        string ext=e.path().extension().string();
        if(ext==".xml"||ext==".json"||ext==".txt"||
           ext==".csv"||ext==".lua"){
            stat[ext]++;
            list.push_back(e.path().string());
        }
    }

    cout<<"\n===== THONG KE =====\n";
    for(auto &i:stat)
        cout<<i.first<<" : "<<i.second<<"\n";

    cout<<"\n===== DANH SACH =====\n";
    for(auto &f:list)
        cout<<f<<"\n";
}
