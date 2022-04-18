#pragma once
#include "Player.h"
#include <vector>


class Player;
class Territory;

class PlayerStrategy {
public:
    Player* p;
    virtual ~PlayerStrategy() {};
    virtual void issueOrder() = 0;
    virtual std::vector<Territory*> toAttack() = 0;
    virtual std::vector<Territory*> toDefend() = 0;

};

class HumanPlayerStrategy : public PlayerStrategy {
public: 
    virtual ~HumanPlayerStrategy();
    HumanPlayerStrategy() = default;
    virtual void issueOrder();
    virtual std::vector<Territory*> toAttack();
    virtual std::vector<Territory*> toDefend();
};

class AggressivePlayerStrategy : public PlayerStrategy{
public: 
    virtual ~AggressivePlayerStrategy();
    virtual void issueOrder();
    std::vector<Territory*> toAttackCountry(Territory*);
    virtual std::vector<Territory*> toAttack();
    virtual std::vector<Territory*> toDefend();
};

class BenevolentPlayerStrategy : public PlayerStrategy{
public: 
    virtual ~BenevolentPlayerStrategy();
    virtual void issueOrder();
    virtual std::vector<Territory*> toAttack();
    virtual std::vector<Territory*> toDefend();
};

class NeutralPlayerStrategy : public PlayerStrategy{
public: 
    virtual ~NeutralPlayerStrategy();
    virtual void issueOrder();
    virtual std::vector<Territory*> toAttack();
    virtual std::vector<Territory*> toDefend();
};

