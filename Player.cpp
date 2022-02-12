#include "Player.h"

Player::~Player() {
    std::cout << "Player object successfully destroyed" << std::endl;
}

Player::Player() {
    std::cout << "Player object successfully created" << std::endl;
}

Player::Player(int val) {
    value = val;
}

void Player::issueOrder() {
    std::cout << "WORKED" << std::endl;
}