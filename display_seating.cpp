#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"
using namespace std;




void displaySeating(bool seats[ROWS][COLS])
{
    cout << setw(27) << "Seats\n";
    cout << setw(8) << " ";
    for(int c = 1; c <= COLS; c++)
    {
        cout << (c % 10);
    }
    cout << endl;
    for (int r = 0; r < ROWS; r++)
    {
        cout << "Row" << setw(3) << (r + 1) << "  ";
        for(int c = 0; c < COLS; c++)
        {
            char ch = seats[r][c]? '#' : '*';
            cout << ch;
        }
        cout << endl;
    }
    
}
