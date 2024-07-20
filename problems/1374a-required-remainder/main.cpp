// Problem: 1374A. Required Remainder
// Problem statement: https://codeforces.com/problemset/problem/1374/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <charconv>
#include <ranges>
#include <type_traits>
#include <cstdint>

/* #region templates */

using umax = std::uintmax_t;

unsigned digit_to_unsigned(char c) {
    char cs[2] = "\0";
    cs[0] = c;
    unsigned result;
    std::from_chars(cs, cs+1, result);
    return result;
}

char unsigned_to_digit(unsigned n) {
    char cs[2] = "\0";
    std::to_chars(cs, cs+1, n);
    return cs[0];
}

template<std::integral T>
auto range(T start, T step, size_t count) {
    using namespace std::ranges::views;
    return iota(0u, count) | transform([=](size_t i){ return start + step * static_cast<T>(i); });
}

template<std::integral BaseT, std::integral ExponentT>
auto power(BaseT base, ExponentT exponent) {
    std::common_type_t<BaseT, ExponentT> result = 1;
    while(exponent--) result *= base;
    return result;
}

/* #endregion */

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        unsigned divisor, remainder, max_result;
        std::cin >> divisor >> remainder >> max_result;

        unsigned result = max_result / divisor * divisor + remainder;
        if(result > max_result) result -= divisor;

        std::cout << result << std::endl;
    }
}
