#include "PlayerStrategies.h"

HumanPlayerStrategy::~HumanPlayerStrategy() {

}

BenevolentPlayerStrategy::~BenevolentPlayerStrategy() {

}

NeutralPlayerStrategy::~NeutralPlayerStrategy() {

}

AggressivePlayerStrategy::~AggressivePlayerStrategy() {

}


void HumanPlayerStrategy::issueOrder() {
    std::cout << "\n\n\n" << std::endl;
    std::cout << "Player: " << p->name << "'s turn" << std::endl;
    std::vector<Territory*> toDefendVect = p->toDefend(this);
    std::vector<Territory*> toAttackVect = p->toAttack(this);
    std::vector<Deploy*> deployVect;

    while(p->reinforcementPool != 0) {
        std::cout << "Issue deploy order on the following territories: " <<std::endl;
        std::cout << "Current number of troops available: " << p->reinforcementPool << std::endl;
        std::cout << "Reinforcement pool: " <<p->reinforcementPool << std::endl;
        // exit(0);
        printVect(toDefendVect);
        std::string answer;
        std::cout << "> ";
        std::cin >> answer;
        Territory* terr = nullptr;

        for(const auto _terr : toDefendVect) {
            if(_terr->getCountry() == answer) {
                terr = _terr;
                break;
            }
        }

        if(terr != nullptr) {

            while(true) {
                std::cout << "Enter number of troops you wish to deploy to p territory: ";
                std::string answer;
                std::cin >> answer;

                if(stoi(answer) >= 0 && stoi(answer) <= p->reinforcementPool) {
                    Deploy* order = new Deploy();
                    p->reinforcementPool -= stoi(answer);
                    order->armyCount = stoi(answer);
                    order->player = p;
                    order->territory = terr->getCountry();
                    p->orderListObject->orderQueue.push(order);
                    deployVect.push_back(order);
                    break;
                }
                else {
                    std::cout << "Incorrect input please try again" << std::endl;
                }
            }
            
        }
        else {
            std::cout << "Incorrect input please try again" << std::endl;
        }
    }

    while(true) {
        std::cout << "Would you like to issue an advance order? (y/n)" << std::endl;
        char y;
        std::cin >> y;

        if(y == 'y');
        else if(y =='n')break;
        else {
            std::cout << "incorrect input please try again"<<std::endl;
            continue;
        }

        std::cout << "Choose territory to issue advance order: " << std::endl;
        printVect(toDefendVect);
        std::cout << "> ";
        std::string answer;
        std::cin >> answer;
        Territory* homeTerr = nullptr;

        for(const auto item : toDefendVect) {
            if(item->getCountry() == answer) {
                homeTerr = item;
                break;
            }
        }

        if(homeTerr != nullptr) {
            std::vector<Territory*> adjacentTerrsAttackable;
            std::vector<Territory*> adjacentTerrsDefendable;

            for(const auto pair : p->map->Edges) {
                bool inValid = false;
                if(pair->AdjacencyEdges.first->getCountry() == homeTerr->getCountry()) {
                    for(const auto item : p->territories) {
                        if(item->getCountry() == pair->AdjacencyEdges.second->getCountry()) {
                            adjacentTerrsDefendable.push_back(pair->AdjacencyEdges.second);
                            inValid = true;
                        }
                    }

                    if(!inValid) {
                       adjacentTerrsAttackable.push_back(pair->AdjacencyEdges.second); 
                    }
                }
                else if(pair->AdjacencyEdges.second->getCountry() == homeTerr->getCountry()) {
                    for(const auto item : p->territories) {
                        if(item->getCountry() == pair->AdjacencyEdges.first->getCountry()) {
                            adjacentTerrsDefendable.push_back(pair->AdjacencyEdges.first);
                            inValid = true;
                        }
                    }

                    if(!inValid) {
                       adjacentTerrsAttackable.push_back(pair->AdjacencyEdges.first); 
                    }
                }
            }
            std::cout << endl;
            std::cout << "Adjacent countries that you can attack: "<<std::endl;
            printVect(adjacentTerrsAttackable);
            std::cout << "\n\n" << std::endl;
            std::cout << "Adjacent territories to defend" << std::endl;
            printVect(adjacentTerrsDefendable);
            std::cout << "\n\n" << std::endl;

            Territory* decisionAttack = nullptr, *decisionDefend = nullptr;
            while(true) {

                std::string Answer;
                std::cout << "> ";
                std::cin >> Answer;

                for(const auto item : adjacentTerrsAttackable) {
                    if(item->getCountry() == Answer) {
                        decisionAttack = item;
                        break;
                    }
                }

                for(const auto item : adjacentTerrsDefendable) {
                    if(item->getCountry() == Answer) {
                        decisionDefend = item;
                        break;
                    }
                }

                if(decisionAttack != nullptr || decisionDefend != nullptr) {
                    break;
                }
                else {
                    std::cout << "Incorrect input please try again"<<std::endl;
                }
            }

            int availableTroops =0;
            for(const auto order : deployVect) {
                if(order->territory == homeTerr->getCountry()) {
                    availableTroops = order->armyCount;
                    break;
                }
            }

            if(decisionAttack != nullptr) {
                Advance* order = new Advance();

                while(true){

                    std::cout << "Available troops to attack with: " << availableTroops << std::endl;
                    std::cout << "How many troops would you like to attack with?"<<std::endl;
                    std::string answer;
                    std::cin >> answer;
                    int intAnswer = stoi(answer);

                    if(intAnswer <= availableTroops) {
                        
                        order->armyCount = intAnswer;
                        order->src = p;
                        order->edges = p->map->Edges;
                        order->t1 = homeTerr->getCountry();
                        order->t2 = decisionAttack->getCountry();
                        p->orderListObject->orderQueue.push(order);
                        break;
                    }
                    else {
                        std::cout << "Incorrect input please try again";
                    }
                }
            }
            else {
                Advance* order = new Advance();

                while(true){
                    std::cout << "Available troops to defend with: " << availableTroops << std::endl;
                    std::cout << "How many troops would you like to defend with?"<<std::endl;
                    std::string answer;
                    std::cin >> answer;
                    int intAnswer = stoi(answer);

                    if(intAnswer <= availableTroops) {
                        
                        order->armyCount = intAnswer;
                        order->src = p;
                        order->edges = p->map->Edges;
                        order->t1 = homeTerr->getCountry();
                        order->t2 = decisionDefend->getCountry();
                        p->orderListObject->orderQueue.push(order);
                        break;
                    }
                    else {
                        std::cout << "Incorrect input please try again";
                    }
                }
            }
        }
        break;
    }


    if(p->hand->handVector.size() > 0) {
        std::cout << "Would you like to play one of your cards? (y/n)" << std::endl;
        std::cout << "> ";
        char answer;
        std::cin >> answer;
        if(answer == 'y') {
            Card* card = p->hand->handVector.front();
            p->hand->handVector.pop();
            
            switch(card->cardType) {
                case OrderType::AIRLIFT: {
                    Airlift* order = new Airlift();
                    order->orderType = (int)OrderType::AIRLIFT;
                    std::cout << "Airlift order created" << std::endl;
                    std::cout << "Enter territory 1: ";
                    std::string answer1, answer2, answer3;
                    std::cin >> answer1;
                    std::cout << "Enter territory 2: ";
                    std::cin >> answer2;
                    std::cout << "Enter number of troops to move: ";
                    int troops;
                    std::cin >> answer3;
                    troops = stoi(answer3);
                    order->t1 = answer1;
                    order->t2 = answer2;
                    order->armyCount = troops;
                    order->player = p;

                    p->orderListObject->orderQueue.push(order);
                    break;
                }
                case OrderType::BLOCKADE: {
                    Blockade* order = new Blockade();
                    order->orderType = (int)OrderType::BLOCKADE;
                    std::cout << "Blockade order created" << std::endl;
                    printVect(toDefendVect);
                    std::cout << "Enter territory to issue blockade order on" << std::endl;
                    std::string answer;
                    std::cout << "> ";
                    std::cin >> answer;
                    order->t1 = answer;
                    order->player = p;
                    p->orderListObject->orderQueue.push(order);
                    break;
                }
                case OrderType::BOMB: {
                    Bomb* order = new Bomb();
                    order->orderType = (int)OrderType::BOMB;
                    std::cout << "Bomb order created" << std::endl;
                    printVect(toAttackVect);
                    std::cout << "Pick a territory to bomb: \n";
                    std::string answer;
                    std::cout << "> ";
                    std::cin >> answer;
                    order->t1 = answer;
                    order->owner = p;
                    order->edges = p->map->Edges;
                    p->orderListObject->orderQueue.push(order);
                    break;
                }
                case OrderType::DIPLOMACY: {
                    Negotiate* order = new Negotiate();
                    order->orderType = (int)OrderType::DIPLOMACY;
                    std::cout << "Negotiate order created" << std::endl;
                    p->orderListObject->orderQueue.push(order);
                    break;
                }
                case OrderType::REINFORCEMENT: {

                    break;
                }
                default: {
                    std::cout << "Invalid card type could not play" << std::endl;
                }
            }
        }
        
    }
       
}

