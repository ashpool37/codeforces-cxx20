// Problem: 758A. Holiday Of Equality
// Problem statement: https://codeforces.com/problemset/problem/758/A?locale=en
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
    unsigned citizen_count;
    std::cin >> citizen_count;

    std::vector<unsigned> citizen_balances;
    get_from_cin(citizen_balances, citizen_count);
    std::ranges::sort(citizen_balances, std::greater());

    unsigned max_balance = citizen_balances[0];
    unsigned total_spendings = 0;
    for(auto balance : citizen_balances) {
        total_spendings += max_balance - balance;
    }

    std::cout << total_spendings << std::endl;
}
