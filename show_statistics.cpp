#include <iostream>
#include <iomanip>
#include "main.h"

using namespace std;

void showStatistics(bool seats[ROWS][COLS], double price_arr[ROWS], double totalSales) {
    int totalSold = 0;
    int totalAvailable = 0;

    cout << "\n=== THONG KE ===\n";
    for (int r = 0; r < ROWS; ++r) {
        int sold = 0;
        for (int c = 0; c < COLS; ++c) {
            if (seats[r][c]) ++sold;
        }
        int avail = COLS - sold;
        totalSold += sold;
        totalAvailable += avail;
        cout << "Hang " << (r + 1) << ": Con " << avail << "/" << COLS << " (Da ban " << sold << ")\n";
    }

    cout <<fixed<<setprecision(2)<<endl;
    cout << "Total seats: " << (ROWS * COLS) << "\n";
    cout << "Total sold: " << totalSold << "\n";
    cout << "Total available: " << totalAvailable << "\n";
    cout << "Total sales: " << totalSales << "\n";
}
