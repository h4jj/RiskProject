#include "Map.cpp"
#include "Player.cpp"
#include "Orders.cpp"

int main() {
    
    MapLoader maploader;
    Map* map1 = nullptr;

    map1 = maploader.readMap("../Maps/canada.map");

    std::cout << "Size of nodes: " << map1->Nodes.size() << std::endl;
    std::cout << "Size of edges: " << map1->Edges.size() << std::endl;
    
    map1->validate();

    Map* map2 = nullptr;
    map2 = maploader.readMap("canada.txt");
    
    Map* map3 = nullptr;
    map3 = maploader.readMap("../Maps/incorrectformat.map");

    return 0;
}