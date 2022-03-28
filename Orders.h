#pragma once
#include <iostream>
#include <random>
#include <queue>
#include "Player.h"
#include "Map.h"
#include "LoggingObserver.h"

class Player;

class Order : public Subject, public ILoggable
{
public:
    Order();
    Order(Order *, int);
    Order *next;
    int orderType;
    void validation();
    void execution();
    virtual void execute() = 0;
    Order(const Order& o);
    friend std::ostream& operator << (std::ostream& out, Order& o);
    std::string stringToLog() override;
    void Notify(ILoggable *) override;
};

class OrderList : public Subject, public ILoggable
{
public:
    OrderList();
    OrderList(const OrderList& ol);
    void add(Order *);
    void print();
    void remove(int);
    void move(int, int);
    int length();
    const Order* getHead();
    const Order* getTail();
    std::queue<Order*> orderQueue;
    std::string stringToLog() override;
    void Notify(ILoggable *) override;
private:

    Order *head;
    Order *tail;
};

class Deploy : public Order
{
public:
    int armyCount;
    Player* player = nullptr;
    std::string territory;
    virtual void execute();
    Deploy() = default;
    Deploy(Order *, int);
    std::string stringToLog() override;
    void Notify(ILoggable *) override;
};

class Advance : public Order
{
public:
    int armyCount;
    Player *src = nullptr, *target = nullptr;
    std::string t1,t2;
    std::vector<Edge*> edges;
    virtual void execute();
    Advance(Order *, int);
    Advance() = default;
    std::string stringToLog() override;
    void Notify(ILoggable *) override;
};

class Bomb : public Order
{
public:
    std::vector<Edge*> edges;
    Player *owner;
    std::string t1;
    virtual void execute();
    Bomb(Order *, int);
    Bomb() = default;
    std::string stringToLog() override;
    void Notify(ILoggable *) override;
};

class Blockade : public Order
{
public:
    Player *player, *neutralPlayer;
    std::string t1;
    virtual void execute();
    Blockade(Order *, int);
    Blockade() = default;
    std::string stringToLog() override;
    void Notify(ILoggable *) override;
};

class Airlift : public Order
{
public:
    Player *player;
    std::string t1,t2;
    int armyCount;
    virtual void execute();
    Airlift() = default;
    Airlift(Order *, int);
    std::string stringToLog() override;
    void Notify(ILoggable *) override;
};

class Negotiate : public Order
{
public:
    virtual void execute();
    Negotiate(Order *, int);
    Negotiate() = default;
    Player *src, *target;
    std::string stringToLog() override;
    void Notify(ILoggable *) override;
};
