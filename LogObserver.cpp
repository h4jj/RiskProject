#include "LogObserver.h"

LogObserver::LogObserver(){}

void LogObserver::Update(ILoggable *lo){
    std::cout << "in update" << std::endl;
    std::string s = lo->stringToLog();
    std::ofstream file ("gamelog.txt", std::fstream::app);
    if(file.is_open()){
        file << s;
        std::cout << "Hello" << std::endl;
    } else{
        std::cout << "Couldn't access file gamelog.txt" << std::endl;
    }
    file.close();
}