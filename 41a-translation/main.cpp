#include <iostream>
#include <string>
#include <algorithm>
#include <ranges>

bool is_reverse(const std::string& str1, const std::string& str2) {
    return str1.size() == str2.size() && std::ranges::equal(str1, str2 | std::views::reverse);
}

int main() {
    std::string str1;
    std::string str2;

    std::getline(std::cin, str1);
    std::getline(std::cin, str2);

    if (is_reverse(str1, str2)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
