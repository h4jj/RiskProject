#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include "Player.h"

class Territory {
public:
    Territory(std::string, std::string, Player*, int);
    Territory(std::string, std::string);
    ~Territory();
    void setContinent(std::string);
    void setCountry(std::string);
    std::string getContinent();
    std::string getCountry();
    Player* getTerritoryOwner();
    int* getArmyCount();
    static int id;
    int getID();
    Territory(const Territory& t);
    Territory& operator =(const Territory& t);
    friend ostream &operator<<(ostream &out, Territory& t);
private:
    int terr_id;
    std::string country, continent;
    Player* territoryOwner;
    int* armyCount;
};

class Edge {
public:
    Edge(Territory*, Territory*);
    ~Edge();
    Edge(const Edge& e);
    Edge& operator =(const Edge& e);

public:
    std::pair<Territory*, Territory*> AdjacencyEdges;
};

class Map {

public:
    Map();
    ~Map();
    bool validate();
    Map(const Map& m);
    Map& operator =(const Map& m);

public:
    std::vector<Territory*> Nodes; // Nodes is a pointer similar to how an array gives a pointer to the first element - Assigning a pointer value will result in **
    std::vector<Edge*> Edges; // Edges is a pointer similar to how an array gives a pointer to the first element - Assigning a pointer value will result in **
};


class MapLoader {
public:
    Map* readMap(std::string filepath);
    MapLoader(const MapLoader& ml);
    MapLoader& operator =(const MapLoader& ml);
};