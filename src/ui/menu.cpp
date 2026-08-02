#include <iostream>
#include "engine/menu.h"
#include "engine/version.h"
#include "engine/project.h"
using namespace std;

void showMainMenu(){
    cout<<"\n==============================\n";
    cout<<APP_NAME<<"\n";
    cout<<APP_VERSION<<"\n";
    cout<<"==============================\n";
    cout<<"1. Du an\n";
    cout<<"2. Dich\n";
    cout<<"3. Cai dat\n";
    cout<<"4. Thong tin\n";
    cout<<"0. Thoat\n";
}


void runTranslationWorkflow() {
    openProject();
    // Next refactor stages:
    // decodeApk();
    // scanResources();
    // parseResources();
    // applyTranslation();
    // rebuildApk();
}
