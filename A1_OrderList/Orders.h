#pragma once
using namespace std;

class Order
{
public:
    Order* next;
    Order* prev;
    void validate();
    void execute();
    Order(Order*,Order*,int);
    ~Order();
};

class OrderList
{
public:
    OrderList();
    ~OrderList();
    void add(Order, int);
    void move();
    void remove();
private:
    Order* head;
};



class Deploy : public Order
{
    Deploy();
};

class Advance : public Order
{
    Advance();
};

class Bomb : public Order
{
    Bomb();
};

class Blockade : public Order
{
    Blockade();
};

class Airlift : public Order
{
    Airlift();
};

class Negotiate : public Order
{
    Negotiate();
};
