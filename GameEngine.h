#pragma once
#include "Player.h"
#include "Map.h"

enum class State {START,MAP_LOADED,MAP_VALIDATED,PLAYERS_ADDED,ASSIGN_REIN,ISSUE_ORDERS,EXEC_ORDERS,WIN};

class GameEngine {
public:
    GameEngine(); 
    ~GameEngine();
    GameEngine(const GameEngine& g); //copy constructure
    GameEngine& operator = (const GameEngine& g);//assignment operator
    friend std::ostream& operator<<(std::ostream& stream, const GameEngine& g); //stream
     
    void start();
    void showMenu();
    void takeInput();
    void changeState();
    void showAvailableMaps();
    void pickMap();
public:
    State state = State::START;
    Map* map = nullptr;
    Player *p1=nullptr,*p2 = nullptr, *p3 = nullptr;
};
