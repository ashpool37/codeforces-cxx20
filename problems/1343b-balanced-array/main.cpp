// Problem: 1343B. Balanced Array
// Problem statement: https://codeforces.com/problemset/problem/1343/B?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>


unsigned arithmetic_series_partial_sum(unsigned first_element, unsigned delta, unsigned count) {
    return count * (2 * first_element + (count - 1) * delta) / 2;
}

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        unsigned array_length;
        std::cin >> array_length;

        if(array_length % 4 != 0) std::cout << "NO" << std::endl;
        else {
            std::cout << "YES" << std::endl;
            unsigned half_length = array_length / 2;
            unsigned first_element = 2;
            unsigned first_element_second_half = 1;
            unsigned delta = 2;
            unsigned half_sum = arithmetic_series_partial_sum(first_element, delta, half_length);
            unsigned half_sum_minus_last_element = arithmetic_series_partial_sum(first_element_second_half, delta, half_length - 1);
            unsigned last_element = half_sum - half_sum_minus_last_element;
            for(unsigned j = 0; j < half_length; j++) {
                std::cout << first_element + delta * j << " ";
            }
            for(unsigned j = 0; j < half_length - 1; j++) {
                std::cout << first_element_second_half + delta * j << " ";
            }
            std::cout << last_element << std::endl;
        }
    }
}
