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
    for (int i = 1; i <= ROWS; i++)
    for (int j = 1; j <= COLS; j++)
        seats[i][j] = '#';    

    int option = -1;
    while (option != 0) {
        cout << "\nMenu Options:\n";
        cout << "1. Input Row Prices\n";
        cout << "2. Purchase Ticket\n";
        cout << "3. Display Total Sales\n";
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
            cout << "Press 2 to load from file, or 3 to update row prices: ";
            int price_option;
            cin >> price_option;
            if (price_option == 1) {
                if (!inputRowPrice(price_arr)) {
                    cout << "Failed to read row prices.\n";
                } else {
                    cout << "Row prices updated.\n";
                }
                saveState("seating_chart.txt", seats, price_arr, totalSales);
            }
            else if (price_option == 2) {
                int count = readFileToArray("inputfile.txt", price_arr, ROWS);
                if (count == 0) {
                    cout << "Failed to read row prices from file.\n";
                }
                else if (count < ROWS) {
                    cout << "Warning: Only " << count << " prices were read from the file. Remaining rows set to $0.0\n";
                } else {
                    cout << "Row prices loaded from file successfully.\n";
                }
            }
            else if (price_option == 3){
                updatePrice(price_arr);
                cout << "Row prices updated.\n";
            }
            else {
                cout << "Invalid option for row prices input.\n";
                continue;
            }

        }
        
        
        else if (option == 2) {
            int row, col;
            int purchase_type;
            sellTicket(seats, price_arr, totalSales);
            saveState("seating_chart.txt", seats, price_arr, totalSales);
            }

         else if (option == 3) {
          showStatistics(seats, price_arr, totalSales);

        } else if (option == 0) {
            cout << "Good bye!\n";
        }
    }

    return 0;
}