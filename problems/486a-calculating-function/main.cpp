#include <iostream>
#include <cstdint>

std::intmax_t f(std::intmax_t n) {
    return -1 * (((((n - 1) % 2) == 0) ? 1 : -1) * (2 * n + 1) + 1) / 4;
}

int main() {
    std::intmax_t n;
    std::cin >> n;

    std::cout << f(n) << std::endl;
}
