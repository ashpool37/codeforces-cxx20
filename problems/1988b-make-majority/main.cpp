// Problem: 1988B. Make Majority
// Problem statement: https://codeforces.com/problemset/problem/1988/B?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        unsigned number_count;
        std::cin >> number_count;

        unsigned zero_count = 0;
        unsigned one_count = 0;
        bool last_zero = false;
        while(number_count--) {
            char number_c;
            std::cin >> number_c;

            switch(number_c) {
                case '0':
                    if(!last_zero) {
                        last_zero = true;
                        zero_count++;
                    }
                    break;
                case '1':
                    last_zero = false;
                    one_count++;
                    break;
            }
        }
        std::cin.ignore(1, '\n');

        std::cout << (one_count > zero_count ? "YES" : "NO") << std::endl;
    }
}
