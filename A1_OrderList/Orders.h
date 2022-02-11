class OrderList
{
public:
    // OrderList(int* length, Order* order[]);
private:
};

class Order
{
public:
    void move();
    void remove();
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
