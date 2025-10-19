#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include "main.h"
using namespace std;

int main() {
    double price_arr[ROWS] = {0.0};
    double totalSales = 0.0;
    bool seats[ROWS][COLS] = {false};
    
    
    loadState("seating_state.txt", seats, price_arr, totalSales);

    int option = -1;
    while (option != 0) {
        cout << "\nMenu Options:\n";
        cout << "1. Input Row Prices\n";
        cout << "2. Display Seating Chart\n";
        cout << "3. Purchase Ticket\n";
        cout << "4. Display Total Sales\n";
        cout << "0. Exit\n";
        cout << "Please select an option (0--4): ";

        if (!(cin >> option)) {
            cout << "Invalid input. Please enter a number between 0 and 4.\n";
            
            continue;
        }

        if (option == 1) {
            if (!inputRowPrice(price_arr)) {
                cout << "Failed to read row prices.\n";
            } else {
                cout << "Row prices updated.\n";
            }
            saveState("seating_state.txt", seats, price_arr, totalSales);

        } else if (option == 2) {
            displaySeating(seats);

        } else if (option == 3) {
            int row, col;
            cout << "Enter the row (1-" << ROWS << "): "; cin >> row;
            cout << "Enter the seat (1-" << COLS << "): "; cin >> col;
            if (sellTicket(seats, price_arr, row, col, totalSales)) {
                cout << "Ticket purchased successfully.\n";
                saveState("seating_state.txt", seats, price_arr, totalSales);
            } else {
                cout << "Ticket purchase failed.\n";
            }

        } else if (option == 4) {
            showStatistics(seats, price_arr, totalSales);

        } else if (option == 0) {
            cout << "Good bye!\n";
        } else {
            cout << "Unknown option. Please choose 0-4.\n";
        }
    }

    return 0;
}