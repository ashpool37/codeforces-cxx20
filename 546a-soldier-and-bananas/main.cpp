#include <iostream>

int main() {
    int first_banana_price, balance, banana_count;
    std::cin >> first_banana_price >> balance >> banana_count;

    int total_cost = first_banana_price * (banana_count * (banana_count + 1) / 2);
    std::cout << std::max(0, -1 * (balance - total_cost)) << std::endl;
}
