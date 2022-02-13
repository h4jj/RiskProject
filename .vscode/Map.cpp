#include "Map.h"


Territory::Territory(std::string name) {
    country = name;
    std::cout << "Territory object created" << std::endl;
}

Territory::~Territory() {
    std::cout << "Territory object destroyed" << std::endl;
}