#include "parser_real.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
using namespace std;
namespace fs=std::filesystem;

bool parseResources(const string& workspace){
    if(!fs::exists(workspace)) return false;
    fs::create_directories("workspace/report");
    ofstream out("workspace/report/strings_extract.txt");
    regex xml("<string[^>]*>(.*?)</string>");
    regex json("\"([^\"]+)\"\\s*:\\s*\"([^\"]*)\"");
    size_t total=0;

    for(auto &e:fs::recursive_directory_iterator(workspace)){
        if(!e.is_regular_file()) continue;
        auto ext=e.path().extension().string();
        if(ext!=".xml" && ext!=".json") continue;

        ifstream in(e.path());
        string line;
        while(getline(in,line)){
            smatch m;
            if(ext==".xml"){
                if(regex_search(line,m,xml)){
                    out<<"XML|"<<e.path().string()<<"|"<<m[1]<<"\n";
                    total++;
                }
            }else{
                if(regex_search(line,m,json)){
                    out<<"JSON|"<<e.path().string()<<"|"<<m[1]<<"="<<m[2]<<"\n";
                    total++;
                }
            }
        }
    }

    cout<<"\n===== REAL PARSER =====\n";
    cout<<"Strings: "<<total<<"\n";
    cout<<"Output : workspace/report/strings_extract.txt\n";
    return true;
}
