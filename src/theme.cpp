#include <iostream>
using namespace std;
void themeMenu(){
    while(true){
        cout<<"\n===== GIAO DIEN =====\n";
        cout<<"1. Mac dinh\n";
        cout<<"2. Xanh la\n";
        cout<<"3. Xanh duong\n";
        cout<<"4. Do\n";
        cout<<"0. Quay lai\n> ";
        int c; cin>>c;
        if(c==0) return;
        cout<<"Da chon giao dien "<<c<<"\n";
    }
}
