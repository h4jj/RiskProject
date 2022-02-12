#include "Orders.cpp"

int main()
{
    OrderList* obj = new OrderList();
    
    Deploy* depObj = new Deploy(nullptr,1);
    Advance* advObj = new Advance(nullptr,2);

    obj->add(depObj);
    obj->add(advObj);
    // obj->add(3);
    // obj->add(4);
    // obj->add(5);
    // obj->add(6);
    
    obj->print();
    
    delete depObj;
    delete advObj;
    delete obj;

    return 0;
}