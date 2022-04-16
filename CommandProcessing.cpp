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
    string* tournamentModeArray = new string[9];
    tournamentModeArray = tournamentMode(word, tournamentModeArray);
    for(int i = 0; i < 9; i++){
        std::cout << (tournamentModeArray[i]) << " ";
    }
    saveCommand(tournamentModeArray[0]);
}

string* CommandProcessing::tournamentMode(string word, string* tournamentMode)
{
    bool valid = true;
    bool finish = false;
    string initialWord = word;
    int index = 0;
    int parsing = 0;
    string maps;
    string delimiter = " -";
    string delimiter2 = ", ";
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
            if (tournamentMode[index] != "M")
            {
                word = "invalid";
                std::cout << "input invalid, should be -M instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 2:
            valid = true;
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            maps = tournamentMode[index];
            delimiter2 = ", ";
            while (!finish)
            {

                if (maps.substr(0, maps.find(delimiter2)).compare("canada.map") == 0 || maps.substr(0, maps.find(delimiter2)).compare("europe.map") == 0)
                {
                    maps.erase(0, maps.find(delimiter2) + delimiter2.length());
                    if (maps.find(delimiter2) == std::string::npos)
                    {
                        if (maps.compare("canada.map -") == 0 || maps.compare("europe.map -") == 0)
                        {
                            finish = true;
                            valid = true;
                        }
                        else
                        {
                            word = "invalid";
                            parsing = -1;
                            std::cout << "input invalid, the maps are not loaded" << std::endl;
                            valid = false;
                            finish = true;
                            break;
                        }
                    }
                    valid = true;
                }
                else if (maps.find(delimiter2) == std::string::npos)
                {
                    if (maps.compare("canada.map -") == 0 || maps.compare("europe.map -") == 0)
                    {
                        finish = true;
                        valid = true;
                    }
                    else
                    {
                        word = "invalid";
                        parsing = -1;
                        std::cout << "input invalid, the maps are not loaded" << std::endl;
                        valid = false;
                        finish = true;
                        break;
                    }
                }
                else
                {
                    std::cout << maps.substr(0, maps.find(delimiter2));
                    word = "invalid";
                    parsing = -1;
                    std::cout << "input invalid, the maps are not loaded" << std::endl;
                    valid = false;
                    break;
                }
                if (valid)
                {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                    finish = true;
                }
            }
            break;
        case 3:
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "P")
            {
                word = "invalid";
                std::cout << "input invalid, should be -P instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 4:
            finish = false;
            valid = true;
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            maps = tournamentMode[index];
            delimiter2 = ", ";
            while (!finish)
            {
                if (maps.substr(0, maps.find(delimiter2)).compare("Aggressive") == 0 || maps.substr(0, maps.find(delimiter2)).compare("Benevolant") == 0 || maps.substr(0, maps.find(delimiter2)).compare("Neutral") == 0 || maps.substr(0, maps.find(delimiter2)).compare("Cheater") == 0)
                {
                    maps.erase(0, maps.find(delimiter2) + delimiter2.length());
                    if (maps.find(delimiter2) == std::string::npos)
                    {
                        if (maps.compare("Aggressive -") == 0 || maps.compare("Benevolant -") == 0 || maps.compare("Neutral -") == 0 || maps.compare("Cheater -") == 0)
                        {
                            finish = true;
                            valid = true;
                        }
                        else
                        {
                            word = "invalid";
                            parsing = -1;
                            std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                            valid = false;
                            finish = true;
                            break;
                        }
                    }
                    valid = true;
                }
                else if (maps.find(delimiter2) == std::string::npos)
                {
                    if (maps.compare("Aggressive -") == 0 || maps.compare("Benevolant -") == 0 || maps.compare("Neutral -") == 0 || maps.compare("Cheater -") == 0)
                    {
                        finish = true;
                        valid = true;
                    }
                    else
                    {
                        word = "invalid";
                        parsing = -1;
                        std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                        valid = false;
                        finish = true;
                        break;
                    }
                }
                else
                {
                    std::cout << maps.substr(0, maps.find(delimiter2));
                    word = "invalid";
                    parsing = -1;
                    std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                    valid = false;
                    break;
                }
                if (valid)
                {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                    finish = true;
                }
            }
            break;
        case 5:
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "G")
            {
                word = "invalid";
                std::cout << "input invalid, should be -G instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 6:
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            try{
                if(stoi(tournamentMode[index]) < 1 || stoi(tournamentMode[index]) > 5){
                    std::cout << "Tournament mode requires minimum 1 game and maximum 5 games. You entered: " << tournamentMode[index] << std::endl;
                    word = "invalid";
                    parsing = -1;
                } else {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                }
            } catch (const std::invalid_argument& ia){
                std::cout << "You wrote: " << tournamentMode[index] << " instead of an integer between 1 and 5 inclusively" << std::endl;
                word = "invalid";
                parsing = -1;
            }
            break;
        case 7: 
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "D")
            {
                word = "invalid";
                std::cout << "input invalid, should be -D instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
            break;
        case 8:
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            try{
                if(stoi(tournamentMode[index]) < 10 || stoi(tournamentMode[index]) > 50){
                    std::cout << "Tournament mode requires minimum 10 turns and maximum 50 turns. You entered: " << tournamentMode[index] << std::endl;
                    word = "invalid";
                    parsing = -1;
                } else {
                    parsing++;
                }
            } catch (const std::invalid_argument& ia){
                std::cout << "You wrote: " << tournamentMode[index] << " instead of an integer between 10 and 50 inclusively" << std::endl;
                word = "invalid";
                parsing = -1;
            }
            break;
        default:
        if(parsing == 9){
            parsing = -1;

        } else {
            std::cout << "input invalid" << std::endl;
            word = "invalid";
        }
            break;
        }
    }
    return tournamentMode;
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
    string* tournamentModeArray = new string[9];
    tournamentModeArray = tournamentMode(word, tournamentModeArray);
    saveCommand(tournamentModeArray[0]);
}

