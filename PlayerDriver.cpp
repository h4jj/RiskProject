#include "Player.cpp"
#include "Orders.cpp"

int main() {

    Player playerObj(5);
    Order orderObj(nullptr, 1);

    std::cout << playerObj.value << std::endl;

    return 0;
}