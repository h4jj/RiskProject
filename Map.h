#pragma once
#include <iostream>
#include <vector>
#include "Player.h"

class Territory {
public:
    Territory(std::string, std::string);
    ~Territory();
    void setContinent(std::string);
    void setCountry(std::string);
    std::string getContinent();
    std::string getCountry();

private:
    std::string* country, continent;
    Player* playerOwner;
    int armyNumber;
};

class Edge {
public:
    Edge();
    Edge(Territory*, Territory*);
    ~Edge();

public:
    std::pair<Territory*, Territory*>* AdjacencyEdges;
};

class Map {

public:
    Map();
    ~Map();
    bool validate();

public:
    std::vector<Territory*>* Nodes;
    std::vector<Edge*>* Edges;
};


class MapLoader {
public:
    void readMap(std::string);
public:
    Map* mapObject;

};