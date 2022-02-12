#include "Orders.cpp"

int main()
{
    OrderList* obj = new OrderList();
    
    obj->add(1);
    obj->add(2);
    obj->add(3);
    obj->add(4);
    obj->add(5);
    obj->add(6);
    
    obj->print();

    delete obj;

    return 0;
}