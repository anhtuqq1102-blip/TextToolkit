#include <iostream>
#include <thread>
#include <chrono>

void showProgress(){
    std::cout<<"\nDang quet...\n";
    for(int i=0;i<=100;i+=10){
        std::cout<<"\r["<<i<<"%]"<<std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
    std::cout<<"\nHoan tat.\n";
}
