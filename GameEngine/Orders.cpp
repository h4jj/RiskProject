#include "Orders.h"

using std::cout;
using std::endl;
using std::ostream;

Order::Order() {}
Deploy::Deploy() : Order() {};
Order::Order(Order *next, int orderType) : next(next), orderType(orderType) {}
Deploy::Deploy(Order *next, int orderType) : Order(next, orderType) { cout << "Deploy order created" << endl; }
Advance::Advance(Order *next, int orderType) : Order(next, orderType) { cout << "Advance order created" << endl; }
Bomb::Bomb(Order *next, int orderType) : Order(next, orderType) { cout << "Bomb order created" << endl; }
Blockade::Blockade(Order *next, int orderType) : Order(next, orderType) { cout << "Blockade order created" << endl; }
Airlift::Airlift(Order *next, int orderType) : Order(next, orderType) { cout << "Airlift order created" << endl; }
Negotiate::Negotiate(Order *next, int orderType) : Order(next, orderType) { cout << "Negotiate order created" << endl; }
OrderList::OrderList() : head(nullptr), tail(nullptr) { cout << "Empty OrderList Successfully Created" << endl; }

void OrderList::add(Order *o)
{
    if (head == nullptr && tail == nullptr)
    { // initial case - empty Order List

        std::cout << "Initial case - empty List" << std::endl;

        this->head = o;
        this->tail = o;
    }
    else
    {
        // Non-empty case
        this->tail->next = o;
        this->tail = o;
    }

    std::cout << "List has " << OrderList::length() << " Order objects" << std::endl;
}

// The functions prints every members of the list
void OrderList::print()
{

    if (this->head != nullptr)
    {
        // When the list is not empty
        Order *curr = this->head;

        while (curr != nullptr)
        {

            std::cout << "Order ID: " << curr->orderType << std::endl;
            curr = curr->next;
        }
    }
    else
    {
        // When the list is empty
        std::cout << "Empty list" << std::endl;
    }
}

// Accessor for head
const Order *OrderList::getHead()
{
    return head;
}

// Accessor for tail
const Order *OrderList::getTail()
{
    return tail;
}

// The function moves an order from one position in the list to another
void OrderList::move(int position, int newPosition) // position is the index of the order to move
{                                                   // newPosition is the index the order has to be moved to

    if (position < 0 || position > OrderList::length() || newPosition < 0 || newPosition > OrderList::length())
    {
        cout << "The position(s) is(are) not valid" << endl;
    }
    else if (position == newPosition)
    {
        cout << "The new position is the same as the actual position" << endl;
    }
    else
    {
        if (head == nullptr)
        {
            // The list is empty
            cout << "The list is empty" << endl;
        }
        else if (head->next == nullptr)
        {
            // The list only has one order
            cout << "There's only one order in the list, it cannot move anywhere" << endl;
        }
        else
        {
            Order *beforeP = this->head; // Temporary pointer to that is used to traverse the list
            if (position == 1)
            {
                this->head = beforeP->next;

                Order *holder = beforeP;
                beforeP->next = beforeP->next->next;
                holder->next = nullptr;

                Order *beforeNP = this->head;

                // Traverse the list to the new position
                if (newPosition < position)
                {
                    while (newPosition > 1)
                    {
                        beforeNP = beforeNP->next;
                        newPosition--;
                    }
                }
                else
                {
                    while (newPosition > 2)
                    {
                        beforeNP = beforeNP->next;
                        newPosition--;
                    }
                }
                holder->next = beforeNP->next;
                beforeNP->next = holder;
            }
            else if (newPosition == 1)
            {
                while (position > 2)
                {
                    beforeP = beforeP->next;
                    position--;
                }
                Order *holder = beforeP->next;
                beforeP->next = beforeP->next->next;
                holder->next = nullptr;
                holder->next = head;
                head = holder;
            }
            else
            {
                // When the position is other that one, it needs to traverse the list
                while (position > 2)
                {
                    beforeP = beforeP->next;
                    position--;
                }
                Order *holder = beforeP->next;
                beforeP->next = beforeP->next->next;
                holder->next = nullptr;

                Order *beforeNP = this->head;

                // Traverse the list to the new position
                if (newPosition < position)
                {
                    while (newPosition > 1)
                    {
                        beforeNP = beforeNP->next;
                        newPosition--;
                    }
                }
                else
                {
                    while (newPosition > 2)
                    {
                        beforeNP = beforeNP->next;
                        newPosition--;
                    }
                }
                holder->next = beforeNP->next;
                beforeNP->next = holder;
            }
        }
    }
}

// The function removes an order at a given position
void OrderList::remove(int position)
{
    int positionTemp = position; // To keep track of the original position
    if (head == nullptr)
    {
        // The list is empty
        cout << "Nothing to be removed" << endl;
    }
    else if (position < 0 || position > OrderList::length())
    {
        // The input is invalid
        cout << "Entered position is not valid" << endl;
    }
    else
    {
        Order *beforeP = this->head; // Temporary pointer to that is used to traverse the list
        if (position == 1)
        {
            // When the position is 1 no need to traverse the list
            head = beforeP->next;
            delete beforeP;
        }
        else
        {
            // When the position is other that one, it needs to traverse the list
            while (position > 2)
            {
                beforeP = beforeP->next;
                position--;
            }
            beforeP->next = beforeP->next->next;
            if (positionTemp == OrderList::length()) // When the last position is removed,
            {                                        // the tail has to be set again
                this->tail = beforeP->next;
            }
            delete beforeP;
        }
    }
}

