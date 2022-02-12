#pragma once
#include <iostream>

class Player {  
    public:
        Player();
        ~Player();
        Player(int);
        void issueOrder();
        int value;
};