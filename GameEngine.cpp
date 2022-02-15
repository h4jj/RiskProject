#include "GameEngine.h"
#include "Map.cpp"
#include "Player.cpp"
#include "Orders.cpp"
#include "Cards.cpp"

GameEngine::GameEngine() {std::cout << "Game Engine successfully created" << std::endl;}
GameEngine::~GameEngine() {std::cout << "Game Engine successfully destroyed" << std::endl;}

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


void GameEngine::showMenu() {

    std::cout << "##########################################################" << std::endl;
    std::cout << std::endl << std:: endl;
    std::cout << "                Welcome to Warzone                        " << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "##########################################################" << std::endl;
    std::cout << std::endl;
    std::cout << "Current state of the game is: " << this->state << std::endl << std::endl;
    std::cout << "List of available commands: " << std::endl << std::endl;
    std::cout << "1) LoadMap" << std::endl;
    std::cout << "2) ValidateMap" << std::endl;
    std::cout << "3) AddPlayer" << std::endl;
    std::cout << "4) AssignCountries" << std::endl;
    std::cout << "5) IssueOrder" << std::endl;
    std::cout << "6) EndIssueOrder" << std::endl;
    std::cout << "7) ExecuteOrder" << std::endl;
    std::cout << "8) EndExecuteOrder" << std::endl;
    std::cout << "9) Win" << std::endl;
    std::cout << "10) PlayAgain" << std::endl;
    std::cout << "11) End" << std::endl << std::endl;
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

void GameEngine::takeInput() {
    
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
                }

                std::cout << "Map successfully loaded" << std::endl;
                this->state = State::MAP_LOADED;
                break;
                
            }
            else if(this->map != nullptr && input.compare("LoadMap") == 0) {
                std::cout << "Map has already been loaded" << std::endl;
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
                this->map->validate();
                std::cout << endl;
                this->state = State::MAP_VALIDATED;
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
                std::string name;
                std::cout << "Input name for player: "<<std::endl;
                std::cout << "> ";
                std::cin >> name;
                
                p1 = new Player(name);
                this->state = State::PLAYERS_ADDED;

            }
            else {
                std::cout << "Incorrect input please try again" << std::endl;
            }

            break;
        }

        case State::PLAYERS_ADDED: {
            if(input.compare("AddPlayer") == 0) {
                std::string name;
                std::cout << "Input name for player: "<<std::endl;
                std::cout << "> ";
                std::cin >> name;
                
                if(p2 == nullptr) {
                    p2 = new Player(name);
                }
                else if(p3 == nullptr) {
                    p3 = new Player(name);
                }   
                else {
                    std::cout << "All 3 Players have been created, you should now use AssignCountries command" << std::endl;
                }

            }

            else if(input.compare("AssignCountries") == 0) {
                std::cout << "You will be directed to the gameplay now" << std::endl;
                this->state = State::ASSIGN_REIN;
            }

            else {
                std::cout << "Incorrect input please try again" << std::endl;
            }

            break;
        }

        case State::ASSIGN_REIN: {
            if(input.compare("IssueOrder") == 0) {
                this->state = State::ISSUE_ORDERS;
            }
            else {
                std::cout << "The only available command in this state is IssueOrder" << std::endl;
            }

            break;
        }

        case State::ISSUE_ORDERS: {

            if(input.compare("IssueOrder") == 0) {
                std::cout << "Issuing more Orders" << std::endl;
            }
            else if(input.compare("EndIssueOrder") == 0) {
                std::cout << "Ending Issue Orders" << std::endl;
                this->state = State::EXEC_ORDERS;
            }
            else {
                std::cout << "The only available commands are - IssueOrder and EndIssueOrder" << std::endl;
            }

            break;
        }

        case State::EXEC_ORDERS: {

            if(input.compare("ExecuteOrder") == 0){
                 std::cout << "Executing Order" << std::endl;
            }
            else if(input.compare("EndExecuteOrder") == 0) {
                std::cout << "Ending Order execution" << std::endl;
                this->state = State::ASSIGN_REIN;
            }
            else if(input.compare("Win") == 0) {
                std::cout << "Congrats you won!" << std::endl;
                this->state = State::WIN;
            }
            else {
                std::cout << "Incorrect input please try again" << std::endl;
            }

            break;
        }

        case State::WIN: {
            if(input.compare("Play") == 0) {
                std::cout << "Going back to start state" << std::endl;
                delete this->p1;
                delete this->p2;
                delete this->p3;
                delete this->map;
                this->state = State::START;
            }
            else if(input.compare("End") == 0) {
                delete this->p1;
                delete this->p2;
                delete this->p3;
                delete this->map;
                std::cout << "Exiting Game now" << std::endl;
                exit(0);
            }
            else{
                std::cout << "Incorrect input please try again" << std::endl;
            }


            break;
        }
    }
}

void GameEngine::changeState() {

}

void GameEngine::start() {

    // main - menu
    while(true) {
        showMenu();
        takeInput();
    }
    

}

