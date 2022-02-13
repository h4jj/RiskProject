#pragma once
#include <iostream>

class Order
{
public:
    Order(Order*,int*);
public:
    Order* next;
    int* orderType;
};

class OrderList
{
public:
    static int orderItems;
    OrderList();
    ~OrderList();
    void add(Order*);
    void print();
private:
    Order* head;
    Order* tail;
};

class Deploy : public Order
{
public:
    Deploy(Order*, int*);
    ~Deploy();
};

class Advance : public Order
{
public:
    Advance(Order*, int*);
    ~Advance();
};

class Bomb : public Order
{
public:
    Bomb(Order*, int*);
};

class Blockade : public Order
{
public:
    Blockade(Order*, int*);
};

class Airlift : public Order
{
public:
    Airlift(Order*, int*);
};

class Negotiate : public Order
{
public:
    Negotiate(Order*, int*);
};