void BenevolentPlayerStrategy::issueOrder() {

}

void NeutralPlayerStrategy::issueOrder() {
    std::cout << "\n\n\n" << std::endl;
    std::cout << "Player: " << p->name << "'s turn - Neutral Player mode - No orders can or will be issued" << std::endl;
}

void AggressivePlayerStrategy::issueOrder() {
    std::cout << "\n\n\n" << std::endl;
    std::cout << "Player: " << p->name << "'s turn - Aggressive Player mode" << std::endl;
    std::vector<Territory*> toDefendVect = p->toDefend(this);
    std::vector<Territory*> toAttackVect = p->toAttack(this);
    std::vector<Deploy*> deployVect;

    std::cout << "Issue deploy order on the following territories: " <<std::endl;
    std::cout << "Current number of troops available: " << p->reinforcementPool << std::endl;
    std::cout << "Reinforcement pool: " <<p->reinforcementPool << std::endl;

    Territory* terr = nullptr;
    bool firstRound = true;

    for(const auto _terr : toDefendVect) {
        if(_terr->getArmyCount() != 0) {
            terr = _terr;
            firstRound = false;
            break;
        }
    }

    if(firstRound) {
        terr = toDefendVect.at(0);
    }
    
    Deploy* order = new Deploy();
    order->armyCount = p->reinforcementPool;
    p->reinforcementPool = 0;
    order->player = p;
    order->territory = terr->getCountry();
    p->orderListObject->orderQueue.push(order);
    deployVect.push_back(order);

    std::cout << "Deploy order successfully added to order queue" << std::endl;


    std::vector<Territory*> adjacentTerrsAttackable = this->toAttack();


    Territory* homeTerr = terr;
    Territory* decisionAttack = this->toAttackCountry(terr).at(0) != nullptr ? this->toAttackCountry(terr).at(0) : nullptr;

    int availableTroops =0;
    for(const auto order : deployVect) {
        if(order->territory == homeTerr->getCountry()) {
            availableTroops = order->armyCount;
            break;
        }
    }

    if(decisionAttack != nullptr) {
        Advance* order = new Advance();

        for(const auto p : p->gEng->Players) {
            for(const auto t : p->territories) {
                if(t == decisionAttack) {
                    order->target = p;
                    break;
                }
            }
        }

        order->armyCount = availableTroops;
        order->src = p;
        order->edges = p->map->Edges;
        order->t1 = homeTerr->getCountry();
        order->t2 = decisionAttack->getCountry();
        p->orderListObject->orderQueue.push(order);
        std::cout << "Advance order successfully pushed to order queue" << std::endl;
    }
    else {
        std::cout << "Attack vector is empty, not attacking this round" << std::endl;
    }
    
}

