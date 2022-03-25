#include "GameEngine.cpp"
#include "CommandProcessing.cpp"
#include "Player.h"
#include "LogObserver.cpp"

int main(){
    std::string s;
    std::cout << "Enter Game Engine? >";
    std::cin >> s;
    if(s.compare("yes") == 0){
        std::cout << "***********************" << std::endl;
        std::cout << "***   GAME ENGINE   ***" << std::endl;
        std::cout << "***********************" << std::endl;
        GameEngine *gameEng = new GameEngine();
        gameEng->startupPhase();//Starts the Game engine
        return 0;
    }

    std::cout << "Enter Command Processor? >";
    std::cin >> s;
    if(s.compare("yes") == 0){
        std::cout << "*****************************" << std::endl;
        std::cout << "***   COMMAND PROCESSOR   ***" << std::endl;
        std::cout << "*****************************" << std::endl;
        while(true) {
        string word;
        std::cout << "Commands are: 1) console\n"
                    "              2) file   \n"
                    "              3) quit   \n";
        std::cout << "Input command > ";
        std::cin >> word;

        if(word == "console") {//takes in commands on the console
            CommandProcessing object;
            object.getCommand();
            Command* cmd = object.popCommand();
            object.validate(*cmd, State::MAP_LOADED);
            std::cout << "Command Effect: " << cmd->effect << std::endl;
        }
        else if(word == "file") {//takes in commands from the commands.txt file
            FileCommandProcessorAdapter obj;
            obj.getCommand();
            Command* cmd = obj.popCommand();
            obj.validate(*cmd, State::MAP_LOADED);
            std::cout << "Command Effect: " << cmd->effect << std::endl;
        }
        else if(word == "quit") {//quits the command processor
            break;
        }
        else {
            std::cout << "Incorrect input please try again." << std::endl << std::endl;
        }
    }
        return 0;
    }

    std::cout << "Enter Orders? >";
    std::cin >> s;
    if(s.compare("yes") == 0){
        std::cout << "******************" << std::endl;
        std::cout << "***   ORDERS   ***" << std::endl;
        std::cout << "******************" << std::endl;
        MapLoader *ml = new MapLoader();
        ml->readMap("canada.map");
        Player* p1 = new Player("Ahmad");
        Player* p2 = new Player("Mostafa");
        Player* p3 = new Player("Marieme");
        p1->issueOrder(1);//Puts order with orderType from 1 to 6 in the orderList (and in the gameLog.txt file)
        p1->issueOrder(2);
        p1->issueOrder(3);
        p1->issueOrder(4);
        p1->issueOrder(5);
        p1->issueOrder(6);
        Deploy *d = new Deploy(nullptr, 1);
        d->execute();//Execute a deploy command
        // Order *a = new Advance(nullptr, 2);
        // a->execute();//Execute a advance command
        // Order *bl = new Blockade(nullptr, 3);
        // bl->execute();//Execute a blockade command
        // Order *b = new Bomb(nullptr, 4);
        // b->execute();//Execute a bomb command
        // Order *al = new Airlift(nullptr, 5);
        // al->execute();//Execute a airlift command
        // Order *n = new Negotiate(nullptr, 6);
        // n->execute();//Execute a negotiate command
        return 0;
    }
}