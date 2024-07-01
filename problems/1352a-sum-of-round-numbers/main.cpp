#include <iostream>
#include <ranges>
#include <vector>
#include <cmath>

double hard_ceil(double x) {
    double ceil = std::ceil(x);
    double _;
    if(std::modf(x, &_) == 0) return ceil + 1;
    else return ceil;
}

int main() {
    unsigned test_count;
    std::cin >> test_count;

    while(test_count--) {
        unsigned number;
        std::cin >> number;

        std::vector<unsigned> round_components;
        unsigned order_of_magnitude = static_cast<unsigned>(hard_ceil(std::log10(number)));
        while(order_of_magnitude--) {
            unsigned divisor = std::pow(10u, order_of_magnitude);
            unsigned round_component = (number % (divisor * 10u)) / divisor * divisor;
            if(round_component != 0u) round_components.push_back(round_component);
        }
        std::cout << round_components.size() << std::endl;
        for(auto round_component : round_components | std::ranges::views::take(round_components.size() - 1)) {
            std::cout << round_component << " ";
        }
        std::cout << round_components.at(round_components.size() - 1) << std::endl;
    }
}
