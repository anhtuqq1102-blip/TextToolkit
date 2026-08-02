#include "engine/binary_scanner.h"

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void binaryScannerMenu()
{
    string file;

    cout << "\n=========================================\n";
    cout << "           BINARY SCANNER\n";
    cout << "=========================================\n";

    cout << "Binary File : ";
    cin >> file;

    if (!fs::exists(file))
    {
        cout << "\nFile not found.\n";
        return;
    }

    ifstream in(file, ios::binary);

    if (!in)
    {
        cout << "\nCannot open file.\n";
        return;
    }

    cout << "\n========== HEX PREVIEW ==========\n";

    unsigned char buffer[16];

    while (in.read(reinterpret_cast<char*>(buffer), sizeof(buffer)) ||
        in.gcount() > 0)
    {
        streamsize count = in.gcount();

        for (streamsize i = 0; i < count; ++i)
        {
            cout << uppercase
                << hex
                << setw(2)
                << setfill('0')
                << static_cast<int>(buffer[i])
                << ' ';
        }

        cout << '\n';
    }

    cout << dec;
    cout << "\nScan completed.\n";
}
