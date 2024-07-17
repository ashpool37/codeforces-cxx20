// Problem: 1352C. K-th Not Divisible by n
// Problem statement: https://codeforces.com/problemset/problem/1352/C?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <cmath>
#include <iostream>

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        unsigned divisor, count;
        std::cin >> divisor >> count;

        unsigned result = count + (count - 1) / (divisor - 1);

        std::cout << result << std::endl;
    }
}
