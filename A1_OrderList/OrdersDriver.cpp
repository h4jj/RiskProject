#include "Orders.h"
#include "Orders.cpp"
#include <iostream>
#include <limits>

using namespace std;

//Purpose of this function is to make sure the input is between 0 and 6 inclusively
int int_Verification(int x)
{
    bool restart;
    // purpose to ensure the input is a positive integer
    do
    {
        restart = false;
        if (!cin)
        {
            cout << "This is not a number" << endl;
            restart = true;
            // remove the state "false" that cin has
            cin.clear();
            // ignores the rest of the input (\n)
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (x < 0 || x > 6)
        {
            cout << "Enter a number between 0 and 6 inclusively" << endl;
            restart = true;
        }
        if (restart)
            cin >> x;

    } while (restart);
    return x;
}

//prints all possible orders (without the cards)
void choice_of_orders()
{
    cout << "Which order you would like to execute (write in order of execution desired)?: \n1 - Deploy\n2 - Advance\n3 - Bomb\n4 - Blockade\n5 - Airlift\n6 - negotiate" << endl;
}

int main()
{
    
    cout << "How many orders would you like to execute this turn?: ";
    int ordersNum = 0;
    cin >> ordersNum; // Number of orders
    ordersNum = int_Verification(ordersNum);
    int length = ordersNum; // To keep the original length that has been provided by the player
    OrderList orderList;
    Order order;
    while (ordersNum > 0)
    {
        choice_of_orders();
        int choice = 0;
        cin >> choice;
        choice = int_Verification(choice);
        orderList.add(order,choice);
        ordersNum--;
    }
    orderList.print();
}