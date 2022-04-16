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
CommandProcessing::CommandProcessing(){
    tournamentModeArray = new string[9];
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
    tournamentModeArray = tournamentMode(word, tournamentModeArray);
    for(int i = 0; i < 9; i++){
        std::cout << (tournamentModeArray[i]) << " ";
    }
    saveCommand(tournamentModeArray[0]);
}

string* CommandProcessing::tournamentMode(string word, string* tournamentMode)
{
    int counter = 0;
    bool valid = true;
    bool finish = false;
    string initialWord = word;
    int index = 0;
    int parsing = 0;
    string maps;
    string strategy;
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
                tournamentMode[0] = "invalid";
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
                tournamentMode[0] = "invalid";
                std::cout << "input invalid, should be -M instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 2:
            counter = 0;
            valid = true;
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            maps = tournamentMode[index];
            delimiter2 = ", ";
            while (!finish)
            {

                if (maps.substr(0, maps.find(delimiter2)).compare("canada.map") == 0 || maps.substr(0, maps.find(delimiter2)).compare("europe.map") == 0)
                {
                    maps.erase(0, maps.find(delimiter2) + delimiter2.length());
                    counter++;
                    if (maps.find(delimiter2) == std::string::npos)
                    {
                        if (maps.compare("canada.map -") == 0 || maps.compare("europe.map -") == 0)
                        {
                            finish = true;
                            valid = true;
                            counter++;
                        }
                        else
                        {
                            tournamentMode[0] = "invalid";
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
                        counter++;
                    }
                    else
                    {
                        tournamentMode[0] = "invalid";
                        parsing = -1;
                        std::cout << "input invalid, the maps are not loaded" << std::endl;
                        valid = false;
                        finish = true;
                        break;
                    }
                }
                else
                {
                    tournamentMode[0] = "invalid";
                    parsing = -1;
                    std::cout << "input invalid, the maps are not loaded" << std::endl;
                    valid = false;
                    break;
                }
                if (valid && counter > 0 && counter < 6)
                {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                    finish = true;
                } else {
                    parsing = -1;
                    tournamentMode[0] = "invalid";
                }
            }
            break;
        case 3:
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "P")
            {
                tournamentMode[0] = "invalid";
                std::cout << "input invalid, should be -P instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 4:
            counter = 0;
            finish = false;
            valid = true;
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            strategy = tournamentMode[index];
            delimiter2 = ", ";
            while (!finish)
            {
                if (strategy.substr(0, strategy.find(delimiter2)).compare("Aggressive") == 0 || strategy.substr(0, strategy.find(delimiter2)).compare("Benevolant") == 0 || strategy.substr(0, strategy.find(delimiter2)).compare("Neutral") == 0 || strategy.substr(0, strategy.find(delimiter2)).compare("Cheater") == 0)
                {
                    strategy.erase(0, strategy.find(delimiter2) + delimiter2.length());
                    counter++;
                    if (strategy.find(delimiter2) == std::string::npos)
                    {
                        if (strategy.compare("Aggressive -") == 0 || strategy.compare("Benevolant -") == 0 || strategy.compare("Neutral -") == 0 || strategy.compare("Cheater -") == 0)
                        {
                            finish = true;
                            valid = true;
                            counter++;
                        }
                        else
                        {
                            tournamentMode[0] = "invalid";
                            parsing = -1;
                            std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                            valid = false;
                            finish = true;
                            break;
                        }
                    }
                    valid = true;
                }
                else if (strategy.find(delimiter2) == std::string::npos)
                {
                    if (strategy.compare("Aggressive -") == 0 || strategy.compare("Benevolant -") == 0 || strategy.compare("Neutral -") == 0 || strategy.compare("Cheater -") == 0)
                    {
                        finish = true;
                        valid = true;
                        counter++;
                    }
                    else
                    {
                        tournamentMode[0] = "invalid";
                        parsing = -1;
                        std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                        valid = false;
                        finish = true;
                        break;
                    }
                }
                else
                {
                    tournamentMode[0] = "invalid";
                    parsing = -1;
                    std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                    valid = false;
                    break;
                }
                if (valid && counter > 1 && counter < 5)
                {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                    finish = true;
                } else {
                    parsing = -1;
                    tournamentMode[0] = "invalid";
                }
            }
            break;
        case 5:
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "G")
            {
                tournamentMode[0] = "invalid";
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
                    tournamentMode[0] = "invalid";
                    parsing = -1;
                } else {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                }
            } catch (const std::invalid_argument& ia){
                std::cout << "You wrote: " << tournamentMode[index] << " instead of an integer between 1 and 5 inclusively" << std::endl;
                tournamentMode[0] = "invalid";
                parsing = -1;
            }
            break;
        case 7: 
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "D")
            {
                tournamentMode[0] = "invalid";
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
                    tournamentMode[0] = "invalid";
                    parsing = -1;
                } else {
                    parsing++;
                }
            } catch (const std::invalid_argument& ia){
                std::cout << "You wrote: " << tournamentMode[index] << " instead of an integer between 10 and 50 inclusively" << std::endl;
                tournamentMode[0] = "invalid";
                parsing = -1;
            }
            break;
        default:
        if(parsing == 9){
            parsing = -1;
            string m, p, g, d;
            std::ofstream file ("gamelog.txt", std::fstream::app);
            if(file.is_open()){
                m = "M: " + tournamentMode[2].substr(0, tournamentMode[2].find(" ")) + "\n";
                p = "P: " + tournamentMode[4].substr(0, tournamentMode[4].find(" ")) + "\n";
                g = "G: " + tournamentMode[6].substr(0, tournamentMode[6].find(" ")) + "\n";
                d = "D: " + tournamentMode[8].substr(0, tournamentMode[8].find(" ")) + "\n";
                file << "Tournament Mode\n";
                file << m;
                file << p;
                file << g;
                file << d;
            } else{
                std::cout << "Couldn't access file gamelog.txt" << std::endl;
            }
            file.close();
        } else {
            std::cout << "input invalid" << std::endl;
            tournamentMode[0] = "invalid";
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
FileCommandProcessorAdapter::FileCommandProcessorAdapter(){
    tournamentModeArray = new string[9];
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
    getline(file, word);
    string* tournamentModeArray = new string[9];
    tournamentModeArray = tournamentMode(word, tournamentModeArray);
    saveCommand(tournamentModeArray[0]);
}

string* FileCommandProcessorAdapter::tournamentMode(string word, string* tournamentMode)
{
    int counter = 0;
    bool valid = true;
    bool finish = false;
    string initialWord = word;
    int index = 0;
    int parsing = 0;
    string maps;
    string strategy;
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
                tournamentMode[0] = "invalid";
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
                tournamentMode[0] = "invalid";
                std::cout << "input invalid, should be -M instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 2:
            counter = 0;
            valid = true;
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            maps = tournamentMode[index];
            delimiter2 = ", ";
            while (!finish)
            {

                if (maps.substr(0, maps.find(delimiter2)).compare("canada.map") == 0 || maps.substr(0, maps.find(delimiter2)).compare("europe.map") == 0)
                {
                    maps.erase(0, maps.find(delimiter2) + delimiter2.length());
                    counter++;
                    if (maps.find(delimiter2) == std::string::npos)
                    {
                        if (maps.compare("canada.map -") == 0 || maps.compare("europe.map -") == 0)
                        {
                            finish = true;
                            valid = true;
                            counter++;
                        }
                        else
                        {
                            tournamentMode[0] = "invalid";
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
                        counter++;
                    }
                    else
                    {
                        tournamentMode[0] = "invalid";
                        parsing = -1;
                        std::cout << "input invalid, the maps are not loaded" << std::endl;
                        valid = false;
                        finish = true;
                        break;
                    }
                }
                else
                {
                    tournamentMode[0] = "invalid";
                    parsing = -1;
                    std::cout << "input invalid, the maps are not loaded" << std::endl;
                    valid = false;
                    break;
                }
                if (valid && counter > 0 && counter < 6)
                {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                    finish = true;
                } else {
                    parsing = -1;
                    tournamentMode[0] = "invalid";
                }
            }
            break;
        case 3:
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "P")
            {
                tournamentMode[0] = "invalid";
                std::cout << "input invalid, should be -P instead of -" << tournamentMode[index] << std::endl;
                parsing = -1;
            }
            index++;
            parsing++;
            break;
        case 4:
            counter = 0;
            finish = false;
            valid = true;
            tournamentMode[index] = word.substr(2, word.find(delimiter));
            strategy = tournamentMode[index];
            delimiter2 = ", ";
            while (!finish)
            {
                if (strategy.substr(0, strategy.find(delimiter2)).compare("Aggressive") == 0 || strategy.substr(0, strategy.find(delimiter2)).compare("Benevolant") == 0 || strategy.substr(0, strategy.find(delimiter2)).compare("Neutral") == 0 || strategy.substr(0, strategy.find(delimiter2)).compare("Cheater") == 0)
                {
                    strategy.erase(0, strategy.find(delimiter2) + delimiter2.length());
                    counter++;
                    if (strategy.find(delimiter2) == std::string::npos)
                    {
                        if (strategy.compare("Aggressive -") == 0 || strategy.compare("Benevolant -") == 0 || strategy.compare("Neutral -") == 0 || strategy.compare("Cheater -") == 0)
                        {
                            finish = true;
                            valid = true;
                            counter++;
                        }
                        else
                        {
                            tournamentMode[0] = "invalid";
                            parsing = -1;
                            std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                            valid = false;
                            finish = true;
                            break;
                        }
                    }
                    valid = true;
                }
                else if (strategy.find(delimiter2) == std::string::npos)
                {
                    if (strategy.compare("Aggressive -") == 0 || strategy.compare("Benevolant -") == 0 || strategy.compare("Neutral -") == 0 || strategy.compare("Cheater -") == 0)
                    {
                        finish = true;
                        valid = true;
                        counter++;
                    }
                    else
                    {
                        tournamentMode[0] = "invalid";
                        parsing = -1;
                        std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                        valid = false;
                        finish = true;
                        break;
                    }
                }
                else
                {
                    tournamentMode[0] = "invalid";
                    parsing = -1;
                    std::cout << "input invalid, " << tournamentMode[index] << " is not a player strategy" << std::endl;
                    valid = false;
                    break;
                }
                if (valid && counter > 1 && counter < 5)
                {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                    finish = true;
                } else {
                    parsing = -1;
                    tournamentMode[0] = "invalid";
                }
            }
            break;
        case 5:
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "G")
            {
                tournamentMode[0] = "invalid";
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
                    tournamentMode[0] = "invalid";
                    parsing = -1;
                } else {
                    parsing++;
                    index++;
                    word.erase(0, word.find(delimiter) + delimiter.length());
                }
            } catch (const std::invalid_argument& ia){
                std::cout << "You wrote: " << tournamentMode[index] << " instead of an integer between 1 and 5 inclusively" << std::endl;
                tournamentMode[0] = "invalid";
                parsing = -1;
            }
            break;
        case 7: 
            tournamentMode[index] = word[0];
            if (tournamentMode[index] != "D")
            {
                tournamentMode[0] = "invalid";
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
                    tournamentMode[0] = "invalid";
                    parsing = -1;
                } else {
                    parsing++;
                }
            } catch (const std::invalid_argument& ia){
                std::cout << "You wrote: " << tournamentMode[index] << " instead of an integer between 10 and 50 inclusively" << std::endl;
                tournamentMode[0] = "invalid";
                parsing = -1;
            }
            break;
        default:
        if(parsing == 9){
            parsing = -1;
            string m, p, g, d;
            std::ofstream file ("gamelog.txt", std::fstream::app);
            if(file.is_open()){
                m = "M: " + tournamentMode[2].substr(0, tournamentMode[2].find(" ")) + "\n";
                p = "P: " + tournamentMode[4].substr(0, tournamentMode[4].find(" ")) + "\n";
                g = "G: " + tournamentMode[6].substr(0, tournamentMode[6].find(" ")) + "\n";
                d = "D: " + tournamentMode[8].substr(0, tournamentMode[8].find(" ")) + "\n";
                file << "Tournament Mode\n";
                file << m;
                file << p;
                file << g;
                file << d;
            } else{
                std::cout << "Couldn't access file gamelog.txt" << std::endl;
            }
            file.close();
        } else {
            std::cout << "input invalid" << std::endl;
            tournamentMode[0] = "invalid";
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