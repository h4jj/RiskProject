#include "Map.h"
#include "Map.cpp"

int main() {

    Map mapObject;
    Territory* country1 = new Territory("Lebanon");
    Territory* country2 = new Territory("Jordan");
    Territory* country3 = new Territory("Syria");

    Edge* edge1 = new Edge();
    edge1->AdjacencyEdges.first = country1;
    edge1->AdjacencyEdges.second = country2;

    mapObject.Nodes.push_back(country1);
    mapObject.Nodes.push_back(country2);
    mapObject.Nodes.push_back(country3);

    mapObject.Edges.push_back(edge1);

    return 0;
}