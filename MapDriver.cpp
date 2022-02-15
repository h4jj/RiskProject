#include "Map.cpp"
#include "Player.cpp"
#include "Orders.cpp"

int main() {

    // Map* mapObject = new Map();

    // Player* Ahmad = new Player();
    // Player* Mostafa = new Player();
    // Player* Marieme = new Player();

    // Territory* t1 =  new Territory("Lebanon", "Asia", Ahmad, 100);
    // Territory* t2 =  new Territory("Syria", "Asia", Ahmad, 100);
    // Territory* t3 =  new Territory("Palestine", "Asia", Ahmad, 100);
    // Territory* t4 =  new Territory("Jordan", "Asia", Mostafa, 100);
    // // Territory* t5 =  new Territory("Iran", "Asia", Mostafa, 100);
    // // Territory* t6 =  new Territory("Iraq", "Asia", Mostafa, 100);
    // // Territory* t7 =  new Territory("China", "Asia", Mostafa, 100);
    // // Territory* t8 =  new Territory("Pakistan", "Asia", Mostafa, 100);
    // // Territory* t9 =  new Territory("Malaysia", "Asia", Marieme, 100);
    // // Territory* t10 =  new Territory("Vietnam", "Asia", Marieme, 100);
    // // Territory* t11 =  new Territory("Saudi Arabia", "Asia", Marieme, 100);

    // Edge* e1 = new Edge(t1,t2);
    // Edge* e2 = new Edge(t1,t3);
    // Edge* e3 = new Edge(t2,t4);
    // Edge* e4 = new Edge(t3,t4);
    // // Edge* e5 = new Edge(t1,t2);
    // // Edge* e6 = new Edge(t1,t3);
    // // Edge* e7 = new Edge(t1,t2);
    // // Edge* e8 = new Edge(t1,t3);
    // // Edge* e9 = new Edge(t1,t2);
    // // Edge* e10 = new Edge(t1,t3);
    // // Edge* e11 = new Edge(t1,t2);
    // // Edge* e12 = new Edge(t1,t3);

    // mapObject->Nodes.push_back(t1);
    // mapObject->Nodes.push_back(t2);
    // mapObject->Nodes.push_back(t3);
    // mapObject->Nodes.push_back(t4);
    
    // mapObject->Edges.push_back(e1);
    // mapObject->Edges.push_back(e2);
    // mapObject->Edges.push_back(e3);
    // mapObject->Edges.push_back(e4);

    // std::cout << "Checking for map connectivitiy, continents are connected subgraphs, and each country belongs to one continent: ";
    // mapObject->validate();
    
    // mapObject->Nodes.push_back(t5);
    // mapObject->Nodes.push_back(t6);
    // mapObject->Nodes.push_back(t7);
    // mapObject->Nodes.push_back(t8);
    // mapObject->Nodes.push_back(t9);
    // mapObject->Nodes.push_back(t9);
    // mapObject->Nodes.push_back(t10);
    // mapObject->Nodes.push_back(t11);
    
    MapLoader maploader;
    Map* map = nullptr;

    map = maploader.readMap("canada.map");

    std::cout << "Size of nodes: " << map->Nodes.size() << std::endl;
    std::cout << "Size of edges: " << map->Edges.size() << std::endl;
    
    map->validate();
    
    // delete t1, delete t2,delete t3, delete t4;
    // delete e1, delete e2, delete e3, delete e4;
    // // delete t5, delete t6, delete t7, delete t8, delete t9, delete t10, delete t11;
    // delete Ahmad, delete Mostafa, delete Marieme;
    // delete mapObject;
    

    return 0;
}