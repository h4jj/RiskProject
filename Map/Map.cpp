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

Territory::Territory(const Territory& t) {
    this->terr_id = t.terr_id;
    this->country = t.country;
    this->continent = t.continent;
    this->armyCount = new int(*(t.armyCount));
    this->territoryOwner = new Player(*(t.territoryOwner->name));
}

Territory& Territory::operator=(const Territory& t) {
    this->terr_id = t.terr_id;
    this->country = t.country;
    this->continent = t.continent;
    this->armyCount = t.armyCount;
    this->territoryOwner = t.territoryOwner;
    return *this;
}

Territory::Territory(std::string _country, std::string _continent) {
    country = _country;
    continent = _continent;

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

Edge::Edge(const Edge& e) {
    this->AdjacencyEdges.first = new Territory(e.AdjacencyEdges.first->getCountry(), e.AdjacencyEdges.first->getContinent());
    this->AdjacencyEdges.second = new Territory(e.AdjacencyEdges.second->getCountry(), e.AdjacencyEdges.second->getContinent());
}

Edge& Edge::operator=(const Edge& e) {
    this->AdjacencyEdges.first = e.AdjacencyEdges.first;
    this->AdjacencyEdges.second = e.AdjacencyEdges.second;
    return *this;
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
        std::cout << unvisitedNodes[i] << " ";
        if(unvisitedNodes[i] == false) {
            std::cout << "FALSE" << std::endl;
            return false;
        }
    }

    std::cout << "Graph is connected: TRUE" << std::endl;
    return true;

    // 2 - Check continents are connected subgraphs

    // if graph is connected then all continents are connected


    // 3 - Each country belongs to one and only one continent

    // since there is only one possible continent value for each territory then each country cannot belong to more than one continent
    
}


Map::Map(const Map& m) {
    for(auto const& item : m.Nodes) {
        Territory* t = new Territory(item->getCountry(), item->getContinent());
        this->Nodes.push_back(t);
    }

    for(auto const& item : m.Edges) {
        Edge* e = new Edge(new Territory(item->AdjacencyEdges.first->getCountry(), item->AdjacencyEdges.first->getContinent()), new Territory(item->AdjacencyEdges.second->getCountry(), item->AdjacencyEdges.second->getContinent()));
        this->Edges.push_back(e);
    }
}

Map& Map::operator=(const Map& m) {
    for(auto const& item : m.Nodes) {
        this->Nodes.push_back(item);
    }

    for(auto const& item : m.Edges) {
        this->Edges.push_back(item);
    }

    return *this;
}

Map* MapLoader::readMap(std::string filepath) {

    // 1 - create map data structure of continents

    std::map<int, std::string> Continents;
    int continentCounter = 1;
    Map* mapObject = new Map();
    std::string line;
    std::string continent;
    std::vector<Edge*> tempVect;
    std::ifstream stream(filepath);
    bool foundContinent = false, foundCountry = false, foundBorders = false;

    if(!stream) {
        std::cout << "File does not exist" << std::endl;
        return nullptr;
    }
    else {
        std::cout << "File is valid" << std::endl;
    }
    

    while(getline(stream,line)) {
        if(line.find("[continents]") != std::string::npos) {
            foundContinent = true;
            continue;
        }

        if(foundContinent) {
            if(line.empty()) {
                break;
            }

            std::stringstream ss(line);
            ss >> continent;
            Continents.insert(std::pair<int,std::string>(continentCounter, continent));
            continentCounter++;
        }
    }

    if(!foundContinent) {
        std::cout << "File has invalid format - Unable to continue - returning nullptr" << std::endl;
        return nullptr;
    }

    // 2 - link each country to a continent and create Territory objects

    while(getline(stream,line)) {
        if(line.find("[countries]") != std::string::npos) {
            foundCountry = true;
            continue;
        }
        if(foundCountry) {

            if(line.empty()) {
                break;
            }

            int placeholder, continentTracker;
            std::string country;
            std::stringstream ss(line) ;
            ss >> placeholder >> country >> continentTracker;
            for(auto const& x : Continents) {
                if(x.first == continentTracker) {
                    Territory* t = new Territory(country, x.second);
                    mapObject->Nodes.push_back(t);
                    break;
                }
            }
            
        }
    }

    if(!foundCountry) {
        std::cout << "File has invalid format - Unable to continue - returning nullptr" << std::endl;
        return nullptr;
    }

    // 3 - connect the edges

    int countrySlot = 0, tempCounter = 0;

    while(getline(stream,line)) {
        if(line.find("[borders]") != std::string::npos) {
            foundBorders = true;
            continue;
        }

        if(foundBorders) {

            if(line.empty()) {
                break;
            }

            std::string var;
            bool initialSlot = true;
            std::stringstream ss(line);
            while(getline(ss,var, ' ')) {

                bool pushBack = true;

                if(initialSlot) {
                    initialSlot = false;
                    continue;
                }
                Edge* e = new Edge(mapObject->Nodes.at(countrySlot), mapObject->Nodes.at(stoi(var)-1));
 
                for(auto& x : tempVect) {
                    if(e->AdjacencyEdges.first->getCountry() == x->AdjacencyEdges.first->getCountry() || e->AdjacencyEdges.first->getCountry() == x->AdjacencyEdges.second->getCountry()) {
                        if(e->AdjacencyEdges.second->getCountry() == x->AdjacencyEdges.first->getCountry() || e->AdjacencyEdges.second->getCountry() == x->AdjacencyEdges.second->getCountry()) {
                            pushBack = false;
                            break;
                        }
                    }
                }

                if(pushBack) {
                    tempVect.push_back(e);
                    mapObject->Edges.push_back(e);
                }
            }
            countrySlot++;
            
        }
    }

    if(!foundBorders) {
        std::cout << "File has invalid format - Unable to continue - returning nullptr" << std::endl;
        return nullptr;
    }
    
    return mapObject;
}

void Territory::setContinent(std::string _continent) {continent = _continent;}
void Territory::setCountry(std::string _country) {country = _country;}
std::string Territory::getContinent() {return continent;}
std::string Territory::getCountry() {return country;}
Player* Territory::getTerritoryOwner() {return territoryOwner;}
int* Territory::getArmyCount() {return armyCount;}
int Territory::getID() {return terr_id;}