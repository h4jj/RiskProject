#include "Cards.h"


Card::~Card() {std::cout << "Card object successfully destroyed" << std::endl;} 

Card::Card(int _cardType) {
    
    switch(_cardType) {
        case 1:
        {
            cardType = OrderType::BOMB;
            break;
        }
        case 2:
        {
            cardType = OrderType::REINFORCEMENT;
            break;
        }
        case 3:
        {
            cardType = OrderType::BLOCKADE;
            break;
        }
        case 4:
        {
            cardType = OrderType::AIRLIFT;
            break;
        }
        case 5:
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

