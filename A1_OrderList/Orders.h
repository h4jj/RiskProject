#pragma once
using namespace std;

class OrderList
{
public:
    OrderList();
    void move();
    void remove();
};

class Order
{
public:

    void validate();
    void execute();
};

class Deploy : public Order
{
};

class Advance : public Order
{
};

class Bomb : public Order
{
};

class Blockade : public Order
{
};

class Airlift : public Order
{
};

class Negotiate : public Order
{
};
