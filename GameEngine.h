#include <iostream>
using namespace std;

class GameEngine
{

public:
    GameEngine(const GameEngine &game); // constructor
    ~GameEngine();                      // destructor
    GameEngine &operator=(const GameEngine &);

    friend ostream &operator<<(ostream &out, const GameEngine &g);
    friend istream &operator>>(istream &in, GameEngine &g);

    void start();
    void loadMap();
    void validateMap();
    void addPlayers();
    void assignReinforcement();
    void issueOrders();
    void executeOrders();
};

private:
enum states
{
    start,
    mapLoaded,
    mapValidated,
    playersAdded,
    assignReinforcement,
    issueOrders,
    executeOrders,
    win
};
