#include "Player.h"

// Destructor

Player::~Player() {
    std::cout << "Player object successfully destroyed" << std::endl;
}

// Constructor

Player::Player() {
    std::cout << "Player object successfully created" << std::endl;
    
    hand = new Hand();
    std::cout << "hand object successfully created" << std::endl;
    
    orderListObject = new OrderList();

    std::cout << "OrderList object successfully created" << std::endl;
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

void Player::toAttack() {

}

// Method to return list of arbitrary territories

void Player::toDefend() {

}

// takes order type as input
// creates Order object based on input given to issueOrder() method
// DEPLOY=1,ADVANCE=2,BOMB=3,BLOCKADE=4,AIRLIFT=5,NEGOTIATE=6

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