#include <iostream>
#include <array>
#include <numeric>
#include <ranges>

int main() {
    unsigned test_count;
    std::cin >> test_count;

    while(test_count--) {
        unsigned array_length;
        std::cin >> array_length;

        std::array<unsigned, 100> numbers;
        numbers.fill(1);

        for(size_t divisor = 1; divisor <= array_length; divisor++) {
            for(size_t i = divisor - 1; i < array_length; i += divisor) {
                auto gcd = std::gcd(divisor, numbers.at(i));
                numbers[i] *= divisor / gcd;
            }
        }

        for(auto n : numbers | std::ranges::views::take(array_length - 1))
            std::cout << n << " ";
        std::cout << numbers.at(array_length - 1) << std::endl;
    }
}
