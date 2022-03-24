#pragma once
#include "LoggingObserver.h"
#include <string>
#include <fstream>
#include <iostream>

class LogObserver : public Observer{
    public:
        LogObserver();
        void Update(ILoggable *) override;
};