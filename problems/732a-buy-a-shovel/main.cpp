#include <iostream>

int main() {
    unsigned shovel_price, coin_denomination;
    std::cin >> shovel_price >> coin_denomination;

    unsigned shovel_count = 1;
    for(; shovel_count <= 10; shovel_count++) {
        if((shovel_count * shovel_price) % 10 == 0 
           or (shovel_count * shovel_price) % 10 == coin_denomination)
           break;
    }
    std::cout << shovel_count << std::endl;
}
