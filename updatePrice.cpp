#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
using namespace std;

int inputRowPrice(double price_arr[ROWS]){
    for (int i = 0; i < ROWS; i++){
        cout << "Price for row " << i + 1 << ": $";
        cin >> price_arr[i];
        while (price_arr[i] <= 0){
            cout << "Invalid price! Please enter again: $" ;
            cin >> price_arr[i];
        }
    }
    return 0;
}


int updatePrice(double price_arr[ROWS]) {
    char update;
    
 do{
    cout <<" Do you want to update the price for each row(y/n) ?";
    cin >> update;


}while (update!='y' || update!='Y' || update!='n' || update!='N');
    if(update = 'y' || update ='Y'{
    inputRowPrice(price_arr);
    }
    else {};
        
    return 0;
}

