#include "strings.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
using namespace std;
namespace fs=std::filesystem;

void stringListMenu(){
    set<string> uniq;
    size_t total=0;
    cout<<"\n===== CHUOI CAN DICH =====\n";
    if(!fs::exists("projects")){
        cout<<"Chua co Project.\n";
        return;
    }
    for(auto &e:fs::recursive_directory_iterator("projects")){
        if(!e.is_regular_file()) continue;
        string ext=e.path().extension().string();
        if(ext!=".xml"&&ext!=".json"&&ext!=".txt"&&ext!=".csv"&&ext!=".lua") continue;
        ifstream in(e.path());
        string line;
        while(getline(in,line)){
            if(line.empty()) continue;
            total++;
            uniq.insert(line);
        }
    }
    cout<<"Tong chuoi : "<<total<<"\n";
    cout<<"Khong trung : "<<uniq.size()<<"\n";
    int shown=0;
    for(auto &s:uniq){
        cout<<s<<"\n";
        if(++shown>=20){
            cout<<"... ("<<uniq.size()-shown<<" dong)\n";
            break;
        }
    }
}
