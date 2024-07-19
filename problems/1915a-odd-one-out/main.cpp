// Problem: 1915A. Odd One Out
// Problem statement: https://codeforces.com/problemset/problem/1915/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <array>
#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        std::array<unsigned, 3> numbers;
        std::copy_n(std::istream_iterator<unsigned>(std::cin), 3, numbers.begin());
        std::ranges::sort(numbers);

        if(numbers[0] < numbers[1]) std::cout << numbers[0] << std::endl;
        else std::cout << numbers[2] << std::endl;
    }
}
