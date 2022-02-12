#include "GameEngine.h"
#include <iostream>
using namespace std;

void GameEngine::start()
{

    cout << "################################################### \n";
    cout << "               WELCOME TO WARZONE!                  \n";
    cout << "################################################### \n";
    loadMap();
    validateMap();
    addPlayers();

    cin >> this->NumberOfPlayers;

    void GameEngine::loadMap()
    {
        cout << "Enter the name of the map file you want to load" << endl;
    }
    void GameEngine::validateMap() {}
    void GameEngine::addPlayers() {}
    void GameEngine::assignReinforcement() {}
    void GameEngine::issueOrders() {}
    void GameEngine::executeOrders() {}
}