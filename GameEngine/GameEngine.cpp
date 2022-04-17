#include "GameEngine.h"
#include "Map.cpp"
#include "Player.cpp"
#include "Orders.cpp"
#include "Cards.cpp"

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
        return;
    }

    this->map->buildContinentVector();
    std::cout << "Successfully built continent vector, looping over it now: \n";

    for(auto con : this->map->continentVector) {
        std::cout << "Continent: " << con.continent_name << " , size: " << con.territories.size() << '\n';
        for(const auto terr : con.territories) {
            std::cout << terr->getCountry() << " ";
        }
        std::cout << '\n';
    } 
}

void GameEngine::reinforcementPhase() {

    for(const auto& player : Players) {

        //1- check if player owns entire continent        

        for(const auto con : this->map->continentVector) {
            int counter = 0;
            for(const auto terr : con.territories) {
                for(const auto terrPlayer : player->territories) {
                    if(terr->getCountry() == terrPlayer->getCountry()) {
                        counter++;
                    }
                }
            }

            if(counter == con.territories.size()) {
                player->reinforcementPool += con.control_bonus;
            }

            counter = 0;
        }

        if(player->territories.size() <= 9) {
            player->reinforcementPool += 3;
        }
        else {
            player->reinforcementPool += floor(player->territories.size() / 3);
        }
    }

}
void GameEngine::issueOrdersPhase() {
    for(const auto& player : Players) {
        std::cout << "ISSUING ORDER FOR PLAYER: " << player->name << std::endl;
        player->issueOrder(player->ps);
    }
}

void GameEngine::executeOrdersPhase() {
    std::cout << "Executing orders now: " << std::endl;
    int counter = 0;
    bool empty = false;

    while(!empty) {
        for(const auto p : Players) {
            if(p->orderListObject->orderQueue.size() != 0) {
                std::cout << "TRYING TO ACCESS FRONT ORDER" << std::endl;
                Order* order = p->orderListObject->orderQueue.front();
                p->orderListObject->orderQueue.pop();
                std::cout << "POPPED ORDER AND ATTEMPTING TO EXEC" << std::endl;
                order->execute();
                std::cout << "EXECUTED ORDER" << std::endl;
            }
        }
        std::cout << "LEAVING EXECUTE ORDERS PHASE NOW" << std::endl;
        break;
        // for(const auto p : Players) {
        //     if(p->orderListObject->orderQueue.size() == 0) {
        //         empty = true;
        //     }
        //     else {
        //         empty = false;
        //         break;
        //     }
        // }   
    }
}


