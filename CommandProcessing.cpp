#include "CommandProcessing.h"
#include "LogObserver.h"

string Command::stringToLog(){
    return "Command effect: " + effect + ".\n";
}
void Command::Notify(ILoggable *c){
    LogObserver lo;
    lo.Update(c);
}
void Command::saveEffect(string eff) {
    effect = eff;
    Notify(this);
}

CommandProcessing::CommandProcessing(const CommandProcessing& obj) {
    this->commandColl = obj.commandColl;
}

CommandProcessing& CommandProcessing::operator=(const CommandProcessing& obj) {
    this->commandColl = obj.commandColl;
    return *this;
}

string CommandProcessing::stringToLog(){
    return "Command saved: " + commandColl.back()->command + ".\n"; 
}
void CommandProcessing::Notify(ILoggable *cp){
    LogObserver lo;
    lo.Update(cp);
}

void CommandProcessing::saveCommand(string word) {
    Command* cmd = new Command(word);
    commandColl.push(cmd);
    std::cout << "Command: " << cmd->command << " saved" << std::endl;
    std::cout << "Command saved, length of collection is: " << commandColl.size() << std::endl;
    Notify(this);
}

void CommandProcessing::readCommand() {
    string word;
    std::cout << "Input Command > ";
    std::getline(std::cin >> std::ws, word);
    
    saveCommand(word);
}

string CommandProcessing::tournamentMode(string word){
    string tournamentMode[9];
    std::stringstream ss(word);
    int i = 0;
    while(ss.good() && i < 9){
        ss >> tournamentMode[i];
        i++;
    }
    if(tournamentMode[0].compare("tournament") == 0 && i == 9
    && tournamentMode[1].compare("-M")){
        std::cout << "Tournament Mode activated" << std::endl;
    }
    //for(i = 0; i < 9; i++){
    //    std::cout << tournamentMode[i] << std::endl;
    //}
    return word;
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
    std::cout << "Current state is: MAP LOADED" <<std::endl;
    switch(state) {
        case State::START: {
            if(cmd.command != "loadmap" || cmd.command != "tournament") {
                cmd.effect = "Error, cannot use this command in current state";
                std::cout << "we here now" << std::endl;
                break;
            }
            else {
                cmd.effect = "Command is valid, moving to next state";
                break;
            }
        }
        case State::MAP_LOADED: {
            if(cmd.command != "loadmap" || cmd.command != "tournament" || cmd.command != "validatemap") {
                cmd.effect = "Error, cannot use this command in current state";
                break;
            }
            else {
                cmd.effect = "Command is valid, moving to next state";
                break;
            }
        }
        case State::MAP_VALIDATED: {
            if(cmd.command != "addplayer") {
                cmd.effect = "Error, cannot use this command in current state";
                break;
            }
            else {
                cmd.effect = "Command is valid, moving to next state";
                break;
            }
        }
        case State::PLAYERS_ADDED: {
            if(cmd.command != "addplayer" && cmd.command != "gamestart") {
                cmd.effect = "Error, cannot use this command in current state";
                break;
            }
            else {
                cmd.effect = "Command is valid, moving to next state";
                break;
            }
        }
        case State::WIN: {
            if(cmd.command != "replay" && cmd.command != "quit") {
                cmd.effect = "Error, cannot use this command in current state";
                break;
            }
            else {
                cmd.effect = "Command is valid, moving to next state";
                break;
            }
        }
        default: cmd.effect = "State entered is not a valid state";

    }
}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(const FileCommandProcessorAdapter& obj) : CommandProcessing() {

}

FileCommandProcessorAdapter& FileCommandProcessorAdapter::operator=(const FileCommandProcessorAdapter& obj) {
    return *this;
}

string FileCommandProcessorAdapter::stringToLog(){
    return "Command read from file: " + commandColl.back()->command + ".\n";
}
void FileCommandProcessorAdapter::Notify(ILoggable *fpa){
    LogObserver lo;
    lo.Update(fpa);
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