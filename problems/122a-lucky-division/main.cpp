#include <iostream>
#include <algorithm>
#include <ranges>

bool is_lucky_digit(char c) {
    return c == '4' or c == '7';
}

bool is_lucky_number(unsigned int x) {
    std::string string_repr = std::to_string(x);
    return std::ranges::all_of(string_repr, is_lucky_digit);
}

int main() {
    unsigned number;
    std::cin >> number;
    
    bool nearly_lucky = std::ranges::any_of(std::views::iota(1u, number + 1)
                                            | std::views::filter(is_lucky_number), 
                                            [number](unsigned i) { return number % i == 0; });

    std::cout << (nearly_lucky ? "YES" : "NO") << std::endl;
}
