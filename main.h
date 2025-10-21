#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 15;
const int COLS = 30;

int updatePrice(double price_arr[ROWS]);
int readFileToArray(const string &filename, double price_arr[ROWS], int maxSize);
bool readPositiveNumber(double &x);
bool inputRowPrice(double price[ROWS]);
void displaySeating(char seats[ROWS][COLS]);
void showStatistics(char seats[ROWS][COLS], double price_arr[ROWS], double totalSales);
bool saveState(const char *filename, char seats[ROWS][COLS], double price_arr[ROWS], double totalSales);
// bool loadState(const char *filename, char seats[ROWS][COLS], double price_arr[ROWS], double &totalSales);
void sellTicket(char seats[ROWS][COLS], double price_arr[ROWS], double &totalSales);





#endif


