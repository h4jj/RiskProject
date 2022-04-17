#pragma once
#include <iostream>
#include "Orders.h"
#include "Cards.h"
#include "Map.h"
#include <list>
#include "PlayerStrategies.h"

class GameEngine;
class OrderList;
class Territory;

class Player 
{  
public:
    Player();
    Player(std::string); // Constructor
    ~Player(); // Destructor
    Player(const Player&); // Copy Constructor
    Player& operator=(const Player&); // assignment operator
    std::vector<Territory*> toAttack(PlayerStrategy*); // Returns a list of arbitrary Territories
    std::vector<Territory*> toDefend(PlayerStrategy*); // Returns a list of arbitrary Territories
    void issueOrder(PlayerStrategy*); // creates an Order object and adds it to orderListObject below
    void setUnattackable(std::string);
    void printTerritories();
public:
    PlayerStrategy* ps;
    Map* map = nullptr;
    std::vector<Territory*> territories;
    GameEngine* gEng;
    OrderList* orderListObject; // pointer to an OrderList object that will store all Orders for a player  
    Hand* hand;   // pointer to hand object that includes a vector of cards
    std::string name, unAttackableName;
    int reinforcementPool;
};