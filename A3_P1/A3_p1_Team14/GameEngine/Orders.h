#pragma once
#include <iostream>
#include <random>
#include <queue>
#include "Player.h"
#include "Map.h"

class Player;

class Order
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
};

class OrderList
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
};

class Blockade : public Order
{
public:
    Player *player, *neutralPlayer;
    std::string t1;
    virtual void execute();
    Blockade(Order *, int);
    Blockade() = default;
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
};

class Negotiate : public Order
{
public:
    virtual void execute();
    Negotiate(Order *, int);
    Negotiate() = default;
    Player *src, *target;
};
