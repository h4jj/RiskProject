#pragma once
using namespace std;

class Order
{
public:
    Order* next;
    Order* prev;
    int orderType;
    void validate();
    void execute();
    Order();
    Order(Order*,Order*,int);
};

class OrderList
{
public:
    OrderList();
    void add(Order, int);
    void move();
    void remove();
    void print();
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
