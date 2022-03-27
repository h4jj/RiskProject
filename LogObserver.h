#pragma once
#include "LoggingObserver.h"
#include <string>
#include <fstream>
#include <iostream>

class LogObserver : public Observer{
    public:
        LogObserver();
        LogObserver(LogObserver&);
        void Update(ILoggable *) override;
        friend std::ostream& operator<<(std::ostream &, const LogObserver *);
        LogObserver& operator= (const LogObserver &);
};