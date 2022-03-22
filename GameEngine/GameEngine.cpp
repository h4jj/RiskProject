#include "GameEngine.h"
#include "Map.cpp"
#include "Player.cpp"
#include "Orders.cpp"
#include "Cards.cpp"
#include "LogObserver.h"

GameEngine::GameEngine() {std::cout << "Game Engine successfully created" << std::endl;}
GameEngine::~GameEngine() {std::cout << "Game Engine successfully destroyed" << std::endl;}

std::ostream& operator<<(std::ostream& out, const Phase phase) {
    std::map<Phase, std::string> strings;

    strings.insert(std::pair<Phase, std::string>(Phase::STARTUP, "Startup"));
    strings.insert(std::pair<Phase, std::string>(Phase::PLAY, "Play"));

    for(auto it = strings.begin(); it != strings.end(); it++) {
        if(phase == it->first) {
            return out << it->second;
        }
    }

    return out << "Invalid State";
}

std::ostream& operator<<(std::ostream& out, const State state) {
    std::map<State, std::string> strings;

    strings.insert(std::pair<State, std::string>(State::START, "Start"));
    strings.insert(std::pair<State, std::string>(State::MAP_LOADED, "Map Loaded"));
    strings.insert(std::pair<State, std::string>(State::MAP_VALIDATED, "Map Validated"));
    strings.insert(std::pair<State, std::string>(State::PLAYERS_ADDED, "Players Added"));
    strings.insert(std::pair<State, std::string>(State::ASSIGN_REIN, "Assign Reinforcement"));
    strings.insert(std::pair<State, std::string>(State::ISSUE_ORDERS, "Issue Orders"));
    strings.insert(std::pair<State, std::string>(State::EXEC_ORDERS, "Execture Orders"));
    strings.insert(std::pair<State, std::string>(State::WIN, "Win!"));

    for(auto it = strings.begin(); it != strings.end(); it++) {
        if(state == it->first) {
            return out << it->second;
        }
    }

    return out << "Invalid State";
}

GameEngine::GameEngine(const GameEngine& g) {
    this->state = g.state;
    transition();
    this->map = new Map(*(g.map));
    for(const auto& p : g.Players) {
        Player* player = new Player(*p);
        this->Players.push_back(player);
    }
}

// GameEngine& GameEngine::operator=(const GameEngine& g) {
//     this->state = g.state;
//     this->map = g.map;
//     this->p1 = g.p1;
//     this->p2 = g.p2;
//     this->p3 = g.p3;
// }


void GameEngine::showMenu() {

    std::cout << "##########################################################" << std::endl;
    std::cout << std::endl << std:: endl;
    std::cout << "                Welcome to Warzone                        " << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "##########################################################" << std::endl;
    std::cout << std::endl;
    std::cout << "Current phase of the game is: " << this->phase << std::endl << std::endl;
    std::cout << "Current state of the game is: " << this->state << std::endl << std::endl;
    std::cout << "List of available commands: " << std::endl << std::endl;
    std::cout << "1) LoadMap" << std::endl;
    std::cout << "2) ValidateMap" << std::endl;
    std::cout << "3) AddPlayer" << std::endl;
    std::cout << "4) GameStart" << std::endl;
    // std::cout << "5) IssueOrder" << std::endl;
    // std::cout << "6) EndIssueOrder" << std::endl;
    // std::cout << "7) ExecuteOrder" << std::endl;
    // std::cout << "8) EndExecuteOrder" << std::endl;
    // std::cout << "9) Win" << std::endl;
    // std::cout << "10) PlayAgain" << std::endl;
    // std::cout << "11) End" << std::endl << std::endl;
}

void GameEngine::showAvailableMaps() {
    std::cout << std::endl << std::endl;
    std::cout << "List of available Maps: "<<std::endl;
    std::cout << "1) canada.map"<<std::endl;
    std::cout << "2) europe.map" <<std::endl;
}

void GameEngine::pickMap() {
    std::string input;
    std::cout << std::endl << std::endl;
    std::cout << "> ";
    std::cin >> input;
    MapLoader maploader;

    if(input.compare("canada.map") == 0) {
        this->map = maploader.readMap("canada.map");
    }
    else if(input.compare("europe.map") == 0) {
        this->map = maploader.readMap("europe.map");
    }
    else {
        std::cout << "Incorrect input please try again" << std::endl;
    }
}

