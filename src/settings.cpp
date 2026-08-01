#include "backup.h"
#include "theme.h"
#include <iostream>
using namespace std;
void settingsMenu(){
    while(true){
        cout<<"\n===== CAI DAT =====\n";
        cout<<"1. Giao dien\n";
        cout<<"2. Mau sac\n";
        cout<<"3. Sao luu\n";
        cout<<"4. Thong tin\n";
        cout<<"0. Quay lai\n> ";
        int c; cin>>c;
        if(c==0) return;
        cout<<"Dang phat trien...\n";
    }
}
