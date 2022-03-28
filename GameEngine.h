#pragma once
#include "Player.h"
#include "Map.h"
#include <random>

enum class State {START,MAP_LOADED,MAP_VALIDATED,PLAYERS_ADDED,ASSIGN_REIN,ISSUE_ORDERS,EXEC_ORDERS,WIN};
enum class Phase {STARTUP, PLAY};

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void startupPhase();
    void startupPhaseTest();
    void showMenu();
    void takeInput();
    void takeInputTest();
    void changeState();
    void showAvailableMaps();
    void pickMap();
    void mainGameLoop();
    void reinforcementPhase();
    void issueOrdersPhase();
    void executeOrdersPhase();
    GameEngine& operator=(const GameEngine&);
    GameEngine(const GameEngine&);
public:
    //modify copy constructor and assignment operator
    Phase phase = Phase::STARTUP;
    State state = State::START;
    Map* map = nullptr;
    std::vector<Player*> Players;
    Player* neutralPlayer;
};