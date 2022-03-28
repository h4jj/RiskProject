#include "Orders.h"
#include <sstream>
#include "LogObserver.cpp"

using std::cout;
using std::endl;
using std::ostream;

Order::Order() {}
Order::Order(Order *next, int orderType) : next(next), orderType(orderType) {}
Deploy::Deploy(Order *next, int orderType) : Order(next, orderType) { cout << "Deploy order created" << endl; }
Advance::Advance(Order *next, int orderType) : Order(next, orderType) { cout << "Advance order created" << endl; }
Bomb::Bomb(Order *next, int orderType) : Order(next, orderType) { cout << "Bomb order created" << endl; }
Blockade::Blockade(Order *next, int orderType) : Order(next, orderType) { cout << "Blockade order created" << endl; }
Airlift::Airlift(Order *next, int orderType) : Order(next, orderType) { cout << "Airlift order created" << endl; }
Negotiate::Negotiate(Order *next, int orderType) : Order(next, orderType) { cout << "Negotiate order created" << endl; }
OrderList::OrderList() : head(nullptr), tail(nullptr) { cout << "Empty OrderList Successfully Created" << endl; }

std::string OrderList::stringToLog(){
    std::stringstream ss;
    std::string s;
    ss << tail->orderType;
    ss >> s;
    return "Order added to the order list: " + s + ".\n";
}
void OrderList::Notify(ILoggable *ol){
    LogObserver lo;
    lo.Update(ol);
}
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
    Notify(this);
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

void Deploy::Notify(ILoggable *d){
    LogObserver lo;
    lo.Update(d);
}
void Advance::Notify(ILoggable *a){
    LogObserver lo;
    lo.Update(a);
}
void Blockade::Notify(ILoggable *b){
    LogObserver lo;
    lo.Update(b);
}
void Bomb::Notify(ILoggable *bo){
    LogObserver lo;
    lo.Update(bo);
}
void Airlift::Notify(ILoggable *al){
    LogObserver lo;
    lo.Update(al);
}
void Negotiate::Notify(ILoggable *n){
    LogObserver lo;
    lo.Update(n);
}

std::string Deploy::stringToLog(){
    return "Deploy order executed.\n";
}
std::string Advance::stringToLog(){
    return "Advance order executed.\n";
}
std::string Blockade::stringToLog(){
    return "Blockafe order executed.\n";
}
std::string Bomb::stringToLog(){
    return "Bomb order executed.\n";
}
std::string Airlift::stringToLog(){
    return "Airlift order executed.\n";
}
std::string Negotiate::stringToLog(){
    return "Negotiate order executed.\n";
}

void Deploy::execute() {
    std::cout << "Executing deploy order" << std::endl;
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
        std::cout << "Total troops available on territory are: " << t->getArmyCount() << std::endl;
        Notify(this);
    }
    else {
        std::cout << "Deploy ordered not properly configured" << std::endl;
    }   
}

