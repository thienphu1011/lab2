#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 15;
const int COLS = 30;



bool readPositiveNumber(double &x);
bool inputRowPrice(double price[ROWS]);
void displaySeating(bool seats[ROWS][COLS]);
void showStatistics(bool seats[ROWS][COLS], double price_arr[ROWS], double totalSales);
bool saveState(const char *filename, bool seats[ROWS][COLS], double price_arr[ROWS], double totalSales);
bool loadState(const char *filename, bool seats[ROWS][COLS], double price_arr[ROWS], double &totalSales) ;
bool sellTicket(bool seats[ROWS][COLS],double price_arr[ROWS], int row, int col,double &totalSales);







#endif


