#include <iostream>
#include "Orders.h"

using namespace std;

OrderList::OrderList() // OrderList is to be considered as the 
: head(nullptr)        // linked list
{                      
    cout << "hello" << endl;
}
void OrderList::add(Order o, int orderType)
{
    if(head == nullptr)
    {
        // If the list is empty
        head = new Order(&o, nullptr, orderType);
        cout << "Empty case" << endl;
    } 
    else
    {
        // If the list is not empty
        Order* p = head; // p is to be understood as the pointer that will traverse the list
        while(p->next != nullptr) // The while loop makes the p pointer visit every order
        {
            p = p->next; // p points to the next order
        }
        Order* newOrder = new Order(nullptr, p, orderType);// a new order is added connected to the last 
        p->next = newOrder;  
        cout << "Non-empty case" << endl;                              // order and pointing to a nullptr
    }                                               
}

void OrderList::print()
{
    if(head == nullptr)
    {
        // If the list is empty
        cout << "The list is empty" << endl;
    } 
    else
    {
        // If the list is not empty
        Order* p = head; // p is to be understood as the pointer that will traverse the list
        while(p != nullptr) // The while loop makes the p pointer visit every order
        {
            cout << "Order type: " << p->orderType << endl;
            cout << "printing..." << endl;
            p = p->next; // p points to the next order
            
        }
        
    }                                               
}


void OrderList::move()
{
    
}

void OrderList::remove()
{

}
Order::Order()
{

}

Order::Order(Order* next, Order* prev, int orderType) // Order is to be taken as the node
: next(next), prev(prev), orderType(orderType)        // of the linked list
{
   
}
/*
 switch (orderNumber)
    {
    case 1:
    cout << "hello";
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default: // The program stops for invalid input
        cout << "There was an error " << orderNumber << " not an order!" << endl;
        exit(0);
        break;
    }
*/
void Order::validate()
{

}

void Order::execute()
{
    
}





