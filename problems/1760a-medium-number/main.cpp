// Problem: 1760A. Medium Number
// Problem statement: https://codeforces.com/problemset/problem/1760/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <algorithm>
#include <iostream>
#include <array>
#include <iterator>

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        std::array<unsigned, 3> numbers;
        std::copy_n(std::istream_iterator<unsigned>(std::cin), 3, numbers.begin());
        std::ranges::sort(numbers);
        std::cout << numbers.at(1) << std::endl;
    }
}
