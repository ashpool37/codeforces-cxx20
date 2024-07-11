#include <algorithm>
#include <iostream>
#include <array>
#include <iterator>
#include <numeric>

unsigned const number_count = 3;

int main() {
    unsigned test_count;
    std::cin >> test_count;

    while(test_count--) {
        std::array<unsigned, number_count> numbers;
        std::copy_n(std::istream_iterator<unsigned>(std::cin), number_count,
                    numbers.begin());

        unsigned operation_count = 5;
        while(operation_count--) {
            std::ranges::sort(numbers);
            numbers[0] += 1;
        }

        unsigned result = std::accumulate(numbers.begin(), numbers.end(), 1u, std::multiplies());
        std::cout << result << std::endl;
    }
}
