#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    unsigned test_count;
    std::cin >> test_count;

    while(test_count--) {
        unsigned array_length;
        std::cin >> array_length;

        std::vector<unsigned> numbers;
        std::copy_n(std::istream_iterator<unsigned>(std::cin), array_length, std::back_inserter(numbers));
        
        std::ranges::sort(numbers);
        bool distance_more_than_1 = false;
        for(size_t i = 0; i < array_length - 1; i++) {
            if(numbers.at(i+1) - numbers.at(i) > 1) {
                distance_more_than_1 = true;
                break;
            }
        }
        std::cout << (distance_more_than_1 ? "NO" : "YES") << std::endl;
    }
}