void GameEngine::reinforcementPhase() {
    
}
void GameEngine::issueOrdersPhase() {

}
void GameEngine::executeOrdersPhase() {

}

void GameEngine::mainGameLoop() {
    std::cout << "Entering main game loop..." << std::endl;
    while(true) {
        std::cout << "Player count: " << this->Players.size() << std::endl;
        for(const auto& player : this->Players) {
            // reinforcementPhase();
            std::cout << player->name << " has " << player->territories.size() << " territories" << std::endl;
        }
        exit(0);
        // for(const auto& player : this->Players) {
        //     issueOrdersPhase();
        // }   
        // for(const auto& player : this->Players) {
        //     executeOrdersPhase();
        // }      
    }
}


void GameEngine::takeInput() {

    switch(this->phase) {

        case Phase::STARTUP: {
            std::string input;

            std::cout << "> ";
            std::cin >> input;

            switch(this->state) {
                case State::START: {
                    transition();
                    if(input.compare("LoadMap") == 0 && this->map == nullptr) {
                        while(true) {
                            showAvailableMaps();
                            pickMap();

                            if(this->map != nullptr) {
                                break;
                            }
                            else {
                                std::cout << "Could not use map, please pick another one" << std::endl;
                            }
                        }

                        std::cout << "Map successfully loaded" << std::endl;
                        this->state = State::MAP_LOADED;
                        transition();
                        break;
                        
                    }
                    else {
                        std::cout << "The only available command at this state is - LoadMap -" << std::endl << std::endl;
                        break;
                    }
                }
                case State::MAP_LOADED: {
            
                    if(input.compare("ValidateMap") == 0) {
                        std::cout << "Map Validity: ";
                        if(this->map->validate()) {
                            std::cout << endl;
                            this->state = State::MAP_VALIDATED;
                            transition();
                        }
                        else {
                            std::cout << "Map is not valid" << std::endl; 
                        }
                        
                    }
                    else if(input.compare("LoadMap") == 0) {
                        std::cout << "Map has already been loaded" << std::endl;
                    }
                    else {
                        std::cout << "Incorrect input please try again" << std::endl;
                    }

                    break;
                }

                case State::MAP_VALIDATED: {
                    if(input.compare("AddPlayer") == 0) {
                        if(this->Players.size() >= 6) {
                            std::cout << "You cannot add anymore players, please move onto the next game state" << std::endl;
                            break;
                        }
                        std::string name;
                        std::cout << "Input name for player: "<<std::endl;
                        std::cout << "> ";
                        std::cin >> name;

                        Player* p = new Player(name);
                        this->Players.push_back(p);

                    }
                    else if(input.compare("GameStart") == 0) {
                        if(this->Players.size() < 2) {
                            std::cout << "Not enough players to start game" << std::endl;
                            break;
                        }

                        int counter = 0;
                        // equally assign territories to players
                        // both map and territory share same pointers now
                        std::cout << "Length of nodes: " << this->map->Nodes.size() << std::endl;

                        for(const auto t : map->Nodes) {
                            // std::cout << "Player " << *(this->Players.at(counter % this->Players.size())->name) << " now owns " << t->getCountry() << " which is located in " << t->getContinent() << std::endl;
                            Players.at(counter % Players.size())->territories.push_back(t);    
                            counter++;
                        }

                        for(const auto& player: Players) {
                            std::cout << "Player " << player->name << " owns: " << endl;
                            for(const auto& t : player->territories) {
                                std::cout << t->getCountry() << " ";
                            }
                            std::cout << std::endl << std::endl; 
                        }
                        std::vector<Player*> PlayersCopy = {};
                        for(auto p : Players) {
                            PlayersCopy.push_back(p);
                        }
                        std::vector<Player*> playerOrder;

                        while(!PlayersCopy.empty()) {
                            std::uniform_int_distribution<int> dist(0,PlayersCopy.size()-1);
                            std::random_device rd;
                            std::mt19937 generator(rd());
                            int number = dist(generator);

                            playerOrder.push_back(PlayersCopy.at(number));
                            PlayersCopy.erase(PlayersCopy.begin() + number);
                        }
                        std::cout << "Player order is: " << std::endl;
                        for(const auto& p : playerOrder) {
                            std::cout << p->name << std::endl;
                        }

                        std::cout << std::endl << std::endl;

                        // deck created
                        Deck* deck = new Deck();

                        // initialize each player with 50 armies
                        for(auto& player : this->Players) {
                            deck->draw(player->hand);
                            deck->draw(player->hand);
                            player->armyCount = 50;
                            std::cout << "Player " << player->name << " army count: " << player->armyCount << std::endl;
                        }
                        this->state = State::ASSIGN_REIN;
                        transition();
                        this->phase = Phase::PLAY;
                        break;
                    }
                    else {
                        std::cout << "Incorrect input please try again" << std::endl;
                    }

                    break;
                }
            }
            break;
        }

        case Phase::PLAY: {
            // mainGameLoop();
            exit(0);
            break;
        }

    }
        // switch(this->state) {
        //     case State::ASSIGN_REIN: {
        //         if(input.compare("IssueOrder") == 0) {
        //             this->state = State::ISSUE_ORDERS;
        //         }
        //         else {
        //             std::cout << "The only available command in this state is IssueOrder" << std::endl;
        //         }

        //         break;
        //     }

        //     case State::ISSUE_ORDERS: {

        //         if(input.compare("IssueOrder") == 0) {
        //             std::cout << "Issuing more Orders" << std::endl;
        //         }
        //         else if(input.compare("EndIssueOrder") == 0) {
        //             std::cout << "Ending Issue Orders" << std::endl;
        //             this->state = State::EXEC_ORDERS;
        //         }
        //         else {
        //             std::cout << "The only available commands are - IssueOrder and EndIssueOrder" << std::endl;
        //         }

        //         break;
        //     }

        //     case State::EXEC_ORDERS: {

        //         if(input.compare("ExecuteOrder") == 0){
        //             std::cout << "Executing Order" << std::endl;
        //         }
        //         else if(input.compare("EndExecuteOrder") == 0) {
        //             std::cout << "Ending Order execution" << std::endl;
        //             this->state = State::ASSIGN_REIN;
        //         }
        //         else if(input.compare("Win") == 0) {
        //             std::cout << "Congrats you won!" << std::endl;
        //             this->state = State::WIN;
        //         }
        //         else {
        //             std::cout << "Incorrect input please try again" << std::endl;
        //         }

        //         break;
        //     }

        //     case State::WIN: {
        //         if(input.compare("Play") == 0) {
        //             std::cout << "Going back to start state" << std::endl;
        //             for(auto& p : this->Players) {
        //                 delete p;
        //                 p = NULL;
        //             }
        //             delete this->map;
        //             this->map = nullptr;
        //             this->state = State::START;
        //         }
        //         else if(input.compare("End") == 0) {
        //             for(auto& p : this->Players) {
        //                 delete p;
        //                 p = NULL;
        //             }
        //             delete this->map;
        //             std::cout << "Exiting Game now" << std::endl;
        //             exit(0);
        //         }
        //         else{
        //             std::cout << "Incorrect input please try again" << std::endl;
        //         }
        //     }
        // }
}
void GameEngine::Notify(ILoggable *ge){
    LogObserver lo;
    lo.Update(ge);
}
std::string GameEngine::stringToLog(){
    cout << "New State: " << this->state << "." << std::endl;
    std::string s;
    switch(this->state){
        case State::START:
            s = "START";
            break;
        case State::MAP_VALIDATED:
            s = "MAP_VALIDATED";
            break;
        case State::PLAYERS_ADDED:
            s = "PLAYER_ADDED";
            break;
        case State::ASSIGN_REIN:
            s = "ASSGIN_REIN";
            break;
        case State::ISSUE_ORDERS:
            s = "ISSUE_ORDERS";
            break;
        case State::EXEC_ORDERS:
            s = "EXEC_ORDERS";
            break;
        default:
            s = "^";
            break;
    }
    return "Current state: " + s + ".\n";
}
void GameEngine::transition(){
    Notify(this);
}

void GameEngine::startupPhase() {

    // main - menu
    while(true) {
        showMenu();
        takeInput();
    }
}

