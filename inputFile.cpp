#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
using namespace std;


int readFileToArray(const string &filename, int price_arr[ROWS], int maxSize) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file!\n";
        return 0;
    }

    int count = 0;
    while (file >> price_arr[count] && count < maxSize) {
        count++;
    }

    file.close();
    return count; // return how many numbers were read
}

int main() {
    const int ROWS = 15;
    int price_arr[ROWS];
    int size = readFileToArray("inputFile.txt", price_arr, 100);

    
    for (int i = 0; i < size; ++i) {
        cout << price_arr[i] << " ";
    }
    cout << endl;
}
