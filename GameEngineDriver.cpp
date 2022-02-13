#include "GameEngine.h"

int main()
{
    //set the current state to 0 to start the game
    int currentState = 0;
    int newState = 0;

    GameEngine game;

    do
    {
        newState = game.listOfActions(currentState);
        currentState = newState;

    } while (currentState != -1);

    return 0;
}