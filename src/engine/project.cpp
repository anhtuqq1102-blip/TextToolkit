#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void openProject(){
    string dir = string(getenv("HOME")) + "/storage/downloads";
    vector<fs::path> files;

    cout << "\n===== MO DU AN =====\n";

    for(auto &e : fs::directory_iterator(dir)){
        if(!e.is_regular_file()) continue;
        string ext = e.path().extension().string();
        if(ext==".apk" || ext==".zip" || ext==".rar"){
            files.push_back(e.path());
            cout << files.size() << ". " << e.path().filename().string() << "\n";
        }
    }

    if(files.empty()){
        cout << "Khong tim thay tep.\n";
        return;
    }

    cout << "\nChon: ";
    int n;
    cin >> n;

    if(n<1 || n>(int)files.size()) return;

    fs::create_directories("projects");
    ofstream("projects/last_project.txt") << files[n-1].string();

    cout << "\nDa luu Project:\n" << files[n-1] << "\n";
}
