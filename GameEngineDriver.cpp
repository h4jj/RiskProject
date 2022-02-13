#include "GameEngine.h"
#include "GameEngine.cpp"


int main()
<<<<<<< HEAD
{   
    GameEngine gameEngineObject;
    STATE x;

    while(true) {
        
        x = STATE::START;

        switch(x){
            case STATE::START:
            {
                gameEngineObject.start();
                break;
            }
            default: std::cout << "Invalid Command" << std::endl;
        } 
        break;
    }
=======
{
    //set the current and new state to 0 to start the game
    int currentState = 0;
    int newState = 0;

    GameEngine game;

    do
    {
        newState = game.listOfActions(currentState);
        currentState = newState;

    } while (currentState != -1);
>>>>>>> 533d5ec864ba8d5c3745c17721d338d27e11ef91

    return 0;
}