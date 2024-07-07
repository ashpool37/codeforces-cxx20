#include <algorithm>
#include <iostream>
#include <iterator>
#include <array>

int main() {
    unsigned test_count;
    std::cin >> test_count;

    while(test_count--) {
        std::array<unsigned, 3> numbers;
        std::copy_n(std::istream_iterator<unsigned>(std::cin), 3, numbers.begin());

        std::ranges::sort(numbers, std::greater());

        std::cout << (numbers.at(0) == numbers.at(1) + numbers.at(2) ? "YES" : "NO") << std::endl;
    }
}
