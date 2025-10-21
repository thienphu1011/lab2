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
    double totalTicketPrices = 0.0;
    char seats[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
        seats[i][j] = '#';    
    
    // loadState("seating_chart.txt", seats, price_arr, totalSales);

    int option = -1;
    while (option != 0) {
        cout << "\nMenu Options:\n";
        cout << "1. Input Row Prices\n";
        cout << "2. Display Seating Chart\n";
        cout << "3. Purchase Ticket\n";
        cout << "4. Display Total Sales\n";
        cout << "0. Exit\n";

        while (true) {
            cout << "Please select an option (0-4): ";
            if (!(cin >> option)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 0 and 4.\n";
                continue;
            }
            if (option < 0 || option > 4) {
                cout << "Please enter a number between 0 and 4.\n";
                continue;
            }
            break;
        }

        if (option == 1) {
            if (!inputRowPrice(price_arr)) {
                cout << "Failed to read row prices.\n";
            } else {
                cout << "Row prices updated.\n";
            }
            saveState("seating_chart.txt", seats, price_arr, totalSales);

        } else if (option == 2) {
            displaySeating(seats);

        } else if (option == 3) {
            int row, col;
            int purchase_type;
            cout << "Enter 1 for single ticket purchase, 0 for multiple: ";
            cin >> purchase_type;
            if (purchase_type==1){
                cout << "Enter the row (1-" << ROWS << "): "; cin >> row;
                cout << "Enter the seat (1-" << COLS << "): "; cin >> col;
                if (sellTicket(seats, price_arr, row, col, totalSales, totalTicketPrices)) {
                    saveState("seating_chart.txt", seats, price_arr, totalSales);
                } 
                else {
                    cout << "Ticket purchase failed.\n";
                }
                cout << "Ticket purchased successfully.\n";
                cout << "Total price: $" << fixed << setprecision(2) << totalTicketPrices << "\n";
                totalTicketPrices = 0.0;
            }
            else if(purchase_type==0){
                int n;
                cout << "Enter number of tickets to purchase: ";
                cin >> n;
                for (int i=0; i<n; i++){
                    cout << "Ticket " << (i+1) << ":\n";
                    cout << "Enter the row (1-" << ROWS << "): "; cin >> row;
                    cout << "Enter the seat (1-" << COLS << "): "; cin >> col;
                    if (sellTicket(seats, price_arr, row, col, totalSales, totalTicketPrices)) {
                        saveState("seating_chart.txt", seats, price_arr, totalSales);
                    } else {
                        cout << "Ticket purchase failed.\n";
                    }
                }
                cout << "Ticket purchased successfully.\n";
                cout << "Total price for " << n << " tickets: $" << fixed << setprecision(2) << totalTicketPrices << "\n";
                totalTicketPrices = 0.0;
            }

        } else if (option == 4) {
            showStatistics(seats, price_arr, totalSales);

        } else if (option == 0) {
            cout << "Good bye!\n";
        }
    }

    return 0;
}