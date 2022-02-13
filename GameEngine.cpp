//create cases for each action to control the flow of the game. verify the input of the user. If input is unvalid, then break.
//For each state, it takes you to the next state, redo the state or both
// at the end the player will chose between restarting the game or ending it.
#include <iostream>
#include "GameEngine.h"

using namespace std;

GameEngine::GameEngine()
{
    state = "Start";
}

GameEngine::GameEngine(const GameEngine &other)
{
    state = other.state;
}

void GameEngine::setState(string newState)
{
    state = newState;
}

string GameEngine::getState()
{
    return state;
}

GameEngine &GameEngine::operator=(const GameEngine &other)
{
    state = other.state;
    return *this;
}

istream &operator>>(istream &in, GameEngine &g)
{
    in >> g.state;
    return in;
}

ostream &operator<<(ostream &out, const GameEngine &g)
{
    out << g.state << endl;
    return out;
}

void GameEngine::listOfActions(int i)
{
    string playerInput;
    switch (i)
    {
    case 0:

        cout << "################################################### \n";
        cout << "               WELCOME TO WARZONE!                  \n";
        cout << "################################################### \n";
        cout << "Enter \"loadmap\" to load the map" << endl;
        cin >> playerInput;
        if (playerInput == "loadmap")
        {
            setState("Map Loaded");
            cout << "You chose to load the map" << endl;
            cout << "The map is now loaded" << endl;

            return ++i;
        }
        else
        {
            cout << "Invalid input" << endl
                 << endl;
            return i;
        }
        break;
    case 1:
        cout << "Enter \"loadmap\" or \"validatemap\" to load or validate the map" << endl;
        cin >> playerInput;
        if (playerInput == "loadmap")
        {
            setState("Map Loaded");
            cout << "You chose to load the map" << endl;
            cout << "The map is now loaded" << endl;
            return i;
        }
        else if (playerInput == "validatemap")
        {
            setState("Map Validated");
            cout << "You chose to validate map" << endl;
            cout << "The map is now validated" << endl;
            return ++i;
        }
        else
        {
            cout << "Invalid input" << endl
                 << endl;
            return i;
        }
        break;
    case 2:
        cout << "Enter \"addplayer\" to add a player" << endl;
        cin >> playerInput;
        if (playerInput == "addplayer")
        {
            setState("Players Added");
            cout << "You chose to add a player" << endl;
            cout << "The player was added" << endl;

            return ++i;
        }
        else
        {
            cout << "Invalid input" << endl
                 << endl;
            return i;
        }
        break;
    case 3:
        cout << "Enter \"addplayer\" or \"assigncountries\" to add a player or assign reinforcement" << endl;
        cin >> playerInput;
        if (playerInput == "addplayer")
        {
            setState("Players Added");
            cout << "You chose to add a player" << endl;
            cout << "The player was added" << endl;
            return i;
        }
        else if (playerInput == "assigncountries")
        {
            setState("Assign Reinforcement");
            cout << "You chose to assign countries" << endl;
            cout << "Countries were assigned" << endl;
            return ++i;
        }
        else
        {
            cout << "Invalid input" << endl
                 << endl;
            return i;
        }
        break;
    case 4:
        cout << "Enter \"issueorder\" to issue an order" << endl;
        cin >> playerInput;
        if (playerInput == "issueorder")
        {
            setState("Issue Orders");
            cout << "You chose to issue an order" << endl;
            cout << "Order was issued" << endl;
            return ++i;
        }
        else
        {
            cout << "Invalid input" << endl
                 << endl;
            return i;
        }
        break;
    case 5:
        cout << "Enter \"issueorder\" or \"endissueorders\" to issue an order or end issuing orders" << endl;
        cin >> playerInput;
        if (playerInput == "issueorder")
        {
            setState("Issue Orders");
            cout << "You chose to issue an order" << endl;
            cout << "Order was issued" << endl;
            return i;
        }
        else if (playerInput == "endissueorders")
        {
            setState("Execute Orders");
            cout << "You chose to execute orders" << endl;
            cout << "Orders were executed " << endl;
            return ++i;
        }
        else
        {
            cout << "Invalid input" << endl
                 << endl;
            return i;
        }
        break;

    case 6:
        cout << "Enter \"execorder\" or \"endexecorders\" or \" \"win\" to execute order, assign reinforcement or to win" << endl;
        cin >> playerInput;
        if (playerInput == "execorder")
        {
            setState("Execute Orders");
            cout << "You chose to execute orders" << endl;
            cout << "Orders were executed " << endl;
            return i;
        }
        else if (playerInput == "endexecorders")
        {
            setState("Assign Reinforcement");
            cout << "You chose to assign countries" << endl;
            cout << "Countries were assigned" << endl;
            return 4;
        }
        else if (playerInput == "win")
        {
            setState("Win");
            cout << "You chose to win" << endl;
            cout << "You won" << endl;
            return ++i;
        }
        else
        {
            cout << "Invalid input" << endl
                 << endl;
            return i;
        }
        break;

    case 7:
        cout << "Enter \"play\" or \"end\" to play the game again or to end the game" << endl;
        cin >> playerInput;
        if (playerInput == "play")
        {
            setState("Start");
            cout << "You started the game" << endl;
            return (i = 0);
        }
        else if (playerInput == "end")
        {
            setState("End");
            cout << "You ended the game" << endl;
            return -1;
        }
        else
        {
            cout << "Invalid input" << endl
                 << endl;
            return i;
        }
        break;
    }
}