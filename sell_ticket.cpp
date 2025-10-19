#include <iostream>
#include "main.h"

using namespace std;

static bool isValidSeat(int row, int col) {
    return row >= 1 && row <= ROWS && col >= 1 && col <= COLS;
}

bool sellTicket(bool seats[ROWS][COLS],double price_arr[ROWS], int row, int col,double &totalSales) {
    if (!isValidSeat(row, col)) {
        cout << "The position is invalid!\n";
        return false;
    }
        
        
    // Kiem tra da co gia chua
    /*if (price_arr[row - 1] <= 0) {
        cout << "Chua co gia cho hang " << row << ". Vui long nhap gia truoc.\n";
        return false;
    }*/

    int r = row - 1;
    int c = col - 1;
    if (seats[r][c]) {
        cout << "This seat has been sold.\n";
        return false;
    }
    seats[r][c] = true;
    totalSales += price_arr[r];
    cout << "Sold (Row " << row << ", Seat " << col << ") - Price: " << price_arr[r] << "\n";
    return true;
}
