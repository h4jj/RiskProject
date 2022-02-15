#include "Player.cpp"
#include "Orders.cpp"
#include "Cards.cpp"
#include "Map.cpp"


void showlist(const std::list<Territory*>& l) {
    std::cout << "Arbitrary List contents: " <<std::endl;
    std::cout << std::endl << std::endl;

    for(auto const& item : l ) {
        std::cout << item->getCountry() << " ";
    }
    std::cout << std::endl << std::endl;
}

int main() {

    Player* Ahmad = new Player("Ahmad");
    Deck deck;

    Territory* t1 =  new Territory("Lebanon", "Asia");
    Territory* t2 =  new Territory("Syria", "Asia");
    Territory* t3 =  new Territory("Palestine", "Asia");
    Territory* t4 =  new Territory("Jordan", "Asia");
    Territory* t5 =  new Territory("Iran", "Asia");
    Territory* t6 =  new Territory("Iraq", "Asia");
    Territory* t7 =  new Territory("China", "Asia");
    Territory* t8 =  new Territory("Pakistan", "Asia");
    Territory* t9 =  new Territory("Malaysia", "Asia");
    Territory* t10 =  new Territory("Vietnam", "Asia");

    Ahmad->territories.push_back(t1);
    Ahmad->territories.push_back(t2);
    Ahmad->territories.push_back(t3);
    Ahmad->territories.push_back(t4);
    Ahmad->territories.push_back(t5);
    Ahmad->territories.push_back(t6);
    Ahmad->territories.push_back(t7);
    Ahmad->territories.push_back(t8);
    Ahmad->territories.push_back(t9);
    Ahmad->territories.push_back(t10);

    std::cout << Ahmad->territories.size() << " : Size of territory vector" << std::endl;

    std::list<Territory*> List1, List2;
    List1 = Ahmad->toAttack();
    List2 = Ahmad->toDefend();

    showlist(List1);
    showlist(List2);
    
    deck.draw(Ahmad->hand);
    deck.draw(Ahmad->hand);
    deck.draw(Ahmad->hand);
    deck.draw(Ahmad->hand);
    deck.draw(Ahmad->hand);
    deck.draw(Ahmad->hand);
    deck.draw(Ahmad->hand);

    Ahmad->issueOrder(1);
    Ahmad->issueOrder(2);
    Ahmad->issueOrder(3);

    delete t1, delete t2, delete t3, delete t4, delete t5, delete t6, delete t7, delete t8, delete t9, delete t10;
    delete Ahmad;

    return 0;
}