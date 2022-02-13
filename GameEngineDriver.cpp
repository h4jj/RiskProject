#include "GameEngine.h"
#include "GameEngine.cpp"


int main()
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

    return 0;
}