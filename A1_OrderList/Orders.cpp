#include "Orders.h"
using std::cout;
using std::endl;

Order::Order(Order *next, int *orderType) : next(next), orderType(orderType) {}
Deploy::Deploy(Order *next, int *orderType) : Order(next, orderType) { cout << "Deploy order created" << endl; }
Advance::Advance(Order *next, int *orderType) : Order(next, orderType) { cout << "Advance order created" << endl; }
Bomb::Bomb(Order *next, int *orderType) : Order(next, orderType) { cout << "Bomb order created" << endl; }
Blockade::Blockade(Order *next, int *orderType) : Order(next, orderType) { cout << "Blockade order created" << endl; }
Airlift::Airlift(Order *next, int *orderType) : Order(next, orderType) { cout << "Airlift order created" << endl; }
Negotiate::Negotiate(Order *next, int *orderType) : Order(next, orderType) { cout << "Negotiate order created" << endl; }
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

            std::cout << "Order ID: " << *(curr->orderType) << std::endl;
            curr = curr->next;
        }
    }
    else
    {
        // When the list is empty
        std::cout << "Empty list" << std::endl;
    }
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
                cout << *(head->orderType) << endl;
                cout << *(beforeP->next->orderType) << endl;
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
            else if(newPosition == 1)
            {
                while (position > 2)
                {
                    beforeP = beforeP->next;
                    position--;
                }
                Order *holder = beforeP->next;
                beforeP->next = beforeP->next->next;
                holder->next = nullptr;
                cout << *(head->next->orderType) << endl;
                cout << *(holder->orderType) << endl;
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