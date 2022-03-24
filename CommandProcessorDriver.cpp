#include "CommandProcessing.h"
#include "CommandProcessing.cpp"
#include "LogObserver.cpp"

int main() {

    while(true) {
        string word;
        std::cout << "Commands are: 1) console\n"
                    "              2) file   \n"
                    "              3) quit   \n";
        std::cout << "Input command > ";
        std::cin >> word;

        if(word == "console") {
            CommandProcessing object;
            object.getCommand();
            Command* cmd = object.popCommand();
            object.validate(*cmd, State::MAP_LOADED);
            std::cout << "Command Effect: " << cmd->effect << std::endl;
        }
        else if(word == "file") {
            FileCommandProcessorAdapter obj;
            obj.getCommand();
            Command* cmd = obj.popCommand();
            obj.validate(*cmd, State::MAP_LOADED);
            std::cout << "Command Effect: " << cmd->effect << std::endl;
        }
        else if(word == "quit") {
            break;
        }
        else {
            std::cout << "Incorrect input please try again." << std::endl << std::endl;
        }
    }


    return 0;
}