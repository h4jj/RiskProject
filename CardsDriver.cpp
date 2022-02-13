#include "Cards.cpp"

int main()
{
    Card card1(1);
    Card card2(2);

    return 0;
    return 0;
    //create a deck
    Deck deck1;
    //create a hand
    Hand hand1;

    //draw 5 cards and add the cards to hand
    cout << "Generate 5 cards and add them to hand" << endl;
    for (int i = 0; i < deckSize; i++)
    {
        deck1.draw(card1));
    }

    //play the cards in hand and add them to played cards
    cout
        << "play the cards in hand and add them to played cards" << endl;
    for (int i = 0; i < handSize; i++)
    {
        hand1.play(card(1));
    }
}
