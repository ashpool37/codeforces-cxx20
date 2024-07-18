// Problem: 1850A. To My Critics
// Problem statement: https://codeforces.com/problemset/problem/1850/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        unsigned digit1, digit2, digit3;
        std::cin >> digit1 >> digit2 >> digit3;

        if(digit1 + digit2 >= 10
           or digit1 + digit3 >= 10
           or digit2 + digit3 >= 10)
            std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
}
