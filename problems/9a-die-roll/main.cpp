// Problem: 9A. Die Roll
// Problem statement: https://codeforces.com/problemset/problem/9/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <algorithm>
#include <iostream>

int main() {
    unsigned yakko_roll, wakko_roll;
    std::cin >> yakko_roll >> wakko_roll;

    unsigned max_opponent_roll = std::max(yakko_roll, wakko_roll);
    switch(max_opponent_roll) {
        case 1:
            std::cout << "1/1" << std::endl;
            break;
        case 2:
            std::cout << "5/6" << std::endl;
            break;
        case 3:
            std::cout << "2/3" << std::endl;
            break;
        case 4:
            std::cout << "1/2" << std::endl;
            break;
        case 5:
            std::cout << "1/3" << std::endl;
            break;
        case 6:
            std::cout << "1/6" << std::endl;
            break;
    }
}
