#include "Map.h"


Territory::Territory(std::string _country, std::string _continent, Player* player, int _armyCount) {
    country = _country;
    continent = _continent;
    territoryOwner = player;
    armyCount = &_armyCount;

    terr_id = id;
    id++;

    std::cout << "Territory object created having ID: " << terr_id << std::endl;
}

Territory::~Territory() {
    std::cout << "territoryOwner and Territory object destroyed, rest was used for stack allocation" << std::endl;
}

int Territory::id = 0;

Edge::Edge(Territory* ptr1, Territory* ptr2) {
    this->AdjacencyEdges.first = ptr1;
    this->AdjacencyEdges.second = ptr2;
    std::cout << "Edge object created linking " << ptr1->getCountry() << " and " << ptr2->getCountry() << std::endl;
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

bool Map::validate() {

    // 1 - Check map is a connected graph

    bool unvisitedNodes[this->Nodes.size()];

    for(int i{0}; i<this->Nodes.size(); i++) {
        unvisitedNodes[i] = false;
    }

    unvisitedNodes[0] = true;

    for(Territory* territory : this->Nodes) {

        for(Edge* edge : this->Edges) {
            if(edge->AdjacencyEdges.first == territory) {
                int id = edge->AdjacencyEdges.second->getID();
                if(unvisitedNodes[id] == false) {
                    unvisitedNodes[id] = true;
                }
            }
        }
    }

    for(int i{0}; i<this->Nodes.size(); i++) {
        if(unvisitedNodes[i] == false) {
            std::cout << "FALSE" << std::endl;
            return false;
        }
    }

    std::cout << "TRUE" << std::endl;
    return true;

    // 2 - Check continents are connected subgraphs

    // if graph is connected then all continents are connected


    // 3 - Each country belongs to one and only one continent

    // since there is only one possible continent value for each territory then each country cannot belong to more than one continent
    
}

Map* MapLoader::readMap(std::string filepath) {
    
}

void Territory::setContinent(std::string _continent) {continent = _continent;}
void Territory::setCountry(std::string _country) {country = _country;}
std::string Territory::getContinent() {return continent;}
std::string Territory::getCountry() {return country;}
Player* Territory::getTerritoryOwner() {return territoryOwner;}
int* Territory::getArmyCount() {return armyCount;}
int Territory::getID() {return terr_id;}