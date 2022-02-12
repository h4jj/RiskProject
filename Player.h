#pragma once
#include <iostream>
#include "Orders.h"

class Player 
{  
public:
    Player(); // Constructor
    ~Player(); // Destructor
    Player(const Player&); // Copy Constructor
    void toAttack(); // Returns a list of arbitrary Territories
    void toDefend(); // Returns a list of arbitrary Territories
    void issueOrder(int); // creates an Order object and adds it to orderListObject below
public:
    OrderList* orderListObject = nullptr; // pointer to an OrderList object that will store all Orders for a player        
};