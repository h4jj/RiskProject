#pragma once
#include <string>

class ILoggable;

class ILoggable{
    public:
        virtual std::string stringToLog() = 0;
};

class Subject{
    public:
        virtual void Notify(ILoggable *) = 0;
};

class Observer{
    public:
        virtual void Update(ILoggable *) = 0;
};