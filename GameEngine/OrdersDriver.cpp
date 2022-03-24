#include "Orders.h"
#include "Player.h"
#include "Map.h"
#include "Map.cpp"
#include "Player.cpp"
#include "Orders.cpp"
#include "LogObserver.cpp"
int main()
{
    MapLoader *ml = new MapLoader();
    ml->readMap("canada.map");
    Player* p1 = new Player("Ahmad");
    Player* p2 = new Player("Mostafa");
    Player* p3 = new Player("Marieme");
    p1->issueOrder(1);
    p1->issueOrder(2);
    p1->issueOrder(3);
    p1->issueOrder(4);
    p1->issueOrder(5);
    p1->issueOrder(6);
    Order *r = new Deploy(nullptr, 1);
    r->execute();
    return 0;
}