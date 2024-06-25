#include <iostream>
#include <algorithm>

int main() {
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    std::cout << std::max({
        a*b*c,
        a*b+c,
        a+b*c,
        a+b+c,
        a*(b+c),
        (a+b)*c,
    }) << std::endl;
}
