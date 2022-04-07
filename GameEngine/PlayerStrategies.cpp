
#include "PlayerStrategies.h"
//
//PlayerStrategy
//

//constructor
PlayerStrategy::PlayerStrategy(){}

//destructor
PlayerStrategy::~PlayerStrategy(){}

//copy constructor
PlayerStrategy::PlayerStrategy(const PlayerStrategy& ps) {
	std::cout << "Copy constructor successfully called" << std::endl;
    this->StrategyName = ps.StrategyName;
    }

// Assignment Operator
PlayerStrategy& PlayerStrategy::operator=(const PlayerStrategy& ps) {
    std::cout << "Assignment operator successfully called" << std::endl;
    this->StrategyName = ps.StrategyName;
    return *this;
}

/******************************************************
 * HUMAN STRATEGY
 *****************************************************/
//requires user interactions to make decisions

//constructor
HumanPlayerStrategy::HumanPlayerStrategy(){}

//destructor
HumanPlayerStrategy::~HumanPlayerStrategy(){}

//copy constructor
HumanPlayerStrategy::HumanPlayerStrategy(const HumanPlayerStrategy& hs) {
	std::cout << "Copy constructor successfully called" << std::endl;
    //player = hs.player;
    }
    
// Assignment Operator
HumanPlayerStrategy& HumanPlayerStrategy::operator=(const HumanPlayerStrategy& hs) {
    std::cout << "Assignment operator successfully called" << std::endl;
   // player =hs.player;
    return *this;
}

void  HumanPlayerStrategy::issueOrder() {}
std::vector<Territory*> HumanPlayerStrategy::toAttack(){}
std::vector<Territory*> HumanPlayerStrategy::toDefend(){}

/******************************************************
 * AGGRESSIVE STRATEGY
 *****************************************************/
//computer player that focuses on attack (deploys or advances armies on its strongest
//country, then always advances to enemy territories until it cannot do so anymore)

//constructor
AggressivePlayerStrategy::AggressivePlayerStrategy(){}

//destructor
AggressivePlayerStrategy::~AggressivePlayerStrategy(){}

//copy constructor
AggressivePlayerStrategy::AggressivePlayerStrategy(const AggressivePlayerStrategy& as) {
	std::cout << "Copy constructor successfully called" << std::endl;
    //player = as.player;
    }
    
// Assignment Operator
AggressivePlayerStrategy& AggressivePlayerStrategy::operator=(const AggressivePlayerStrategy& as) {
    std::cout << "Assignment operator successfully called" << std::endl;
    //player = as.player;
    return *this;
}

void AggressivePlayerStrategy::issueOrder() {}
std::vector<Territory*> AggressivePlayerStrategy::toAttack(){}
std::vector<Territory*> AggressivePlayerStrategy::toDefend(){}

/******************************************************
 * BENEVOLENT STRATEGY
 *****************************************************/
// computer player that focuses on protecting its weak countries (deploys or advances armies
// on its weakest countries, never advances to enemy territories).

//constructor
BenevolentPlayerStrategy::BenevolentPlayerStrategy(){}

//destructor
BenevolentPlayerStrategy::~BenevolentPlayerStrategy(){}

//copy constructor
BenevolentPlayerStrategy::BenevolentPlayerStrategy(const BenevolentPlayerStrategy& bs) {
	std::cout << "Copy constructor successfully called" << std::endl;
    //player = bs.player;
    }
    
// Assignment Operator
BenevolentPlayerStrategy& BenevolentPlayerStrategy::operator=(const BenevolentPlayerStrategy& bs) {
    std::cout << "Assignment operator successfully called" << std::endl;
    //player = bs.player;
    return *this;
}
void BenevolentPlayerStrategy::issueOrder() {}
std::vector<Territory*> BenevolentPlayerStrategy::toAttack(){}
std::vector<Territory*> BenevolentPlayerStrategy::toDefend(){}


/******************************************************
 * NEUTRAL STRATEGY
 *****************************************************/
//computer player that never issues any order. If a Neutral player is attacked, it becomes an
//Aggressive player. 

//constructor
NeutralPlayerStrategy::NeutralPlayerStrategy(){}

//destructor
NeutralPlayerStrategy::~NeutralPlayerStrategy(){}

//copy constructor
NeutralPlayerStrategy::NeutralPlayerStrategy(const NeutralPlayerStrategy& ns) {
	std::cout << "Copy constructor successfully called" << std::endl;
    //player = ns.player;
    }
    
// Assignment Operator
NeutralPlayerStrategy& NeutralPlayerStrategy::operator=(const NeutralPlayerStrategy& ns) {
    std::cout << "Assignment operator successfully called" << std::endl;
    //player = ns.player;
    return *this;
}
void NeutralPlayerStrategy::issueOrder() {
    cout << "The neutral player does nothing." << endl;
}
std::vector<Territory*> NeutralPlayerStrategy::toAttack(){}
std::vector<Territory*> NeutralPlayerStrategy::toDefend(){}


/******************************************************
 * CHEATER STRATEGY
 *****************************************************/
//computer player that automatically conquers all territories that are adjacent to its own
//territories (only once per turn).

//constructor
CheaterPlayerStrategy::CheaterPlayerStrategy(){}

//destructor
CheaterPlayerStrategy::~CheaterPlayerStrategy(){}

//copy constructor
CheaterPlayerStrategy::CheaterPlayerStrategy(const CheaterPlayerStrategy& cs) {
	std::cout << "Copy constructor successfully called" << std::endl;
    //player = cs.player;
    }
    
// Assignment Operator
CheaterPlayerStrategy& CheaterPlayerStrategy::operator=(const CheaterPlayerStrategy& cs) {
    std::cout << "Assignment operator successfully called" << std::endl;
    //player = cs.player;
    return *this;
}
void CheaterPlayerStrategy::issueOrder() {}
std::vector<Territory*> CheaterPlayerStrategy::toAttack(){}
std::vector<Territory*> CheaterPlayerStrategy::toDefend(){}
