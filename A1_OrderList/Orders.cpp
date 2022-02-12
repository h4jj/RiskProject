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

int OrderList::orderItems = 0;

void OrderList::add(int orderType)
{
    if(head == nullptr && tail == nullptr) { // initial case - empty Order List

        std::cout << "Initial case - empty List" << std::endl;

        switch(orderType) {
            case 1:
                {
                    Deploy* depObject = new Deploy(nullptr, 1);
                    this->head = depObject;
                    this->tail = depObject;
                    std::cout << "Deploy object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 2:
                {
                    Advance* advObject = new Advance(nullptr, 2);
                    this->head = advObject;
                    this->tail = advObject;
                    std::cout << "Advance object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 3:
                {
                    Bomb* bombObject = new Bomb(nullptr, 3);
                    this->head = bombObject;
                    this->tail = bombObject;
                    std::cout << "Bomb object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 4:
                {
                    Blockade* blockadeObject = new Blockade(nullptr, 4);
                    this->head = blockadeObject;
                    this->tail = blockadeObject;
                    std::cout << "Blockade object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 5:
                {
                    Airlift* airliftObject = new Airlift(nullptr, 5);
                    this->head = airliftObject;
                    this->tail = airliftObject;
                    std::cout << "Airlift object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 6:
                {
                    Negotiate* negotiateObject = new Negotiate(nullptr, 6);
                    this->head = negotiateObject;
                    this->tail = negotiateObject;
                    std::cout << "Negotiate object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }

            default:
                {
                    std::cout << "Invalid Order type" << std::endl;
                }
        }
    } 

    else {
        switch(orderType) {

            

            case 1:
                {
                    Deploy* deployObj = new Deploy(nullptr, 1);
                    this->tail->next = deployObj;
                    this->tail = deployObj;
                    std::cout << "Deploy object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 2:
                {
                    Advance* advanceObj = new Advance(nullptr, 2);
                    this->tail->next = advanceObj;
                    this->tail = advanceObj;
                    std::cout << "Advance object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 3:
                {
                    Bomb* bombObject = new Bomb(nullptr, 3);
                    this->tail->next = bombObject;
                    this->tail = bombObject;
                    std::cout << "Bomb object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 4:
                {
                    Blockade* blockadeObject = new Blockade(nullptr, 4);
                    this->tail->next = blockadeObject;
                    this->tail = blockadeObject;
                    std::cout << "Blockade object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 5:
                {
                    Airlift* airliftObject = new Airlift(nullptr, 5);
                    this->tail->next = airliftObject;
                    this->tail = airliftObject;
                    std::cout << "Airlift object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            case 6:
                {
                    Negotiate* negotiateObject = new Negotiate(nullptr, 6);
                    this->tail->next = negotiateObject;
                    this->tail = negotiateObject;
                    std::cout << "Negotiate object successfully created and added to List" << std::endl;
                    OrderList::orderItems++;
                    break;
                }
            
            default:
                std::cout << "Invalid Order type" << std::endl;
        }
    }

    std::cout << "List has " << OrderList::orderItems << " Order objects" << std::endl;                                              
}

void OrderList::print() {
    
    if(this->head != nullptr) {
        
        Order* curr = this->head;

        while(true) {

            if(curr == nullptr) {
                break;
            }

            std::cout << "Order ID: " << curr->orderType << std::endl;
            curr = curr->next;
        }
    }
    else {
        std::cout << "Empty list" << std::endl;
    }
}