void GameEngine::mainGameLoop() {
    std::cout << "Entering main game loop..." << std::endl;

    if(state == State::WIN) {
        return;
    }

    reinforcementPhase();
    issueOrdersPhase();
    executeOrdersPhase();

    int counter = 0;
    bool flag = false;
    for(const auto p : Players) {
        if(p->territories.size() == 0) {
            flag = true;
            break;
        }
        counter++;
    }

    if(flag){
        Players.erase(Players.begin() + counter);
    }
    if(Players.size() == 1) {
        state = State::WIN;
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
                        std::string name, playerType;
                        std::cout << "Input name for player: "<<std::endl;
                        std::cout << "> ";
                        std::cin >> name;

                        std::cout << "What kind of player do you want this to be?" << std::endl;
                        std::cout << "1) Human\n";
                        std::cout << "2) Aggressive\n";
                        std::cout << "3) Benevolent\n";
                        std::cout << "4) Neutral\n";
                        std::cout << "5) Cheater\n" << std::endl;

                        std::cout << "> ";
                        std::cin >> playerType;

                        Player* p = new Player(name);
                        p->map = this->map;

                        std::transform(playerType.begin(), playerType.end(), playerType.begin(), ::toupper);

                        if(playerType == "HUMAN") {
                            HumanPlayerStrategy* hps = new HumanPlayerStrategy();
                            p->ps = hps;
                            hps->p = p;
                            std::cout << "Human Player Strategy has been selected" << std::endl;
                        }
                        else if(playerType == "AGGRESSIVE") {
                            AggressivePlayerStrategy* aps = new AggressivePlayerStrategy();
                            p->ps = aps;
                            aps->p = p;
                            std::cout << "Aggressive Player Strategy has been selected" << std::endl;
                        }
                        else if(playerType == "BENEVOLENT") {
                            BenevolentPlayerStrategy* bps = new BenevolentPlayerStrategy();
                            p->ps = bps;
                            bps->p = p;
                            std::cout << "Benevolent Player Strategy has been selected" << std::endl;
                        }
                        else if(playerType == "NEUTRAL") {
                            NeutralPlayerStrategy* nps = new NeutralPlayerStrategy();
                            p->ps = nps;
                            nps->p = p;
                            std::cout << "Neutral Player Strategy has been selected" << std::endl;
                        }
                        else if(playerType == "CHEATER") {

                        }

                        p->gEng = this;
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
                            player->reinforcementPool = 50;
                            std::cout << "Player " << player->name << " army count: " << player->reinforcementPool << std::endl;
                        }
                        this->state = State::ASSIGN_REIN;
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
            while(state != State::WIN) {
                mainGameLoop();
            }
            std::cout << "Player: " << Players.at(0)->name << " has won the game!" << std::endl;
            std::cout << "Would you like to play again? (y/n)" <<std::endl;
            char ans;
            std::cout << "> ";
            std::cin >> ans;

            if(ans == 'y') {
                state = State::START;
                phase = Phase::STARTUP;
            }
            else {
                std::cout << "Thanks for playing, exiting." << std::endl;
                exit(0);
            }
        }

    }
}

// void GameEngine::takeInputTest() {
    
//     MapLoader mapLoader;

//     this->map = mapLoader.readMap("canada.map");
//     this->map->validate();
    
//     Player* p1 = new Player("Ahmad");
//     Player* p2 = new Player("Mostafa");
//     p1->map = this->map;
//     p2->map = this->map;
//     p1->gEng = this;
//     p2->gEng = this;
//     this->Players.push_back(p1);
//     this->Players.push_back(p2);

//     int counter = 0;
//     // equally assign territories to players
//     // both map and territory share same pointers now
//     std::cout << "Length of nodes: " << this->map->Nodes.size() << std::endl;

//     for(const auto t : map->Nodes) {
//         // std::cout << "Player " << *(this->Players.at(counter % this->Players.size())->name) << " now owns " << t->getCountry() << " which is located in " << t->getContinent() << std::endl;
//         Players.at(counter % Players.size())->territories.push_back(t);    
//         counter++;
//     }

//     for(const auto& player: Players) {
//         std::cout << "Player " << player->name << " owns: " << endl;
//         for(const auto& t : player->territories) {
//             std::cout << t->getCountry() << " , armyCount: " << t->getArmyCount();
//         }
//         std::cout << std::endl << std::endl; 
//     }
//     // exit(0);

//     // deck created
//     Deck* deck = new Deck();

//     // initialize each player with 50 armies
//     for(auto& player : this->Players) {
//         deck->draw(player->hand);
//         deck->draw(player->hand);
//         player->reinforcementPool = 50;
//         std::cout << "Player " << player->name << " army count: " << player->reinforcementPool << std::endl;
//     }
//     this->state = State::ASSIGN_REIN;
//     this->phase = Phase::PLAY;

//     while(state != State::WIN) {
//         mainGameLoop();
//     }
//     std::cout << "Player: " << Players.at(0)->name << " has won the game!" << std::endl;
//     std::cout << "Would you like to play again? (y/n)" <<std::endl;
//     char ans;
//     std::cout << "> ";
//     std::cin >> ans;

//     if(ans == 'y') {
//         state = State::START;
//         phase = Phase::STARTUP;
//     }
//     else {
//         std::cout << "Thanks for playing, exiting." << std::endl;
//         exit(0);
//     }
    

// }

// void GameEngine::startupPhaseTest() {

//     // main - menu
//     while(true) {
//         takeInputTest();
//     }
// }


void GameEngine::startupPhase() {

    // main - menu
    while(true) {
        showMenu();
        takeInput();
    }
}
