#include "translation_pipeline.h"
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs=std::filesystem;

void translationPipelineMenu(){
    fs::create_directories("pipeline");
    cout<<"\n===== TRANSLATION PIPELINE =====\n";
    cout<<"Scan Resources : Ready\n";
    cout<<"Extract Text   : Ready\n";
    cout<<"Translate Step : Placeholder\n";
    cout<<"Validate       : Ready\n";
    cout<<"Export Stage   : Ready\n";
    cout<<"Pipeline Dir   : pipeline/\n";
}
