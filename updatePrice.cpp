#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
using namespace std;

int updatePrice(double price_arr[ROWS]) {
    char update;
    
 do{
    cout <<" Do you want to update the price for each row(y/n) ?";
    cin >> update;
     if(update == 'y' || update =='Y'){
        for (int i = 1; i <= ROWS; i++){
            cout << "Price for row " << i << ": $";
            cin >> price_arr[i];
            while (price_arr[i] <= 0){
                cout << "Invalid price! Please enter again: $" ;
                cin >> price_arr[i];
            }
        }
    }
    else if (update == 'n' || update == 'N'){
        cout << "No changes made to row prices.\n";
        return 0;
    }
    else {
        cout << "Invalid input! Please enter 'y' or 'n'.\n";
    }

}while (update!='y' || update!='Y' || update!='n' || update!='N');
   
        
    return 0;
}

