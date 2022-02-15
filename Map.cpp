#include "Map.h"

Territory::Territory(std::string _country, std::string _continent, Player *player, int _armyCount)
{
    country = _country;
    continent = _continent;
    territoryOwner = player;
    armyCount = &_armyCount;

    terr_id = id;
    id++;

    std::cout << "Territory object created having ID: " << terr_id << std::endl;
}

Territory::Territory(std::string _country, std::string _continent)
{
    country = _country;
    continent = _continent;

    terr_id = id;
    id++;

    std::cout << "Territory object created having ID: " << terr_id << std::endl;
}

Territory::~Territory()
{
    std::cout << "territoryOwner and Territory object destroyed, rest was used for stack allocation" << std::endl;
}

int Territory::id = 0;

Edge::Edge(Territory *ptr1, Territory *ptr2)
{
    this->AdjacencyEdges.first = ptr1;
    this->AdjacencyEdges.second = ptr2;
    std::cout << "Edge object created linking " << ptr1->getCountry() << " and " << ptr2->getCountry() << std::endl;
}

Edge::~Edge()
{
    std::cout << "Edge object successfully destroyed" << std::endl;
}

Map::Map()
{
    std::cout << "Map object created" << std::endl;
}

Map::~Map()
{
    std::cout << "Map object destroyed" << std::endl;
}

bool Map::validate()
{

    // 1 - Check map is a connected graph

    bool unvisitedNodes[this->Nodes.size()];

    for (int i{0}; i < this->Nodes.size(); i++)
    {
        unvisitedNodes[i] = false;
    }

    unvisitedNodes[0] = true;

    for (Territory *territory : this->Nodes)
    {

        for (Edge *edge : this->Edges)
        {
            if (edge->AdjacencyEdges.first == territory)
            {
                int id = edge->AdjacencyEdges.second->getID();
                if (unvisitedNodes[id] == false)
                {
                    unvisitedNodes[id] = true;
                }
            }
        }
    }

    for (int i{0}; i < this->Nodes.size(); i++)
    {
        if (unvisitedNodes[i] == false)
        {
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

Map *MapLoader::readMap(std::string filepath)
{

    // 1 - create map data structure of continents

    std::map<int, std::string> Continents;
    int continentCounter = 1;
    Map *mapObject = new Map();
    std::ifstream stream(filepath);
    std::string line;
    std::string continent;
    std::vector<Edge *> tempVect;
    bool foundContinent = false, foundCountry = false, foundBorders = false;

    while (getline(stream, line))
    {
        if (line.find("[continents]") != std::string::npos)
        {
            foundContinent = true;
            continue;
        }

        if (foundContinent)
        {
            if (line.empty())
            {
                break;
            }

            std::stringstream ss(line);
            ss >> continent;
            Continents.insert(std::pair<int, std::string>(continentCounter, continent));
            continentCounter++;
        }
    }

    // 2 - link each country to a continent and create Territory objects

    while (getline(stream, line))
    {
        if (line.find("[countries]") != std::string::npos)
        {
            foundCountry = true;
            continue;
        }
        if (foundCountry)
        {

            if (line.empty())
            {
                foundCountry = false;
                break;
            }

            int placeholder, continentTracker;
            std::string country;
            std::stringstream ss(line);
            ss >> placeholder >> country >> continentTracker;
            for (auto const &x : Continents)
            {
                if (x.first == continentTracker)
                {
                    Territory *t = new Territory(country, x.second);
                    mapObject->Nodes.push_back(t);
                    break;
                }
            }
        }
    }

    // 3 - connect the edges

    int countrySlot = 0, tempCounter = 0;

    while (getline(stream, line))
    {
        if (line.find("[borders]") != std::string::npos)
        {
            foundBorders = true;
            continue;
        }

        if (foundBorders)
        {

            if (line.empty())
            {
                break;
            }

            std::string var;
            bool initialSlot = true;
            std::stringstream ss(line);
            while (getline(ss, var, ' '))
            {

                bool pushBack = true;

                if (initialSlot)
                {
                    initialSlot = false;
                    continue;
                }
                Edge *e = new Edge(mapObject->Nodes.at(countrySlot), mapObject->Nodes.at(stoi(var) - 1));

                for (auto &x : tempVect)
                {
                    if (e->AdjacencyEdges.first->getCountry() == x->AdjacencyEdges.first->getCountry() || e->AdjacencyEdges.first->getCountry() == x->AdjacencyEdges.second->getCountry())
                    {
                        if (e->AdjacencyEdges.second->getCountry() == x->AdjacencyEdges.first->getCountry() || e->AdjacencyEdges.second->getCountry() == x->AdjacencyEdges.second->getCountry())
                        {
                            pushBack = false;
                            break;
                        }
                    }
                }

                if (pushBack)
                {
                    tempVect.push_back(e);
                    mapObject->Edges.push_back(e);
                }
            }
            countrySlot++;
        }
    }

    return mapObject;
}

Territory::Territory(const Territory &t)
{
    terr_id = t.terr_id;
    country = t.country;
    continent = t.continent;
    territoryOwner = new Player(*t.territoryOwner);
    armyCount = new int(*armyCount);
}

Edge::Edge(const Edge &e)
{
}

Map::Map(const Map &m)
{
    for (int i = 0; i < m.Edges.size(); i++)
    {
        Edges[i] = new Edge(*m.Edges[i]);
    }

    for (int i = 0; i < m.Nodes.size(); i++)
    {
        Nodes[i] = new Territory(*m.Nodes[i]);
    }
}

MapLoader::MapLoader(const MapLoader &ml)
{
}

Territory &Territory::operator=(const Territory &t)
{
    if (this != &t)
    {
        id = t.id;
    }
    return *this;
}

Edge &Edge::operator=(const Edge &e)
{
}

Map &Map::operator=(const Map &m)
{
    if (this != &m)
    {
        for (int i = 0; i < m.Edges.size(); i++)
        {
            Nodes[i] = Nodes[i];
        }
        for (int i = 0; i < m.Nodes.size(); i++)
        {
            Edges[i] = Edges[i];
        }
    }
    return *this;
}

MapLoader& MapLoader::operator =(const MapLoader& m)
{
    return *this;
}

ostream& operator <<(ostream& out, Territory& t)
{
    out << "Continent: " << t.getContinent() << "\n"
    << "Country: " << t.getCountry() << "\n"
    << "Army Count: " << *t.getArmyCount() << "\n"
    << "Territory id: " << t.getID() << endl;
}

void Territory::setContinent(std::string _continent) { continent = _continent; }
void Territory::setCountry(std::string _country) { country = _country; }
std::string Territory::getContinent() { return continent; }
std::string Territory::getCountry() { return country; }
Player *Territory::getTerritoryOwner() { return territoryOwner; }
int *Territory::getArmyCount() { return armyCount; }
int Territory::getID() { return terr_id; }