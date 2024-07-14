// Problem: 1560A. Dislike of Threes
// Problem statement: https://codeforces.com/problemset/problem/1560/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

size_t max_number_count = 1000;

int main() {
    auto good_number_filter = [](auto n) {
        return not (n % 3 == 0 or n % 10 == 3);
    };
    auto good_numbers_view = std::ranges::views::iota(1)
                             | std::ranges::views::filter(good_number_filter);

    std::vector<unsigned> good_numbers;
    good_numbers.reserve(max_number_count);

    std::copy_n(good_numbers_view.begin(), max_number_count, std::back_inserter(good_numbers));

    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        unsigned good_number_index;
        std::cin >> good_number_index;

        std::cout << good_numbers[good_number_index - 1] << std::endl;
    }
}
