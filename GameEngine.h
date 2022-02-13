#include <iostream>
using namespace std;

class GameEngine
{

public:
    GameEngine();                        // constructor
    GameEngine(const GameEngine &other); //constructor
    ~GameEngine();                       // destructor
    void setState(string newState);      //setter
    string getState();                   //gett
    int listOfActions(int i);
    friend ostream &operator<<(ostream &out, const GameEngine &g);
    friend istream &operator>>(istream &in, GameEngine &g);
};
