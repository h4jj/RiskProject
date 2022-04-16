#include "Orders.h"
#include "Player.h"
#include "Map.h"
#include "GameEngine.cpp"


int main()
{
    Deploy order;
    Map* map = new Map();
    GameEngine* gameEng = new GameEngine();
    gameEng->showAvailableMaps();
    gameEng->pickMap();
    Player* p1 = new Player("Ahmad");
    Player* p2 = new Player("Mostafa");
    Player* p3 = new Player("Marieme");

    p1->printTerritories();

    order.armyCount = 10;
    order.player = p1;
    order.territory = "New_Brunswick";

    order.execute(); 

    return 0;
}