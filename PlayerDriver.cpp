#include "Player.cpp"
#include "Orders.cpp"
#include "Cards.cpp"


int main() {

    Player playerObj;
    Deck deck;

    deck.draw(playerObj.hand);
    deck.draw(playerObj.hand);
    deck.draw(playerObj.hand);
    deck.draw(playerObj.hand);
    deck.draw(playerObj.hand);
    deck.draw(playerObj.hand);
    deck.draw(playerObj.hand);

    playerObj.issueOrder(1);
    playerObj.issueOrder(2);
    playerObj.issueOrder(3);


    return 0;
}