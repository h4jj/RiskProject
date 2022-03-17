#include "CommandProcessing.h"

void Command::saveEffect(string eff) {
    effect = eff;
}

void CommandProcessing::saveCommand(string word) {
    Command* cmd = new Command(word);
    commandColl.push(cmd);
    std::cout << "Command saved, length of collection is: " << commandColl.size() << std::endl;
}

void CommandProcessing::readCommand() {
    string word;
    std::cout << "Input Command > ";
    std::cin >> word;
    saveCommand(word);
}

void CommandProcessing::getCommand() {
    readCommand();
}

Command* CommandProcessing::popCommand() {
    Command* cmd = commandColl.front();
    commandColl.pop();

    return cmd;
}

void CommandProcessing::validate(Command& cmd, State state) {
    switch(state) {
        case State::START: {
            if(cmd.command != "loadmap") {
                cmd.effect = "Error, cannot use this command in current state";
                break;
            }
        }
        case State::MAP_LOADED: {
            if(cmd.command != "loadmap" || cmd.command != "validatemap") {
                cmd.effect = "Error, cannot use this command in current state";
                std::cout << "HERE";
                break;
            }
        }
        case State::MAP_VALIDATED: {
            if(cmd.command != "addplayer") {
                cmd.effect = "Error, cannot use this command in current state";
                break;
            }
        }
        case State::PLAYERS_ADDED: {
            if(cmd.command != "addplayer" || cmd.command != "gamestart") {
                cmd.effect = "Error, cannot use this command in current state";
                break;
            }
        }
        case State::WIN: {
            if(cmd.command != "replay" || cmd.command != "quit") {
                cmd.effect = "Error, cannot use this command in current state";
                break;
            }
        }
        default: cmd.effect = "State entered is not a valid state";

    }
}

void FileCommandProcessorAdapter::readCommand() {
    
    std::fstream file("commands.txt", std::ios::in);
    string word;
    
    file >> word;
    saveCommand(word);
}

void FileCommandProcessorAdapter::getCommand() {
    readCommand();
}