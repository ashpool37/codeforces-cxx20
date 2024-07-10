#include <iostream>

int main() {
    unsigned n, m;
    std::cin >> n >> m;

    if(n > m) std::swap(n, m);

    std::cout << (n % 2 == 0 ? "Malvika" : "Akshat") << std::endl;
}
