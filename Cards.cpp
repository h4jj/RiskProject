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
/* 
===================================
Deck class
===================================
 */

bool fillDeck = false;
for (int i = 0; i < deckSize; i++)
{
    do
    {
        card.cardType()
            fillDeck = Deck(card, i);
    } while (fillDeck == true);
    fillDeck = false;
    card[i] = card;
}
Card *draw(Deck &deck)
{
    int randomCard = rand() % deckSize();
    Card *temp = deck.at(randomCard);
    cout << randomCard << "-" << *deck.at(randomCard) << " | ";
    deckSize--;
    randomCard--;
    return temp;
}
std::array<Card *, deckSize> deck()
{

    return Deck[deckSize--];
    [handSize++]
}
/* 
===================================
 Hand class
===================================
 */
Hand::~Hand() { std::cout << "Hand object successfully destroyed" << std::endl; }
Hand::Hand() {} // default constructor of Hand

std::array<Card *, handSize> hand()
{
}
}
