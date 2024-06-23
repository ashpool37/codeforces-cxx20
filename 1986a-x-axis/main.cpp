#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

unsigned f(unsigned a, std::vector<unsigned> const& xs) {
    unsigned result = 0;
    for(auto x : xs) {
        result += std::abs(static_cast<int>(x) - static_cast<int>(a));
    }
    return result;
}

int main() {
    unsigned test_count;
    std::cin >> test_count;
    for(unsigned _ = test_count; _--;) {
        unsigned x1, x2, x3;
        std::cin >> x1 >> x2 >> x3;

        std::vector<unsigned> xs{x1, x2, x3};
        std::ranges::sort(xs);

        std::cout << f(xs[1], xs) << std::endl;
    }
}
