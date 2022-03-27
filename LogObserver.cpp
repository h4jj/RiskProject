#include "LogObserver.h"

LogObserver::LogObserver(){}

LogObserver::LogObserver(LogObserver &lo){
    //No need for an implementation since lo is holding nothing
}

std::ostream& operator<<(std::ostream &out, const LogObserver *lo){
    out << "This is the assignment operator for LogObserver.\n";
    return out;    
}

LogObserver& LogObserver::operator= (const LogObserver &lo){
    //There is no copies to be made since LogObserver holds no values
    return *this;
}

void LogObserver::Update(ILoggable *lo){
    std::cout << "in Update(ILoggable *);" << std::endl;
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