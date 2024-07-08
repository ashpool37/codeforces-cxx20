#include <iostream>

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        unsigned a, b;
        std::cin >> a >> b;

        if(a > b) std::swap(a, b);

        std::cout << (b - a) / 10 + (((b - a) % 10 == 0 ? 0 : 1)) << std::endl;
    }
}
