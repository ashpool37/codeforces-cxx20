// Problem: 1791A. Codeforces Checking
// Problem statement: https://codeforces.com/problemset/problem/1791/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <string>
#include <algorithm>

std::string const haystack = "codeforces";

int main() {
    unsigned test_count;
    std::cin >> test_count;
    std::cin.ignore(1, '\n');

    while(test_count--) {
        char needle;
        std::cin >> needle;
        std::cin.ignore(1, '\n');

        bool contains = std::ranges::find(haystack, needle) != haystack.end();

        std::cout << (contains ? "YES" : "NO") << std::endl;
    }
}
