#pragma once
#include <iostream>

class GameEngine
{

public:
<<<<<<< HEAD
    GameEngine(); // constructor
    void start();
};

enum class STATE {START, MAP_LOADED, MAP_VALIDATED, PLAYERS_ADDED, ASSIGN_REINF, ISSUE_ORDERS, EXECUTE_ORDERS, WIN};

=======
    GameEngine();                        // constructor
    GameEngine(const GameEngine &other); //constructor
    ~GameEngine();                       // destructor
    void setState(string newState);      //setter
    string getState();                   //gett
    int listOfActions(int i);
    friend ostream &operator<<(ostream &out, const GameEngine &g);
    friend istream &operator>>(istream &in, GameEngine &g);
};
>>>>>>> 533d5ec864ba8d5c3745c17721d338d27e11ef91
