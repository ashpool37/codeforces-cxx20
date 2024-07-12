// Problem: 706B. Interesting drink
// Problem statement: https://codeforces.com/problemset/problem/706/B?locale=en
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
    unsigned shop_count;
    std::cin >> shop_count;

    std::vector<unsigned> shop_prices;
    get_from_cin(shop_prices, shop_count);
    std::ranges::sort(shop_prices);

    unsigned day_count;
    std::cin >> day_count;

    while(day_count--) {
        unsigned balance;
        std::cin >> balance;

        auto upper_bound = std::ranges::upper_bound(shop_prices, balance);
        auto available_shop_count = upper_bound - shop_prices.begin();

        std::cout << available_shop_count << std::endl;
    }
}
