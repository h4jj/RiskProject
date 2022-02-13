#pragma once
#include <iostream>
#include <vector>

class Territory {
public:
    Territory(std::string, std::string);
    ~Territory();
    void setContinent(std::string);
    void setCountry(std::string);
    std::string getContinent();
    std::string getCountry();

private:
    char* continent;
    char* country;
};

class Edge {
public:
    Edge(Territory*, Territory*);
    ~Edge();

public:
    std::pair<Territory*, Territory*>* AdjacencyEdges;
};

class Map {

public:
    Map();
    ~Map();

public:
    std::vector<Territory*> Nodes;
    std::vector<Edge*> Edges;
};


class MapLoader {
public:
    void readMap(std::string);
public:
    Map* mapObject;

};