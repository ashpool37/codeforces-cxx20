// Problem: 431A. Black Square
// Problem statement: https://codeforces.com/problemset/problem/431/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <algorithm>
#include <iostream>
#include <charconv>
#include <array>
#include <iterator>
#include <string>
#include <sstream>

unsigned digit_to_unsigned(char c) {
    char cs[2] = "\0";
    cs[0] = c;
    unsigned result;
    std::from_chars(cs, cs+1, result);
    return result;
}

int main() {
    std::array<unsigned, 4> calories;
    std::copy_n(std::istream_iterator<unsigned>(std::cin), 4, calories.begin());
    std::cin.ignore(1, '\n');

    std::string digits;
    std::getline(std::cin, digits);
    std::istringstream digits_stream(digits);

    unsigned calories_total = 0;
    char digit;
    while(digits_stream >> digit) {
        calories_total += calories.at(digit_to_unsigned(digit) - 1);
    }
    std::cout << calories_total << std::endl;
}
