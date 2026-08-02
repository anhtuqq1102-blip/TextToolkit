#include <iostream>
using namespace std;

void backupMenu(){
    while(true){
        cout<<"\n===== SAO LUU =====\n";
        cout<<"1. Dat duong dan sao luu\n";
        cout<<"2. Xem duong dan hien tai\n";
        cout<<"0. Quay lai\n> ";
        int c; cin>>c;
        if(c==0) return;
        if(c==1) cout<<"[Chuc nang se hoan thien]\n";
        else if(c==2) cout<<"backup/\n";
    }
}