// The function return the length of the list
int OrderList::length()
{
    if (head == nullptr)
    {
        // The list is empty
        return 0;
    }
    else
    {
        // The list is not empty
        Order *curr = this->head;
        int length = 0;
        while (curr != nullptr)
        {
            length++;
            curr = curr->next;
        }
        return length;
    }
}

// Validation function
void Order::validation()
{
    cout << orderType << " is being validated..." << endl;
}

// Execution function
void Order::execution()
{
    Order::validation();
    cout << orderType << " is being executed..." << endl;
}

// Copy constructor (deep copy) of Order
Order::Order(const Order &o)
{
    orderType = o.orderType;
    next = nullptr;
}

// Copy constructor (deep copy) of OrderList
OrderList::OrderList(const OrderList &ol)
{

    if (head == nullptr)
    {
        // Empty list case
        cout << "The list is empty." << endl;
    }
    // else
    // {
    //     // First, we set the tail and head on the first order manually (wihtout the loop)
    //     Order *temp = ol.head;
    //     head = new Order(*(temp));
    //     tail = head;
    //     Order *curr = head;
    //     // Second, all the orders are copied and linked to each other
    //     while (temp->next != nullptr)
    //     {
    //         temp = temp->next;
    //         curr->next = new Order(*(temp));
    //         curr = curr->next;
    //         tail = curr;
    //     }
    // }
}

// Stream insertion operator implementation
ostream &operator<<(ostream &out, Order &o)
{
    switch (o.orderType)
    {
    case 1:
        out << "Deploy order: place some armies on one of the current player’s territories." << endl;
        break;
    case 2:
        out << "Advance order: move some armies from one of the current player’s territories (source) to an adjacent territory\n"
            << "(target). If the target territory belongs to the current player, the armies are moved to the target\n"
            << "territory. If the target territory belongs to another player, an attack happens between the two\n"
            << "territories." << endl;
        break;
    case 3:
        out << "Bomb order: destroy half of the armies located on an opponent’s territory that is adjacent to one of the current\n"
            << "player’s territories." << endl;
        break;
    case 4:
        out << "Blockade order: triple the number of armies on one of the current player’s territories and make it a neutral territory." << endl;
        break;
    case 5:
        out << "Airlift order: advance some armies from one of the current player’s territories to any another territory." << endl;
        break;
    case 6:
        out << "Negotiate order: prevent attacks between the current player and another player until the end of the turn." << endl;
        break;
    default:
        out << "There is a mistake, this order doesn't exist." << endl;
    }
    out << "Execution satus: " << endl;
    o.execution();

    return out;
}

void Deploy::execute() {
    
    bool isValid = false;
    Territory* t = nullptr;
    if(player != nullptr) {
        for(const auto& _t : player->territories) {
            if(_t->getCountry() == territory) {
                isValid = true;
                t = _t;
                break;
            } 
        }

        if(!isValid){
            std::cout << "You do not own this territory, please try a different one" << std::endl;
            return;
        }

        t->setArmyCount(armyCount);
        std::cout << armyCount << " troops deployed to " << t->getCountry() << std::endl;
    }
    else {
        std::cout << "Deploy ordered not properly configured" << std::endl;
    }   
}

void Advance::execute() {
    // std::cout << "t1: " << t1 << std::endl;
    // if(player != nullptr) {

    // }
}

void Blockade::execute() {

    Territory* t = nullptr;
    int index = 0;

    for(const auto& _t : player->territories) {
        if(_t->getCountry() == t1) {
            t = _t;
            break;
        }
        index++;
    }

    if(t == nullptr) {
        std::cout << "Order is invalid, you do not own this territory" << std::endl;
        return;
    }

    t->setArmyCount(t->getArmyCount() * 2);
    neutralPlayer = new Player("neutral player");
    neutralPlayer->territories.push_back(t);
    player->territories.erase(player->territories.begin() + index);

    std::cout << "Army count at territory " << t->getCountry() << " has increased from " << t->getArmyCount() / 2 << " to " << t->getArmyCount() << " and is now owned by the neutral player" << std::endl;
    return;
}

void Bomb::execute() {

    Territory* t = nullptr;

    for(const auto& _t : player->territories) {
        if(_t->getCountry() == t1) {
            t = _t; 
            break;
        }
    }

    if(t != nullptr) {
        std::cout << "Order is invalid, you own this territory" << std::endl;
        return;
    }


}

void Airlift::execute() {

    Territory *source = nullptr, *target = nullptr;

    for(const auto& t : player->territories) {
        if(t->getCountry() == t1) {
            source = t;
        }
        else if(t->getCountry() == t2) {
            target = t;
        }
    }

    if(source == nullptr || target == nullptr ) {
        std::cout << "Order is invalid, you do not own both territories" << std::endl;
        return;
    }

    source->setArmyCount(source->getArmyCount() - armyCount);
    target->setArmyCount(target->getArmyCount() + armyCount);
    std::cout << armyCount << " troops successfully deployed from " << source->getCountry() << " to " << target->getArmyCount() << std::endl;
}

void Negotiate::execute() {

}