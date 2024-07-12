// Problem: 1669A. Division?
// Problem statement: https://codeforces.com/problemset/problem/1669/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>

template<typename T>
void get_from_cin(std::vector<T>& vec, size_t count) {
    std::copy_n(std::istream_iterator<T>(std::cin), count, std::back_inserter(vec));
}

template<typename T, size_t n>
void get_from_cin(std::array<T, n>& arr) {
    std::copy_n(std::istream_iterator<T>(std::cin), n, arr.begin());
}

int main() {
    unsigned test_count = 1;
    std::cin >> test_count;
    while(test_count--) {
        int rating;
        std::cin >> rating;

        unsigned division;
        if(rating <= 1399) division = 4;
        else if(rating <= 1599) division = 3;
        else if(rating <= 1899) division = 2;
        else division = 1;

        std::cout << "Division " << division << std::endl;
    }
}
