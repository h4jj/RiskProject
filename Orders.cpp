#include "Orders.h"
using std::cout;
using std::endl;

Order::Order(Order* next, int orderType) : next(next), orderType(orderType) {}
Deploy::Deploy(Order* next, int orderType) : Order(next, orderType) {}
Advance::Advance(Order* next, int orderType) : Order(next, orderType) {}
Bomb::Bomb(Order* next, int orderType) : Order(next, orderType) {}
Blockade::Blockade(Order* next, int orderType) : Order(next, orderType) {}
Airlift::Airlift(Order* next, int orderType) : Order(next, orderType) {}
Negotiate::Negotiate(Order* next, int orderType) : Order(next, orderType) {}
OrderList::OrderList() : head(nullptr), tail(nullptr) {cout << "Empty OrderList Successfully Created" << endl;}

Deploy::~Deploy() {std::cout << "Deploy object successfully destroyed" << std::endl;}
Advance::~Advance() {std::cout << "Advance object successfully destroyed" << std::endl;}
OrderList::~OrderList() {std::cout << "OrderList object successfully destroyed" << std::endl;}


int OrderList::orderItems = 0;

void OrderList::add(Order* orderObject)
{
    if(head == nullptr && tail == nullptr) { // initial case - empty Order List

        std::cout << "Initial case - empty List" << std::endl;
        this->head = orderObject;
        this->tail = orderObject;
        std::cout << "Order object successfully created and added to List" << std::endl;
        OrderList::orderItems++;
    } 

    else {
       
        this->tail->next = orderObject;
        this->tail = orderObject;
        std::cout << "Order object successfully created and added to List" << std::endl;
        OrderList::orderItems++;
    }

    std::cout << "List has " << OrderList::orderItems << " Order objects" << std::endl;                                              
}

void OrderList::print() {
    
    if(this->head != nullptr) {
        
        Order* curr = this->head;

        while(curr != nullptr) {

            std::cout << "Order ID: " << curr->orderType << std::endl;
            curr = curr->next;
        }
    }
    else {
        std::cout << "Empty list" << std::endl;
    }
}





