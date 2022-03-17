#include "Player.h"

// Destructor

Player::~Player() {
    std::cout << "Player object successfully destroyed" << std::endl;
}

// Constructor

Player::Player(std::string _name) {
    name = _name;
    std::cout << "Player object successfully created having name: " << name << std::endl;
    
    hand = new Hand();
    std::cout << "hand object successfully created" << std::endl;
    
    orderListObject = new OrderList();
    int reinforcementPool;

}

// Copy Constructor

Player::Player(const Player& p) {
    std::cout << "Copy constructor successfully called" << std::endl;
    this->orderListObject =  new OrderList(*(p.orderListObject));
    this->hand = new Hand(*(p.hand));
}

// Assignment Operator

Player& Player::operator=(const Player& p) {
    std::cout << "Assignment operator successfully called" << std::endl;
    this->orderListObject =  new OrderList(*(p.orderListObject));
    this->hand = new Hand(*(p.hand));

    return *this;
}

// Method to return list of arbitrary territories

std::list<Territory*> Player::toAttack() {
    if(this->territories.size() != 0) {
        std::list<Territory*> randTerritories;
        int even = 0;

        for(auto const& x : this->territories) {
            if(even%2==0){
                randTerritories.push_back(x);
            }
            even++;
        }
        
        return randTerritories;
    }
    else {
        std::cout << "Player does not own any territories" << std::endl;
    }

    std::list<Territory*> emptyList;

    return emptyList;
}

// Method to return list of arbitrary territories

std::list<Territory*> Player::toDefend() {
    if(this->territories.size() != 0) {
        std::list<Territory*> randTerritories;
        int odd = 1;

        for(auto const& x : this->territories) {
            if(odd%2==0){
                randTerritories.push_back(x);
            }
            odd++;
        }
        
        return randTerritories;
    }
    else {
        std::cout << "Player does not own any territories" << std::endl;
    }

    std::list<Territory*> emptyList;

    return emptyList;
}

// takes order type as input
// creates Order object based on input given to issueOrder() method
// DEPLOY=1,ADVANCE=2,BOMB=3,BLOCKADE=4,AIRLIFT=5,NEGOTIATE=6

void Player::setUnattackable(std::string val) {unAttackableName = val;}

void Player::issueOrder(int orderType) {

    switch(orderType) {
        case 1:
            {
                Deploy* depObj = new Deploy(nullptr, orderType);
                this->orderListObject->add(depObj);
                break;
            }
        case 2:
            {
                Advance* advObj = new Advance(nullptr, orderType);
                this->orderListObject->add(advObj);
                break;
            }
        case 3:
            {
                Bomb* bombObj = new Bomb(nullptr, orderType);
                this->orderListObject->add(bombObj);
                break;
            }
        case 4:
            {
                Blockade* blockadeObj = new Blockade(nullptr, orderType);
                this->orderListObject->add(blockadeObj);
                break;
            }
        case 5:
            {
                Airlift* airliftObj = new Airlift(nullptr, orderType);
                this->orderListObject->add(airliftObj);
                break;
            }
        case 6:
            {
                Negotiate* negotiateObj = new Negotiate(nullptr, orderType);
                this->orderListObject->add(negotiateObj);
                break;
            }
        default: std::cout << "Invalid Order Type" << std::endl;
    }
}
