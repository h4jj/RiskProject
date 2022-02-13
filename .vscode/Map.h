#pragma once
#include <iostream>
#include <vector>


class Map {
public:
    std::vector<Territory*> Nodes;
    std::vector<Edge*> Edges;
};

class Territory {
public:
    Territory(std::string);
    ~Territory();

public:
    std::string continent;
    std::string country;
};

class Edge {
public:
    std::pair<Territory*, Territory*> AdjacencyEdges;

};

class MapLoader {

};