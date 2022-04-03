#include "Player.h"
#include "Orders.h"
#include <vector>
#include <algorithm>

enum class StrategyName {HUMAN,AGGRESSIVE,BENEVOLENT,NEUTRAL,CHEATER};

class Player;

class PlayerStrategy {
public:
	PlayerStrategy();
	~PlayerStrategy();
	PlayerStrategy(const PlayerStrategy&);
	PlayerStrategy& operator=(const PlayerStrategy&);

	virtual void issueOrder() = 0;
	std::vector<Territory*> toAttack() = 0;
	std::vector<Territory*> toDefend() = 0;
};

class HumanPlayerStrategy :  public PlayerStrategy {
public:
	HumanPlayerStrategy();
	~HumanPlayerStrategy();
	HumanPlayerStrategy(const HumanPlayerStrategy&);
	HumanPlayerStrategy& operator=(const HumanPlayerStrategy&);

	void issueOrder();
	std::vector<Territory*> toAttack();
	std::vector<Territory*> toDefend();
};

class AggressivePlayerStrategy :  public PlayerStrategy {
public:
	AggressivePlayerStrategy();
	~AggressivePlayerStrategy();
	AggressivePlayerStrategy(const AggressivePlayerStrategy&);
	AggressivePlayerStrategy& operator=(const AggressivePlayerStrategy&);

	void issueOrder();
	std::vector<Territory*> toAttack();
	std::vector<Territory*> toDefend();
};

class BenevolentPlayerStrategy : public PlayerStrategy {
public:
	BenevolentPlayerStrategy();
	~BenevolentPlayerStrategy();
	BenevolentPlayerStrategy(const BenevolentPlayerStrategy&);
	BenevolentPlayerStrategy& operator=(const BenevolentPlayerStrategy&);


	void issueOrder();
	std::vector<Territory*> toAttack();
	std::vector<Territory*> toDefend();
};

class NeutralPlayerStrategy : public PlayerStrategy {
public:
	NeutralPlayerStrategy();
	~NeutralPlayerStrategy();
	NeutralPlayerStrategy(const NeutralPlayerStrategy&);
	NeutralPlayerStrategy& operator=(const NeutralPlayerStrategy&);


	void issueOrder();
	std::vector<Territory*> toAttack();
	std::vector<Territory*> toDefend();
};

class CheaterPlayerStrategy :  public PlayerStrategy {
public:
	CheaterPlayerStrategy();
	~CheaterPlayerStrategy();
	CheaterPlayerStrategy(const CheaterPlayerStrategy&);
	CheaterPlayerStrategy& operator=(const CheaterPlayerStrategy&);


	void issueOrder();
	std::vector<Territory*> toAttack();
	std::vector<Territory*> toDefend();
};
