#include <iostream>

int main() {
    unsigned balance;
    std::cin >> balance;

    unsigned banknote_count = 0;
    banknote_count += balance / 100u;
    banknote_count += (balance % 100u) / 20u;
    banknote_count += (balance % 20u) / 10u;
    banknote_count += (balance % 10u) / 5u;
    banknote_count += (balance % 5u) / 1u;

    std::cout << banknote_count << std::endl;
}
