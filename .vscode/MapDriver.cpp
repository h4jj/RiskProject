#include "Map.h"

int main() {

    Map mapObject;
    Territory* country1 = new Territory("Lebanon");
    Territory* country2 = new Territory("Jordan");
    Territory* country3 = new Territory("Syria");

    mapObject.Nodes.push_back(country1);
    mapObject.Nodes.push_back(country2);
    mapObject.Nodes.push_back(country3);

    return 0;
}