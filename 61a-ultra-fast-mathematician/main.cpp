#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <ranges>

int main() {
    std::string a_str, b_str;
    std::getline(std::cin, a_str);
    std::getline(std::cin, b_str);

    std::bitset<100> a(a_str), b(b_str);
    std::bitset<100> result(a ^ b);

    std::string result_str;
    std::ranges::copy(result.to_string() | std::views::drop(100 - a_str.size()),
                      std::back_inserter(result_str));

    std::cout << result_str << std::endl;
}
