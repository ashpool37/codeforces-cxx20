#include <algorithm>
#include <iostream>
#include <string>

char tolower_c (char c) {
    return static_cast<char>(std::tolower(static_cast<int>(c)));
}

int main() {
    unsigned test_count;
    std::cin >> test_count;
    std::cin.ignore(1, '\n');

    while(test_count--) {
        std::string str, str_lower;
        std::getline(std::cin, str);
        std::ranges::transform(str, std::back_inserter(str_lower), tolower_c);
        std::cout << (str_lower == "yes" ? "YES" : "NO") << std::endl;
    }
}
