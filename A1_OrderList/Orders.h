#pragma once
#include <iostream>

class Order
{
public:
    Order(Order *, int *);
    Order *next;
    int *orderType;
    void validation();
    void execution();
};

class OrderList
{
public:
    OrderList();
    void add(Order *);
    void print();
    void remove(int);
    void move(int, int);
    int length();

private:
    Order *head;
    Order *tail;
};

class Deploy : public Order
{
public:
    Deploy(Order *, int *);
};

class Advance : public Order
{
public:
    Advance(Order *, int *);
};

class Bomb : public Order
{
public:
    Bomb(Order *, int *);
};

class Blockade : public Order
{
public:
    Blockade(Order *, int *);
};

class Airlift : public Order
{
public:
    Airlift(Order *, int *);
};

class Negotiate : public Order
{
public:
    Negotiate(Order *, int *);
};
