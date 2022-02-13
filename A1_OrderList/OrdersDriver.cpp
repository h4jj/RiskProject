#include "Orders.cpp"

int main()
{

    int value1 = 1, value2 = 2, value3 = 3;

    OrderList* obj = new OrderList();
    Deploy* depObj = new Deploy(nullptr,&value1);
    Advance* advObj = new Advance(nullptr,&value2);


    obj->add(depObj);
    obj->add(advObj);
    
    obj->print();
    
    delete depObj;
    delete advObj;
    delete obj;

    

    return 0;
}