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

std::vector<Card*> Deck::getDeck() {
    return this->deck;
}

Card* Deck::draw() {
    if(this->deck.size() != 0) {
        srand(time(0));
        int randNumber = rand() % deck.size();

        Card* card = nullptr;
        card = this->deck.at(randNumber);
        this->deck.erase(this->deck.begin() + randNumber);
        std::cout << "Card successfully withdrawn from deck" << std::endl;
        std::cout << "Size of deck is now: " << this->deck.size() << std::endl;
        return card;

    }   
    else {
        std::cout << "Deck is empty cannot draw anymore cards" << std::endl;
    }

    std::cout << "Was unable to withdraw card from deck" << std::endl;
    return nullptr;
    
}