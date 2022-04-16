#include "Orders.h"
#include "Player.h"
#include "Map.h"
#include "GameEngine.h"


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

    return 0;
}