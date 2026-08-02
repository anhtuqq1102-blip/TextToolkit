#include "engine/scanner_history.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
namespace fs = std::filesystem;

void scannerHistoryMenu()
{
    fs::create_directories("reports");

    string file = "reports/scanner_history.txt";

    ofstream out(file, ios::app);

    time_t now = time(nullptr);

    string time =
        ctime(&now);

    if (!time.empty() && time.back() == '\n')
        time.pop_back();

    out << "---------------------------------\n";
    out << "Scan Time : "
        << time
        << "\n";
    out << "Status    : Completed\n";
    out << "Engine    : Resource Scanner\n";
    out << "---------------------------------\n";

    out.close();

    cout << "\nScanner history updated.\n";
}
