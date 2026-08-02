#include "engine/translation_engine_real_v2.h"
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;

bool applyTranslation(const string& extractFile){
    if(!fs::exists(extractFile)){
        cout<<"Extract file not found\n";
        return false;
    }
    fs::create_directories("workspace/translated");
    ifstream in(extractFile);
    ofstream out("workspace/translated/translation_preview.txt");
    string line;
    size_t count=0;
    while(getline(in,line)){
        out<<"# "<<line<<"\n";
        ++count;
    }
    cout<<"Translated entries: "<<count<<"\n";
    return true;
}
