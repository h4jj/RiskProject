#pragma once

#include <fstream>
#include <iostream>
#include <queue>
#include "LoggingObserver.h"
#include <string>
#include <sstream>

using std::queue;
using std::string;

enum class StateCommand {START,MAP_LOADED,MAP_VALIDATED,PLAYERS_ADDED,ASSIGN_REIN,ISSUE_ORDERS,EXEC_ORDERS,WIN};

class Command : public Subject, public ILoggable {
public:
    Command();
    Command(string cmd) : command(cmd) {}; 
    string command, effect;
    void saveEffect(string);
    string stringToLog() override;
    void Notify(ILoggable *) override;
};

class CommandProcessing : public Subject, public ILoggable {
public:
    CommandProcessing();//Modified
    ~CommandProcessing() {};
    CommandProcessing(const CommandProcessing&);
    CommandProcessing& operator=(const CommandProcessing&);
    virtual void getCommand();
    void validate(Command&, StateCommand);
    Command* popCommand();
    string* returnTournamentPara();
    string stringToLog() override;
    void Notify(ILoggable *) override;
protected:
    virtual void readCommand();
    void saveCommand(string);
    queue<Command*> commandColl;
private:
    string* tournamentModeArray;
    virtual string* tournamentMode(string, string*);
    string* tournamentPara;
};

class FileCommandProcessorAdapter : public CommandProcessing{
public:
    FileCommandProcessorAdapter();//Modified
    ~FileCommandProcessorAdapter() {};
    FileCommandProcessorAdapter(const FileCommandProcessorAdapter&);
    FileCommandProcessorAdapter& operator=(const FileCommandProcessorAdapter&);
    virtual void getCommand();
    string* returnTournamentPara();
    string stringToLog() override;
    void Notify(ILoggable *) override;
private:
    virtual string* tournamentMode(string, string*);
    virtual void readCommand();
    string* tournamentModeArray;
    string* tournamentPara;
};