#include "LogObserver.h"

void LogObserver::Update(ILoggable *lo){
    std::string s = lo->stringToLog();
    std::ofstream file ("gamelog.txt");
    if(file.is_open()){
        file << s;
    } else{
        std::cout << "Couldn't access file gamelog.txt" << std::endl;
    }
    file.close();
}