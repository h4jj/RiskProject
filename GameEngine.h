#pragma once
#include "Player.h"
#include "Map.h"
#include <random>
#include "LoggingObserver.h"
#include "CommandProcessing.h"

enum class Phase {STARTUP, PLAY};

class GameEngine : public ILoggable, public Subject{
public:
    GameEngine();
    ~GameEngine();
    void startupPhase();
    void showMenu();
    void takeInput();
    void changeState();
    void showAvailableMaps();
    void pickMap();
    void mainGameLoop();
    void reinforcementPhase();
    void issueOrdersPhase();
    void executeOrdersPhase();
    void transition();//Added to original work
    GameEngine& operator=(const GameEngine&);
    GameEngine(const GameEngine&);
    void Notify(ILoggable *) override;
    std::string stringToLog() override;
public:
    //modify copy constructor and assignment operator
    Phase phase = Phase::STARTUP;
    State state = State::START;
    Map* map = nullptr;
    std::vector<Player*> Players;
};