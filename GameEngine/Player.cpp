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

std::vector<Territory*> Player::toAttack(PlayerStrategy* ps) {
    
    std::vector<Territory*> toAttackVect = ps->toAttack();

    return toAttackVect;
}

// Method to return list of arbitrary territories

std::vector<Territory*> Player::toDefend(PlayerStrategy* ps) {
    return ps->toDefend();
}

// takes order type as input
// creates Order object based on input given to issueOrder() method
// DEPLOY=1,ADVANCE=2,BOMB=3,BLOCKADE=4,AIRLIFT=5,NEGOTIATE=6

void Player::setUnattackable(std::string val) {unAttackableName = val;}

void Player::printTerritories() {
    std::cout << std::endl;
    std::cout << "Player: " << this->name << std::endl; 
    std::cout << "list of territories size: " << territories.size() << std::endl;
    for(const auto t : territories) {
        std::cout << t->getCountry() << " ";
    }
    std::cout << std::endl;
}

void printVect(std::vector<Territory*> terrVect) {
    int counter = 1;
    for(const auto terr : terrVect) {
        std::cout << counter<<")" <<terr->getCountry() << std::endl;
        counter++;
    }
}

void Player::issueOrder(PlayerStrategy* ps) { 
    ps->issueOrder();
}

