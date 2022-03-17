#include "Cards.h"
#include <stdlib.h>

Card::~Card() {std::cout << "Card object successfully destroyed" << std::endl;} 

Card::Card(int _cardType) {
    
    switch(_cardType) {
        case 0:
        {
            cardType = OrderType::BOMB;
            break;
        }
        case 1:
        {
            cardType = OrderType::REINFORCEMENT;
            break;
        }
        case 2:
        {
            cardType = OrderType::BLOCKADE;
            break;
        }
        case 3:
        {
            cardType = OrderType::AIRLIFT;
            break;
        }
        case 4:
        {
            cardType = OrderType::DIPLOMACY;
            break;
        }
        default: std::cout << "Invalid Order Type" << std::endl;
    }
    
    std::cout << "Card object of type " << (int)cardType << " successfully created" << std::endl;
}

void Card::play() {
    
}


Deck::~Deck() {std::cout << "Deck object successfully destroyed" << std::endl;}

Deck::Deck() {
    for(size_t i{0}; i<Deck::deckSize; i++) {
        Card* cardObject = new Card(i%5);
        this->deck.push_back(cardObject);
    }
}

void Deck::draw(Hand* handObject) {

    if(handObject->handVector.size() < 5) {

        srand(time(0));
        int randNumber = rand() % deck.size();

        handObject->handVector.push(this->deck[randNumber]);

        std::cout << "New Card successfully added to hand vector; Length of hand is: " << handObject->handVector.size() << std::endl; 

        this->deck.erase(this->deck.begin() + randNumber);

        std::cout << "Card successfully removed from deck; Length of deck is now: " << this->deck.size() << std::endl;

    }
    else {
        std::cout << "Hand is full you cannot draw anymore cards" << std::endl;
    }
}