std::vector<Territory*> AggressivePlayerStrategy::toAttackCountry(Territory* terr) {
    std::vector<Territory*> toAttackVect = {};

    for(const auto edge : p->map->Edges) {
        bool inValid = false;
        if(edge->AdjacencyEdges.first->getCountry() == terr->getCountry()) {
            for(const auto terr : toAttackVect) {
                if(terr->getCountry() == edge->AdjacencyEdges.second->getCountry()) {
                    inValid = true;
                }
            }

            for(const auto terr : p->territories) {
                if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                    inValid = true;
                }
            }

            if(!inValid) {
                toAttackVect.push_back(edge->AdjacencyEdges.second);
            }
        }
        else if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
            for(const auto terr : toAttackVect) {
                if(terr->getCountry() == edge->AdjacencyEdges.first->getCountry()) {
                    inValid = true;
                }
            }

            for(const auto terr : p->territories) {
                if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                    inValid = true;
                }
            }

            if(!inValid) {
                toAttackVect.push_back(edge->AdjacencyEdges.first);
            }
        }
    }

    return toAttackVect;
}

std::vector<Territory*> HumanPlayerStrategy::toAttack() {

    std::vector<Territory*> toAttackVect = {};

    for(const auto terr : p->territories) {
        for(const auto edge : p->map->Edges) {
            bool inValid = false;
            if(edge->AdjacencyEdges.first->getCountry() == terr->getCountry()) {
                for(const auto terr : toAttackVect) {
                    if(terr->getCountry() == edge->AdjacencyEdges.second->getCountry()) {
                        inValid = true;
                    }
                }

                for(const auto terr : p->territories) {
                    if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                        inValid = true;
                    }
                }

                if(!inValid) {
                    toAttackVect.push_back(edge->AdjacencyEdges.second);
                }
            }
            else if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                for(const auto terr : toAttackVect) {
                    if(terr->getCountry() == edge->AdjacencyEdges.first->getCountry()) {
                        inValid = true;
                    }
                }

                for(const auto terr : p->territories) {
                    if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                        inValid = true;
                    }
                }

                if(!inValid) {
                    toAttackVect.push_back(edge->AdjacencyEdges.first);
                }
            }
        }
    }

    return toAttackVect;
}

