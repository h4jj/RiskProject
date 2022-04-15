#include "CommandProcessing.h"
#include "LogObserver.h"

string Command::stringToLog()
{
    return "Command effect: " + effect + ".\n";
}
void Command::Notify(ILoggable *c)
{
    LogObserver lo;
    lo.Update(c);
}
void Command::saveEffect(string eff)
{
    effect = eff;
    Notify(this);
}

CommandProcessing::CommandProcessing(const CommandProcessing &obj)
{
    this->commandColl = obj.commandColl;
}

CommandProcessing &CommandProcessing::operator=(const CommandProcessing &obj)
{
    this->commandColl = obj.commandColl;
    return *this;
}

string CommandProcessing::stringToLog()
{
    return "Command saved: " + commandColl.back()->command + ".\n";
}
void CommandProcessing::Notify(ILoggable *cp)
{
    LogObserver lo;
    lo.Update(cp);
}

void CommandProcessing::saveCommand(string word)
{
    Command *cmd = new Command(word);
    commandColl.push(cmd);
    std::cout << "Command: " << cmd->command << " saved" << std::endl;
    std::cout << "Command saved, length of collection is: " << commandColl.size() << std::endl;
    Notify(this);
}

void CommandProcessing::readCommand()
{
    string word;
    std::cout << "Input Command > ";
    std::getline(std::cin >> std::ws, word);
    word = tournamentMode(word);
    saveCommand(word);
}

string CommandProcessing::tournamentMode(string word)
{
    string tournamentMode[9];
    int index = 0;
    int parsing = 0;
    string delimiter = " -";
    while (parsing != -1)
    {
        switch (parsing)
        {
        case 0:
            tournamentMode[index] = word.substr(0, word.find(delimiter));
            if (tournamentMode[index].compare("tournament") != 0)
            {
                word = "invalid";
                std::cout << "input is invalid" << std::endl;
                parsing = -1;
                break;
            }
            word.erase(0, word.find(delimiter) + delimiter.length());
            parsing++;
            index++;
            break;
        case 1:
            tournamentMode[index] = word[0];
            if(tournamentMode[index] != "M"){
                word = "invalid";
                std::cout << "input invalid, should be -M instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 2:
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            string maps = tournamentMode[index];
            while(word.find(delimiter) == -1){
                if(maps.substr(0, maps.find(", ")).compare("canada.map") != 0
                || maps.substr(0, maps.find(", ")).compare("europe.map") != 0);
            }
            break;
        default:
            break;
        }
    }
    return word;
}
void CommandProcessing::getCommand()
{
    readCommand();
}

Command *CommandProcessing::popCommand()
{
    Command *cmd = commandColl.front();
    commandColl.pop();

    return cmd;
}

void CommandProcessing::validate(Command &cmd, State state)
{
    std::cout << "Current state is: MAP LOADED" << std::endl;
    switch (state)
    {
    case State::START:
    {
        if (cmd.command != "loadmap" || cmd.command != "tournament")
        {
            cmd.effect = "Error, cannot use this command in current state";
            break;
        }
        else
        {
            cmd.effect = "Command is valid, moving to next state";
            break;
        }
    }
    case State::MAP_LOADED:
    {
        if (cmd.command != "loadmap" || cmd.command != "tournament" || cmd.command != "validatemap")
        {
            cmd.effect = "Error, cannot use this command in current state";
            break;
        }
        else
        {
            cmd.effect = "Command is valid, moving to next state";
            break;
        }
    }
    case State::MAP_VALIDATED:
    {
        if (cmd.command != "addplayer")
        {
            cmd.effect = "Error, cannot use this command in current state";
            break;
        }
        else
        {
            cmd.effect = "Command is valid, moving to next state";
            break;
        }
    }
    case State::PLAYERS_ADDED:
    {
        if (cmd.command != "addplayer" && cmd.command != "gamestart")
        {
            cmd.effect = "Error, cannot use this command in current state";
            break;
        }
        else
        {
            cmd.effect = "Command is valid, moving to next state";
            break;
        }
    }
    case State::WIN:
    {
        if (cmd.command != "replay" && cmd.command != "quit")
        {
            cmd.effect = "Error, cannot use this command in current state";
            break;
        }
        else
        {
            cmd.effect = "Command is valid, moving to next state";
            break;
        }
    }
    default:
        cmd.effect = "State entered is not a valid state";
    }
}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(const FileCommandProcessorAdapter &obj) : CommandProcessing()
{
}

FileCommandProcessorAdapter &FileCommandProcessorAdapter::operator=(const FileCommandProcessorAdapter &obj)
{
    return *this;
}

string FileCommandProcessorAdapter::stringToLog()
{
    return "Command read from file: " + commandColl.back()->command + ".\n";
}
void FileCommandProcessorAdapter::Notify(ILoggable *fpa)
{
    LogObserver lo;
    lo.Update(fpa);
}

void FileCommandProcessorAdapter::readCommand()
{

    std::fstream file("commands.txt", std::ios::in);
    string word;

    file >> word;
    word = tournamentMode(word);
    saveCommand(word);
}
string FileCommandProcessorAdapter::tournamentMode(string word)
{
    string tournamentMode[9];
    std::stringstream ss(word);
    int i = 0;
    while (ss.good() && i < 9)
    {
        ss >> tournamentMode[i];
        i++;
    }
    return word;
}
void FileCommandProcessorAdapter::getCommand()
{
    readCommand();
}