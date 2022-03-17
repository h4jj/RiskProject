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
    order.player = p1;
    std::string config1;


    order.execute();

    while(true);

    return 0;
}