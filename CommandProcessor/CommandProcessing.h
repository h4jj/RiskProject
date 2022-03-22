#pragma once

#include <fstream>
#include <iostream>
#include <queue>
#include "LoggingObserver.h"

using std::queue;
using std::string;

enum class State {START,MAP_LOADED,MAP_VALIDATED,PLAYERS_ADDED,ASSIGN_REIN,ISSUE_ORDERS,EXEC_ORDERS,WIN};

class Command : public ILoggable, public Subject{
public:
    Command();
    Command(string cmd) : command(cmd) {}; 
    string command, effect;
    void saveEffect(string); 
    void Notify(ILoggable *) override;
    string stringToLog() override;   
};

class CommandProcessing : public ILoggable, public Subject{
public:
    virtual void getCommand();
    void validate(Command&, State);
    Command* popCommand();
    void Notify(ILoggable *) override;
    string stringToLog() override;
protected:
    virtual void readCommand();
    void saveCommand(string);
    queue<Command*> commandColl;
};

class FileCommandProcessorAdapter : public CommandProcessing{
public:
    virtual void getCommand();
private:
    virtual void readCommand();
};