#include "Orders.cpp"

int main()
{
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;
    int value4 = 4;
    int value5 = 5;
    int value6 = 6;

    cout << "-------------------------" << endl;

    OrderList* obj = new OrderList();

    cout << "-------------------------" << endl;

    Deploy* d = new Deploy(nullptr, &value1);
    Advance* a = new Advance(nullptr, &value2);
    Bomb* b = new Bomb(nullptr, &value3);
    Blockade* bl = new Blockade(nullptr, &value4);
    Airlift* ai = new Airlift(nullptr, &value5);
    Negotiate* n = new Negotiate(nullptr, &value6);

    cout << "-------------------------" << endl;

    obj->add(d);
    obj->add(a);
    obj->add(b);
    obj->add(bl);
    obj->add(ai);
    obj->add(n);

    cout << "-------------------------" << endl;

    obj->print();

    cout << "length of the list: " << obj->length() << endl;

    cout << "-------------------------" << endl;

    obj->move(2,6);

    obj->print();

    cout << "-------------------------" << endl;

    obj->move(1,6);

    obj->print();

    cout << "-------------------------" << endl;

    obj->move(6,1);

    obj->print();

    cout << "length of the list: " << obj->length() << endl;

    cout << "-------------------------" << endl;

    d->validation();

    cout << endl;
    
    d->execution();

    Deploy* copyD = new Deploy(*d);

    //cout << "order type address copyD: " << &copyD->orderType << endl;
    //cout << "order type address d: " << &d->orderType << endl;

    //cout << "order type copyD->next: " << *copyD->next->orderType << endl;

    //cout << "order type address copyD: " << *copyD->orderType << endl;
    //cout << "order type address d: " << *d->orderType << endl;

    //cout << "order type address copyD: " << *copyD->orderType << endl;
    //cout << "order type address d: " << *d->orderType << endl;
    
    OrderList* copyObj = new OrderList(*(obj));

    obj->print();

    obj->move(1,4);

    cout << "obj: " << endl;

    obj->print();

    cout << "-------------------------" << endl;

    copyObj->print();

    cout << "-------------------------" << endl;

    
    delete obj;
    delete d;
    delete a;
    delete b;
    delete bl;
    delete ai;
    delete n;

    return 0;
}