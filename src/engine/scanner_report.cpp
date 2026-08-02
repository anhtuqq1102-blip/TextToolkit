#include "engine/scanner_report.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void scannerReportMenu()
{
    fs::create_directories("reports");

    string file = "reports/scan_report.txt";

    ofstream out(file);

    cout << "\n=========================================\n";
    cout << "          SCANNER REPORT\n";
    cout << "=========================================\n";

    out << "TEXTTOOLKIT SCANNER REPORT\n";
    out << "==========================\n";
    out << "Status: Ready\n";
    out << "Scanner Engine: Active\n";
    out << "Resource Scanner: Ready\n";
    out << "XML Engine: Ready\n";
    out << "JSON Engine: Ready\n";
    out << "Binary Scanner: Ready\n";
    out << "Translation Engine: Preparing\n";

    out.close();

    cout << "Report created:\n";
    cout << file << "\n";
}
