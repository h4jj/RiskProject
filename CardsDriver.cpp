#include "Cards.h"

int main()
{

    //create a deck
    Deck deck1;
    //create a hand
    Hand hand1;

    //print size of deck
    cout << "The size of the deck is  " << endl;
    deck1.printSizeOfDeck();
    //print all cards in deck
    deck1.printDeck();

    //draw 5 cards and add the cards to hand
    cout << "Generate 5 cards and add them to hand" << endl;
    for (int i = 0; i < 5; i++)
    {
        hand1.setHandCards(deck1.draw());
    }
    //print size of deck
    cout << "The size of the deck is now " << endl;
    deck1.printSizeOfDeck();

    //print all cards in hand
    cout << "The hand contains " << endl;
    hand1.printHandCards();

    //play the cards in hand and add them to played cards
    cout
        << "play the cards in hand and add them to played cards" << endl;
    for (int i = 0; i < hand1.getCardInHand()->size(); i++)
    {
        hand1.play(hand1.getCardInHand()->at(i));
    }

    //print cards in hand after the cards being played
    cout << "The hand now contains " << endl;
    hand1.printHandCards();

    //print the card that were played
    cout
        << "The cards that were played are " << endl;
    hand1.printCardsToPlay();

    //add a played card to the deck
    hand1.addPlayedCardToDeck(&deck1);

    //remove all played cards from hand
    hand1.removeAllPlayedCardsFromHand();

    //print size of deck
    cout << "The size of the deck is  " << endl;
    deck1.printSizeOfDeck();

    //clear cards to play
    hand1.clearPlayedCards();

    //print the cards in hand (should be 0)
    cout << "The hand now contains " << endl;
    hand1.printHandCards();

    //print the cards to play (should be 0)
    cout << "The cards that were played are " << endl;
    hand1.printCardsToPlay();
}