void Advance::execute() {
    std::cout << "Executing advance order" << std::endl;
    Territory *terr1 = nullptr, *terr2 = nullptr;

    for(const auto& _t : src->territories) {
        if(_t->getCountry() == t1) {
            terr1 = _t;
            break;
        }
    }

    if(terr1 == nullptr) {
        std::cout << "Order is invalid, you do not own source territory, returning" << std::endl;
        return;
    }
    Notify(this);
    for(const auto& t : src->territories) {
        for(const auto& edge : edges) {
            if(edge->AdjacencyEdges.first == t || edge->AdjacencyEdges.second == t) {
                if(edge->AdjacencyEdges.first->getCountry() == t2) {
                    terr2 = edge->AdjacencyEdges.first;
                    break;
                }
                else if(edge->AdjacencyEdges.second->getCountry() == t2) {
                    terr2 = edge->AdjacencyEdges.second;
                    break;
                }
            }
        }

        if(terr2 != nullptr) break;
    }

    if(terr2 != nullptr) {
        std::cout << "Target territory is correct and territories are adjacent" << std::endl;
        bool playerOwner = false;
        for(const auto& t : src->territories) {
            if(terr2 == t) {
                playerOwner = true;
                break;
            }
        }
        int tempValue = armyCount;
        if(playerOwner) {
            terr1->setArmyCount(terr1->getArmyCount() - armyCount);
            terr2->setArmyCount(terr2->getArmyCount() + armyCount);
        }
        else {

            
            std::cout << "Attack between " << terr1->getCountry() << " and " << terr2->getCountry() << " is initiating" << std::endl;
            std::cout << "t1: " << terr1->getArmyCount() << std::endl;
            std::cout << "t2: " << terr2->getArmyCount() << std::endl;

            std::random_device                  rand_dev;
            std::mt19937                        generator(rand_dev());
            std::uniform_real_distribution<float>  distr(0,1);
            // exit(0);
            while(true) {

                if(armyCount <= 0) {
                    std::cout << terr1->getCountry() << " has been defeated" << std::endl;
                    break;
                }
                else if(terr2->getArmyCount() <= 0) {
                    std::cout << terr2->getCountry() << " has been defeated" << std::endl;
                    break;
                }

                float number1 = distr(generator);
                
                if(number1 < 0.6) {
                    terr2->setArmyCount(terr2->getArmyCount() - 1);
                    std::cout << "1 troop killed at " << terr2->getCountry() << ", amount of troops left is: " << terr2->getArmyCount() << std::endl;
                }
                float number2 = distr(generator);
                if(number2 < 0.7) {
                    std::cout << "1 troop killed at " << terr1->getCountry() << ", amount of troops left is: " << armyCount << std::endl;
                    armyCount -= 1;
                }
            }

            if(terr2->getArmyCount() == 0) {
                std::cout << "Player: " << src->name << " has conquered " << terr2->getCountry() << " and now owns it" << std::endl;
                terr1->setArmyCount(terr1->getArmyCount() - armyCount);
                std::cout << "Current troops on " << terr1->getCountry() << " are: " << terr1->getArmyCount() << std::endl;
                std::cout << "Current troops on " << terr2->getCountry() << " are: " << terr2->getArmyCount() << std::endl;
                src->territories.push_back(terr2);
                
                int index = 0;

                target = nullptr;

                for(const auto p : src->gEng->Players) {
                    if(p->name == src->name) continue;
                    
                    for(const auto t : p->territories) {
                        std::cout << "SIZE OF TERRS: " << p->territories.size() << std::endl;
                        std::cout << "t->getCountry: " << t->getCountry() << std::endl;
                        std::cout << "terr2->getCountry: " << terr2->getCountry() << std::endl;
                        if(t->getCountry() == terr2->getCountry()) {
                            target = p;
                            std::cout << "Target player found: " << target->name << std::endl;
                            break;
                        }
                        index++;
                    }

                    if(target != nullptr) {
                        break;
                    }
                }
                
                if(target != nullptr) {
                    std::cout << "Successfully erased territory from player vector" << std::endl;
                    target->territories.erase(target->territories.begin() + index);
                }
                
                std::cout << "Returning to reinforcement phase" << std::endl;
            }
            else {
                std::cout << "Player: " << src->name << " was unable to conquer " << terr2->getCountry() << std::endl;
                terr1->setArmyCount(terr1->getArmyCount() - tempValue);
                std::cout << "Current troops on " << terr1->getCountry() << " are: " << terr1->getArmyCount() << std::endl;
                std::cout << "Current troops on " << terr2->getCountry() << " are: " << terr2->getArmyCount() << std::endl;
            }
        }
    }
    else {
        std::cout << "Territories are not adjacent, order is invalid" << std::endl;
        return;
    }



}

void Blockade::execute() {
    std::cout << "Executing blockade order" << std::endl;
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
    Notify(this);
    t->setArmyCount(t->getArmyCount() * 2);
    neutralPlayer = new Player("neutral player");
    neutralPlayer->territories.push_back(t);
    player->territories.erase(player->territories.begin() + index);

    std::cout << "Army count at territory " << t->getCountry() << " has increased from " << t->getArmyCount() / 2 << " to " << t->getArmyCount() << " and is now owned by the neutral player" << std::endl;
    return;
}

void Bomb::execute() {
    std::cout << "Executing bomb order" << std::endl;
    Territory* t = nullptr;

    for(const auto& _t : owner->territories) {
        if(_t->getCountry() == t1) {
            t = _t; 
            break;
        }
    }

    if(t != nullptr) {
        std::cout << "Order is invalid, you own this territory" << std::endl;
        return;
    }

    Territory* target = nullptr;

    for(const auto& t : owner->territories) {
        for(const auto& edge : edges) {
            if(edge->AdjacencyEdges.first == t || edge->AdjacencyEdges.second == t) {
                if(edge->AdjacencyEdges.first->getCountry() == t1) {
                    target = edge->AdjacencyEdges.first;
                    break;
                }
                else if(edge->AdjacencyEdges.second->getCountry() == t1) {
                    target = edge->AdjacencyEdges.second;
                    break;
                }
            }
        }

        if(target != nullptr) break;
    }

    if(target != nullptr) {
        target->setArmyCount(target->getArmyCount() / 2);
        Notify(this);
    }
    else {
        std::cout << "Territories are not adjacent, cannot issue bomb order" << std::endl;
        return;
    }



}

void Airlift::execute() {
    std::cout << "Executing airlift order" << std::endl;
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
    Notify(this);
    source->setArmyCount(source->getArmyCount() - armyCount);
    target->setArmyCount(target->getArmyCount() + armyCount);
    std::cout << armyCount << " troops successfully deployed from " << source->getCountry() << " to " << target->getArmyCount() << std::endl;
}

void Negotiate::execute() {
    std::cout << "Executing negotiate order" << std::endl;
    if(target == src) {
        std::cout << "Invalid order, target selected is the same as source" << std::endl;
        return;
    }
    Notify(this);
    src->unAttackableName = target->name;
    target->unAttackableName = src->name;

    return;

}