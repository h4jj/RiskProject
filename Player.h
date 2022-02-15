#pragma once
#include <iostream>
#include "Orders.h"
#include "Cards.h"

class Player 
{  
public:
    Player(std::string); // Constructor
    ~Player(); // Destructor
    Player(const Player&); // Copy Constructor
    Player& operator=(const Player&); // assignment operator
    void toAttack(); // Returns a list of arbitrary Territories
    void toDefend(); // Returns a list of arbitrary Territories
    void issueOrder(int); // creates an Order object and adds it to orderListObject below
public:
    OrderList* orderListObject; // pointer to an OrderList object that will store all Orders for a player  
    Hand* hand;   // pointer to hand object that includes a vector of cards
    std::string name;
};