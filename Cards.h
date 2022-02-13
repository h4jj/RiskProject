#pragma once
#include <iostream>
#include <array>

using std::cout;
using std::endl;


enum class OrderType {
    BOMB=1,REINFORCEMENT=2,BLOCKADE=3,AIRLIFT=4,DIPLOMACY=5
};

class Card
{
public:                           
    ~Card();
    Card(int);                            
    void play();                   
private:
    OrderType cardType;         
};

class Deck
{

public:                         
    ~Deck();                                                 
    bool fillDeck(); 
    Card* draw();
    static const int deckSize = 25;                    

private:
    std::array<Card*, deckSize> deck;

};

class Hand {
public:
    Hand();
    ~Hand();
    static const int handSize = 5;

private:
    std::array<Card*, handSize> hand;

};
