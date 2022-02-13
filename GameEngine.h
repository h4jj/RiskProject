#pragma once
#include <iostream>

class GameEngine
{

public:
    GameEngine(); // constructor
    void start();
};

enum class STATE {START, MAP_LOADED, MAP_VALIDATED, PLAYERS_ADDED, ASSIGN_REINF, ISSUE_ORDERS, EXECUTE_ORDERS, WIN};