string* FileCommandProcessorAdapter::tournamentMode(string word, string* tournamentMode)
{
    bool valid = true;
    bool finish = false;
    string initialWord = word;
    int index = 0;
    int parsing = 0;
    string maps;
    string delimiter = " -";
    string delimiter2 = ", ";
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
            if (tournamentMode[index] != "M")
            {
                word = "invalid";
                std::cout << "input invalid, should be -M instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 2:
            valid = true;
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            maps = tournamentMode[index];
            delimiter2 = ", ";
            while (!finish)
            {

                if (maps.substr(0, maps.find(delimiter2)).compare("canada.map") == 0 || maps.substr(0, maps.find(delimiter2)).compare("europe.map") == 0)
                {
                    maps.erase(0, maps.find(delimiter2) + delimiter2.length());
                    if (maps.find(delimiter2) == std::string::npos)
                    {
                        if (maps.compare("canada.map -") == 0 || maps.compare("europe.map -") == 0)
                        {
                            finish = true;
                            valid = true;
                        }
                        else
                        {
                            word = "invalid";
                            parsing = -1;
                            std::cout << "input invalid, the maps are not loaded" << std::endl;
                            valid = false;
                            finish = true;
                            break;
                        }
                    }
                    valid = true;
                }
                else if (maps.find(delimiter2) == std::string::npos)
                {
                    if (maps.compare("canada.map -") == 0 || maps.compare("europe.map -") == 0)
                    {
                        finish = true;
                        valid = true;
                    }
                    else
                    {
                        word = "invalid";
                        parsing = -1;
                        std::cout << "input invalid, the maps are not loaded" << std::endl;
                        valid = false;
                        finish = true;
                        break;
                    }
                }
                else
                {
                    std::cout << maps.substr(0, maps.find(delimiter2));
                    word = "invalid";
                    parsing = -1;
                    std::cout << "input invalid, the maps are not loaded" << std::endl;
                    valid = false;
                    break;
                }
                if (valid)
                {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                    finish = true;
                }
            }
            break;
        case 3:
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "P")
            {
                word = "invalid";
                std::cout << "input invalid, should be -P instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 4:
            finish = false;
            valid = true;
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            maps = tournamentMode[index];
            delimiter2 = ", ";
            while (!finish)
            {
                if (maps.substr(0, maps.find(delimiter2)).compare("Aggressive") == 0 || maps.substr(0, maps.find(delimiter2)).compare("Benevolant") == 0 || maps.substr(0, maps.find(delimiter2)).compare("Neutral") == 0 || maps.substr(0, maps.find(delimiter2)).compare("Cheater") == 0)
                {
                    maps.erase(0, maps.find(delimiter2) + delimiter2.length());
                    if (maps.find(delimiter2) == std::string::npos)
                    {
                        if (maps.compare("Aggressive -") == 0 || maps.compare("Benevolant -") == 0 || maps.compare("Neutral -") == 0 || maps.compare("Cheater -") == 0)
                        {
                            finish = true;
                            valid = true;
                        }
                        else
                        {
                            word = "invalid";
                            parsing = -1;
                            std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                            valid = false;
                            finish = true;
                            break;
                        }
                    }
                    valid = true;
                }
                else if (maps.find(delimiter2) == std::string::npos)
                {
                    if (maps.compare("Aggressive -") == 0 || maps.compare("Benevolant -") == 0 || maps.compare("Neutral -") == 0 || maps.compare("Cheater -") == 0)
                    {
                        finish = true;
                        valid = true;
                    }
                    else
                    {
                        word = "invalid";
                        parsing = -1;
                        std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                        valid = false;
                        finish = true;
                        break;
                    }
                }
                else
                {
                    std::cout << maps.substr(0, maps.find(delimiter2));
                    word = "invalid";
                    parsing = -1;
                    std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                    valid = false;
                    break;
                }
                if (valid)
                {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                    finish = true;
                }
            }
            break;
        case 5:
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "G")
            {
                word = "invalid";
                std::cout << "input invalid, should be -G instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 6:
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            try{
                if(stoi(tournamentMode[index]) < 1 || stoi(tournamentMode[index]) > 5){
                    std::cout << "Tournament mode requires minimum 1 game and maximum 5 games. You entered: " << tournamentMode[index] << std::endl;
                    word = "invalid";
                    parsing = -1;
                } else {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                }
            } catch (const std::invalid_argument& ia){
                std::cout << "You wrote: " << tournamentMode[index] << " instead of an integer between 1 and 5 inclusively" << std::endl;
                word = "invalid";
                parsing = -1;
            }
            break;
        case 7: 
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "D")
            {
                word = "invalid";
                std::cout << "input invalid, should be -D instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
            break;
        case 8:
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            try{
                if(stoi(tournamentMode[index]) < 10 || stoi(tournamentMode[index]) > 50){
                    std::cout << "Tournament mode requires minimum 10 turns and maximum 50 turns. You entered: " << tournamentMode[index] << std::endl;
                    word = "invalid";
                    parsing = -1;
                } else {
                    parsing++;
                }
            } catch (const std::invalid_argument& ia){
                std::cout << "You wrote: " << tournamentMode[index] << " instead of an integer between 10 and 50 inclusively" << std::endl;
                word = "invalid";
                parsing = -1;
            }
            break;
        default:
        if(parsing == 9){
            parsing = -1;

        } else {
            std::cout << "input invalid" << std::endl;
            word = "invalid";
        }
            break;
        }
    }
    return tournamentMode;
}

void FileCommandProcessorAdapter::getCommand()
{
    readCommand();
}