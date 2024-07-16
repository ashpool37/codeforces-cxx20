// Problem: 1475A. Odd Divisor
// Problem statement: https://codeforces.com/problemset/problem/1475/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <cstdint>

using umax = std::uintmax_t;

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        umax number;
        std::cin >> number;

        while(number > 1 and number % 2 == 0)
            number = number / 2;

        std::cout << (number == 1 ? "NO" : "YES") << std::endl;
    }
}
