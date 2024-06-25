#include <iostream>

unsigned turn_count(unsigned a, unsigned b) {
    if (a <= b) return b - a;
    else if (a % b == 0) return 0;
    else return ((a / b) + 1) * b - a;
}

int main() {
    unsigned test_count;
    std::cin >> test_count;

    for(unsigned test_no = 0; test_no < test_count; test_no++) {
        unsigned a, b;
        std::cin >> a >> b;

        std::cout << turn_count(a, b) << std::endl;
    }
}
