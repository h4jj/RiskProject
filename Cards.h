#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Card
{

public:
    Card();                               // default constructor
    ~Card();                              // destructor
    void initialCardsType();              // initial card type
    vector<string> *getPointerToVector(); // vector that pointes to the vectors
    void printVectorCards();              //print the cards of vector
    void setCardType(int typeValue);      //setter for card type
    void getCardType();                   // get card type

private:
    vector<string> CardsTypes; // vector of card pointers
    string *cardType;          //string that store card type
};

class Deck
{

public:
    Deck();                          // default constructor
    ~Deck();                         // destructor
    void initialDeck();              //initial Deck to assign 25 cards, each type has 5 cards
    void printSizeOfDeck();          //print the size of deck
    void printDeck();                //print the cards in the deck
    void addCardToDeck(Card *aCard); //add card to deck
    Card *draw();                    // draw a card at random from the cards remaining in the deck and place it in their hand.

private:
    vector<Card *> deckCards; // vector of card pointers to deck
    Card *pointerToCard;      // pointer to card
    Card *cardTmp;            // temp card to draw and remove a card from deck
};

class Hand
{

public:
    Hand();                           //default constructor
    ~Hand();                          //destructor
    void setHandCards(Card *aCard);   //setter for hand cards
    vector<Card *> *getCardInHand();  //vector that pointes to the cardsInHand
    vector<Card *> *getCardsToPlay(); //vector that pointes to the cardsToPlay
    void printHandCards();            //print the hand cards
    void play(Card *aCard);           //play the card
    void printCardsToPlay();          //add played card to deck
    void removeAllPlayedCardsFromHand();
    void removePlayedCardsFromHand(Card *aCard);
    void addPlayedCardToDeck(Deck *aDeck);
    void clearPlayedCards();

private:
    vector<Card *> cardsInHand; // vector that stores the cards in hand
    vector<Card *> cardsToPlay; // vector that stores the cards to play
};
