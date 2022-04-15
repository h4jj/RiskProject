#pragma once
#include <iostream>
#include <queue>
#include "Orders.h"

using std::cout;
using std::endl;


enum class OrderType {
    BOMB=0,REINFORCEMENT=1,BLOCKADE=2,AIRLIFT=3,DIPLOMACY=4
};

class Card
{
public:                           
    ~Card();
    Card(int);                            
    Order* play();                   
public:
    OrderType cardType;         
};


class Hand {

public:
    static const int handSize = 5;
    std::queue<Card*> handVector;

};

class Deck
{
public: 
    Deck();                        
    ~Deck();                                                 
    void draw(Hand*);
    static const int deckSize = 25;                    

private:
    std::vector<Card*> deck;
};
