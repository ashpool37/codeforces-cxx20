// Problem: 1807A. Plus or Minus
// Problem statement: https://codeforces.com/problemset/problem/1807/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>

int main() {
    unsigned test_count = 1;
    std::cin >> test_count;
    while(test_count--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        std::cout << (a + b == c ? "+" : "-") << std::endl;
    }
}
