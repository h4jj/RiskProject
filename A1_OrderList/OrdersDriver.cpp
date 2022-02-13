#include "Orders.cpp"

int main()
{
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;
    int value4 = 4;
    int value5 = 5;
    int value6 = 6;

    OrderList* obj = new OrderList();
    
    Deploy* d = new Deploy(nullptr, &value1);
    Advance* a = new Advance(nullptr, &value2);
    Bomb* b = new Bomb(nullptr, &value3);
    Blockade* bl = new Blockade(nullptr, &value4);
    Airlift* ai = new Airlift(nullptr, &value5);
    Negotiate* n = new Negotiate(nullptr, &value6);

    obj->add(d);
    obj->add(a);
    obj->add(b);
    obj->add(bl);
    obj->add(ai);
    obj->add(n);
    
    obj->print();

    cout << obj->length() << endl;

    obj->move(6,1);

    obj->print();

    cout << obj->length() << endl;

    delete obj;
    delete d;

    return 0;
}