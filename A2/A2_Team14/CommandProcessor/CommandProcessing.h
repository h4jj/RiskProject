#pragma once

#include <fstream>
#include <iostream>
#include <queue>

using std::queue;
using std::string;

enum class State {START,MAP_LOADED,MAP_VALIDATED,PLAYERS_ADDED,ASSIGN_REIN,ISSUE_ORDERS,EXEC_ORDERS,WIN};

class Command {
public:
    Command();
    Command(string cmd) : command(cmd) {}; 
    string command, effect;
    void saveEffect(string);    
};

class CommandProcessing {
public:
    CommandProcessing() = default;
    ~CommandProcessing() {};
    CommandProcessing(const CommandProcessing&);
    CommandProcessing& operator=(const CommandProcessing&);
    virtual void getCommand();
    void validate(Command&, State);
    Command* popCommand();
protected:
    virtual void readCommand();
    void saveCommand(string);
    queue<Command*> commandColl;
};

class FileCommandProcessorAdapter : public CommandProcessing{
public:
    FileCommandProcessorAdapter() = default;
    ~FileCommandProcessorAdapter() {};
    FileCommandProcessorAdapter(const FileCommandProcessorAdapter&);
    FileCommandProcessorAdapter& operator=(const FileCommandProcessorAdapter&);
    virtual void getCommand();
private:
    virtual void readCommand();
};