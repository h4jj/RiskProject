#include "Cards.cpp"


int main() {

    Deck deck;

    std::cout << "Size of deck is: " << deck.getDeck().size() << std::endl;

    Card* card = nullptr;

    card = deck.draw();

    return 0;
}