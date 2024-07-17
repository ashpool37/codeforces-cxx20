// Problem: 313A. Ilya and Bank Account
// Problem statement: https://codeforces.com/problemset/problem/313/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <cmath>

unsigned remove_digit(unsigned number, unsigned digit) {
    unsigned result = 0;
    unsigned multiplier = 1;
    unsigned current_digit_position = 0;

    while (number > 0) {
        unsigned current_digit = number % 10;
        number /= 10;

        if (current_digit_position != digit) {
            result += current_digit * multiplier;
            multiplier *= 10;
        }

        current_digit_position++;
    }

    return result;
}

int main() {
    int balance;
    std::cin >> balance;

    if(balance >= 0) std::cout << balance << std::endl;
    else {
        unsigned debt_amount = std::abs(balance);
        debt_amount = std::min(remove_digit(debt_amount, 0), remove_digit(debt_amount, 1));
        std::cout << -1 * static_cast<int>(debt_amount) << std::endl;
    }
}
