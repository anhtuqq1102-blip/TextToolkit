#include "memory.h"
#include "xml_parser.h"
#include "repack.h"
#include "translate_engine.h"
#include "strings.h"
#include "version.h"
#include "filelist.h"
#include "about.h"
#include "settings.h"
#include "info.h"
#include "history.h"
#include "progress.h"
#include "scanner.h"
#include "translator.h"
#include "project.h"
#include <iostream>
#include "menu.h"
using namespace std;

int main(){
    while(true){
        showMainMenu();
        cout<<"> ";
        int c; cin>>c;
        switch(c){
            case 1: openProject(); break;
            case 2:
            runTranslationWorkflow();
            break;

        // legacy
        case 200: translatorMenu(); stringListMenu(); translateEngineMenu(); repackMenu(); xmlParserMenu(); memoryMenu(); scanMenu(); showProgress(); historyMenu(); break;
            case 3: settingsMenu(); break;
            case 4: aboutMenu(); break;
            case 0: return 0;
            default: cout<<"Không hợp lệ\n";
        }
    }
}
