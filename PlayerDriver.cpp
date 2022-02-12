#include "Player.cpp"
#include "Orders.cpp"

enum class OrderType {
    DEPLOY=1,ADVANCE=2,BOMB=3,BLOCKADE=4,AIRLIFT=5,NEGOTIATE=6
};

int main() {

    Player playerObj;
    OrderType typeObject;

    playerObj.issueOrder((int)OrderType::DEPLOY);
    playerObj.issueOrder((int)OrderType::ADVANCE);
    playerObj.issueOrder((int)OrderType::DEPLOY);
    playerObj.issueOrder((int)OrderType::BLOCKADE);
    
    playerObj.orderListObject->print();

    Player playerObj2(playerObj);
    playerObj2.issueOrder((int)OrderType::AIRLIFT);
    playerObj2.issueOrder((int)OrderType::NEGOTIATE);
    playerObj2.orderListObject->print();

    delete playerObj.orderListObject; 


    return 0;
}