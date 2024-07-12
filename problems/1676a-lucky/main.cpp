// Problem: 1676A. Lucky?
// Problem statement: https://codeforces.com/problemset/problem/1676/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <numeric>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <charconv>

namespace r = std::ranges;
namespace rv = std::ranges::views;

template<typename T>
void get_from_cin(std::vector<T>& vec, size_t count) {
    std::copy_n(std::istream_iterator<T>(std::cin), count, std::back_inserter(vec));
}

template<typename T, size_t n>
void get_from_cin(std::array<T, n>& arr) {
    std::copy_n(std::istream_iterator<T>(std::cin), n, arr.begin());
}

unsigned digit_to_unsigned(char c) {
    char cs[2] = "\0";
    cs[0] = c;
    unsigned result;
    std::from_chars(cs, cs+1, result);
    return result;
}

template<r::input_range R>
unsigned sum_digits(R&& range) {
    auto ints = rv::transform(range, digit_to_unsigned);
    return std::accumulate(ints.begin(), ints.end(), 0u);
}

int main() {
    unsigned test_count = 1;
    std::cin >> test_count;
    while(test_count--) {
        std::array<char, 6> ticket_digits;
        get_from_cin(ticket_digits);
        std::cin.ignore(1, '\n');

        auto first_half = ticket_digits | rv::take(3);
        auto second_half = ticket_digits | rv::drop(3);
        std::cout << (sum_digits(first_half) == sum_digits(second_half) ? "YES" : "NO") << std::endl;
    }
}
