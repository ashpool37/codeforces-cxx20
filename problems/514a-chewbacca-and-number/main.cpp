// Problem: 514A. Chewbacca and Number
// Problem statement: https://codeforces.com/problemset/problem/514/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <cmath>
#include <iostream>
#include <charconv>
#include <ranges>
#include <sstream>
#include <cstdint>
#include <cmath>

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

unsigned chewbacca_get_digit(std::istream& input_stream) {
    char digit;
    input_stream >> digit;
    unsigned digit_value = digit_to_unsigned(digit);
    digit_value = std::min(digit_value, 9 - digit_value);
    return digit_value;
}

int main() {
    std::string number_string;
    std::getline(std::cin, number_string);

    std::istringstream number_istream(number_string);
    umax result = 0;
    umax digit_value;
    bool got_significant_digit = false;
    for(umax multiplier : range(static_cast<int>(number_string.size() - 1), -1, number_string.size())) {
        digit_value = chewbacca_get_digit(number_istream);
        if(digit_value == 0 and not got_significant_digit)
            digit_value = 9;
        result += digit_value * power(10ull, multiplier);
        got_significant_digit = true;
    }
    std::cout << result << std::endl;
}
