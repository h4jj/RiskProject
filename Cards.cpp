#include "Cards.h"
using namespace std;

/* 
===================================
 Card class
===================================
 */

Card::Card() // default constructor of card
{
    initialCardType();
}
Card::~Card() {} // destructor of card

void Card::initialCardsType()
{ // Pushing all types to a stack

    CardsTypes.push_back("bomb");
    CardsTypes.push_back("reinforcement");
    CardsTypes.push_back("blockade");
    CardsTypes.push_back("airlift");
    CardsTypes.push_back("displomacy");
}

//set card type
void Card::setCardType(int typeValue)
{
    cardType = &CardsTypes.at(typeValue);
}

//get card type
string *Card::getCardType()
{
    return cardType;
}

vector<string> *Card::getPointerToVector()
{
    return &CardsTypes;
}
//print vector card
void Card::printVectorCards()
{
    cout << "This vector contains the following cards:  " << endl;
    for (int j = 0; j < CardsTypes.size(); j++)
    {
        cout << CardsTypes.at(j) << endl;
    }
}

/* 
===================================
Deck class
===================================
 */

Deck::Deck() {} // default constructor of Deck

Deck::~Deck() {} // destructor of Deck

//initial Deck to assign 25 cards, each type has 5 cards
void Deck::initialDeck()
{

    for (int i = 0; i < 25; i++)
    {
        pointerToCard = new Card;
        if (i < 5)
        {
            pointerToCard->setCardType(0);
            deckCards.push_back(pointerToCard);
        }
        if (i >= 5 && i < 10)
        {
            pointerToCard->setCardType(1);
            deckCards.push_back(pointerToCard);
        }
        if (i >= 10 && i < 15)
        {
            pointerToCard->setCardType(2);
            deckCards.push_back(pointerToCard);
        }
        if (i >= 15 && i < 20)
        {
            pointerToCard->setCardType(3);
            deckCards.push_back(pointerToCard);
        }
        if (i >= 20 && i < 25)
        {
            pointerToCard->setCardType(4);
            deckCards.push_back(pointerToCard);
        }
    }
}

//print the size of current deck
void Deck::printSizeOfDeck()
{
    cout << "This deck has " << deckCards.size() << " cards. " << endl;
}

//print all cards of deck, it should has 25 cards, which has 5 types, each type has 5 cards.
void Deck::printDeck()
{
    cout << "This deck has " << deckCards.size() << " cards. " << endl;

    for (int j = 0; j < deckCards.size(); j++)
    {
        cout << "The card at " << j << " is " << *deckCards.at(i)->getCardType() << endl;
    }
}

void Deck::addCardToDeck(Card *aCard)
{ // To add a card to deckCards
    deckCards.push_back(aCard);
}

Card *Deck::draw()
{ //using draw() to randomly draw a card from deck, then add in handcards
    srand(time(0));
    int random = rand();
    int tmp = (random % deckCards.size());
    tmpCard = deckCards.at(tmp);
    deckCards.erase(deckCards.begin() + tmp);
    return tmpCard;
}

/* 
===================================
 Hand class
===================================
 */

Hand::Hand() {} // default constructor of Hand

Hand::~Hand() {} // destructor of Hand

//set hand card (add card to hand)
void Hand::setHandCards(Card *aCard)
{
    cardsInHand.push_back(aCard);
}
// Gets the cards in hand
vector<Card *> *Hand::getCardInHand()
{
    return &cardsInHand;
}
vector<Card *> *Hand::getCardsToPlay()
{
    return &cardsToPlay;
}

//print the current hand cards
void Hand::printHandCards()
{
    if (cardsInHand.size() > 0)
    {
        cout << "The hand of cards has" << cardsInHand.size() << " cards " << endl;
        for (int k = 0; k < cardsInHand.size(); k++)
        {
            cout << "The card at " << k << " is " << *cardsInHand.at(j)->getCardType() << endl;
        }
    }
    else
    {
        cout << "Hand is empty" << endl;
    }
}
// Pushes a card to the playcards
void Hand::play(Card *aCard)
{
    cardsToPlay.push_back(aCard);
}

void Hand::printCardsToPlay()
{
    if (cardsToPlay.size() > 0)
    {
        cout << "Here is the order of the playcards: " << endl;
        for (int k = 0; k < cardsToPlay.size(); k++)
        {
            cout << "The card at " << k << " is " << *cardsToPlay.at(i)->getCardType() << endl;
        }
    }
    else
    {
        cout << "There is no card to play" << endl;
    }
}
// remove a played card from Hand
void Hand::removeAllPlayedCardsFromHand()
{
    for (int i = 0; i < cardsToPlay.size(); i++)
    {
        removePlayedCardsFromHand(cardsToPlay.at(i));
    }
}
// function to remove played cards from hand
void Hand::removePlayedCardsFromHand(Card *aCard)

// Removes a card of the hand if already a card of the same type
{
    for (int k = 0; k < cardsInHand.size(); k++)
    {
        if (*cardsInHand.at(k)->getCardType() == *aCard->getCardType())
        {
            cardsInHand.erase(cardsInHand.begin() + k);
            cout << "Removing the card from hand" << *aCard->getCardType() << endl;
            return;
        }
    }
}
//return played card to deck
void Hand::addPlayedCardToDeck(Deck *aDeck)
{
    for (int i = 0; i < cardsToPlay.size(); i++)
    {
        aDeck->addCardToDeck(cardsToPlay.at(i));
    }
}

// clear played cards
void Hand::clearPlayedCards()
{
    cardsToPlay.clear();
    cout << "The played cards have been cleared." << endl;
}
