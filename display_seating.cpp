#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"
using namespace std;





void displaySeating(bool seats[ROWS][COLS]) {
    cout << "\n\t\tSeats\n        ";
    for (int i=1; i<=3; i++){
    for (int c = 1; c <= 10; ++c) {
        if (c==10)
         cout <<"0"<<"";
        
    
        else cout  << c;
    }
    
    }

    cout << endl;

    for (int r = 0; r < ROWS; ++r) {
        cout << "Row " << setw(2) << (r + 1) << "  ";
        for (int c = 0; c < COLS; ++c) {
            char ch = seats[r][c] ? '#' : '#';
            cout <<  ch;
        }
        cout << endl;
    }
}
 