std::vector<Territory*> BenevolentPlayerStrategy::toAttack() {
    std::vector<Territory*> toAttackVect = {};

    for(const auto terr : p->territories) {
        for(const auto edge : p->map->Edges) {
            bool inValid = false;
            if(edge->AdjacencyEdges.first->getCountry() == terr->getCountry()) {
                for(const auto terr : toAttackVect) {
                    if(terr->getCountry() == edge->AdjacencyEdges.second->getCountry()) {
                        inValid = true;
                    }
                }

                for(const auto terr : p->territories) {
                    if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                        inValid = true;
                    }
                }

                if(!inValid) {
                    toAttackVect.push_back(edge->AdjacencyEdges.second);
                }
            }
            else if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                for(const auto terr : toAttackVect) {
                    if(terr->getCountry() == edge->AdjacencyEdges.first->getCountry()) {
                        inValid = true;
                    }
                }

                for(const auto terr : p->territories) {
                    if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                        inValid = true;
                    }
                }

                if(!inValid) {
                    toAttackVect.push_back(edge->AdjacencyEdges.first);
                }
            }
        }
    }

    return toAttackVect;
}

std::vector<Territory*> NeutralPlayerStrategy::toAttack() {
    std::vector<Territory*> toAttackVect = {};

    for(const auto terr : p->territories) {
        for(const auto edge : p->map->Edges) {
            bool inValid = false;
            if(edge->AdjacencyEdges.first->getCountry() == terr->getCountry()) {
                for(const auto terr : toAttackVect) {
                    if(terr->getCountry() == edge->AdjacencyEdges.second->getCountry()) {
                        inValid = true;
                    }
                }

                for(const auto terr : p->territories) {
                    if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                        inValid = true;
                    }
                }

                if(!inValid) {
                    toAttackVect.push_back(edge->AdjacencyEdges.second);
                }
            }
            else if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                for(const auto terr : toAttackVect) {
                    if(terr->getCountry() == edge->AdjacencyEdges.first->getCountry()) {
                        inValid = true;
                    }
                }

                for(const auto terr : p->territories) {
                    if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                        inValid = true;
                    }
                }

                if(!inValid) {
                    toAttackVect.push_back(edge->AdjacencyEdges.first);
                }
            }
        }
    }

    return toAttackVect;
}

std::vector<Territory*> AggressivePlayerStrategy::toAttack() {
    std::vector<Territory*> toAttackVect = {};

    for(const auto terr : p->territories) {
        for(const auto edge : p->map->Edges) {
            bool inValid = false;
            if(edge->AdjacencyEdges.first->getCountry() == terr->getCountry()) {
                for(const auto terr : toAttackVect) {
                    if(terr->getCountry() == edge->AdjacencyEdges.second->getCountry()) {
                        inValid = true;
                    }
                }

                for(const auto terr : p->territories) {
                    if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                        inValid = true;
                    }
                }

                if(!inValid) {
                    toAttackVect.push_back(edge->AdjacencyEdges.second);
                }
            }
            else if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                for(const auto terr : toAttackVect) {
                    if(terr->getCountry() == edge->AdjacencyEdges.first->getCountry()) {
                        inValid = true;
                    }
                }

                for(const auto terr : p->territories) {
                    if(edge->AdjacencyEdges.second->getCountry() == terr->getCountry()) {
                        inValid = true;
                    }
                }

                if(!inValid) {
                    toAttackVect.push_back(edge->AdjacencyEdges.first);
                }
            }
        }
    }

    return toAttackVect;
}

std::vector<Territory*> HumanPlayerStrategy::toDefend() {
    return p->territories;
}

std::vector<Territory*> BenevolentPlayerStrategy::toDefend() {
    return p->territories;
}

std::vector<Territory*> NeutralPlayerStrategy::toDefend() {
    return p->territories;
}

std::vector<Territory*> AggressivePlayerStrategy::toDefend() {
    return p->territories;
}

