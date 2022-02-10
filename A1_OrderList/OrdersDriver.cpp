#pragma once
#include "Orders.h"
#include <iostream>
#include <limits>
using namespace std;

int positive_Int_Verification(int x){
    bool restart;
    //purpose to ensure the input is a positive integer
    do{
        restart = false;
        if(!cin){
            cout << "This is not a number" << endl;
            restart = true;
            //remove the state "false" that cin has
            cin.clear();
            //ignores the rest of the input (\n)
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }
        if(x < 0){
            cout << "Enter a positive number" << endl;
            restart = true;
        }
        if(restart)
            cin >> x;
        
    } while(restart);
    return x;
}

int main(){
    cout << "How many orders would you like to execute this turn?: ";
    int ordersNum = 0;
    cin >> ordersNum;
    ordersNum = positive_Int_Verification(ordersNum);
    return 0;
}