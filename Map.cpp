#include "Map.h"


Territory::Territory(std::string* _country, std::string* _continent) {
    country = _country;
    continent = _continent;
    std::cout << "Territory object created" << std::endl;
}

Territory::~Territory() {
    std::cout << "Territory object destroyed" << std::endl;
}

Edge::Edge(Territory* ptr1, Territory* ptr2) {
    this->AdjacencyEdges->first = ptr1;
    this->AdjacencyEdges->second = ptr2;
    std::cout << "Edge object successfully created" << std::endl;
}

Edge::Edge() {

}

Edge::~Edge() {
    std::cout << "Edge object successfully destroyed" << std::endl;
}

Map::Map() {
    std::cout << "Map object created" << std::endl;
}

Map::~Map() {
    std::cout << "Map object destroyed" << std::endl;
}

void Territory::setContinent(std::string* _continent) {continent = _continent;}
void Territory::setCountry(std::string* _country) {country = _country;}
std::string* Territory::getContinent() {return continent;}
std::string* Territory::getCountry() {return country;}
