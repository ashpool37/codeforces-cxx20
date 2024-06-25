#include <algorithm>
#include <iostream>

bool is_lucky_digit(char c) {
    return c == '4' or c == '7';
}

bool is_lucky_number(unsigned int x) {
    std::string string_repr = std::to_string(x);
    return std::all_of(string_repr.begin(), string_repr.end(), is_lucky_digit);
}

int main() {
    std::string digits;
    std::getline(std::cin, digits);
    size_t happy_digit_count = std::count_if(digits.begin(), digits.end(), is_lucky_digit);
    std::cout << (is_lucky_number(happy_digit_count) ? "YES" : "NO") << std::endl;
}
