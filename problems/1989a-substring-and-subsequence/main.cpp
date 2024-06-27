#include <iostream>
#include <ranges>

template<std::ranges::input_range R1, std::ranges::input_range R2>
size_t subsequence_prefix_length(R1 const& text, R2 const& pattern) {
    auto pattern_it = pattern.begin();
    size_t result = 0;
    for(auto c : text) {
        if(c == *pattern_it) {
            result++;
            pattern_it++;
        }
    }
    return result;
}

template<std::ranges::input_range R1, std::ranges::input_range R2>
size_t partial_subsequence_length(R1 const& text, R2 const& pattern) {
    size_t max_length = 0;
    for(size_t i = 0; i < pattern.size(); i++) {
        max_length = std::max(max_length, subsequence_prefix_length(text, pattern | std::ranges::views::drop(i)));
    }
    return max_length;
}

int main() {
    unsigned test_count;
    std::cin >> test_count;
    std::cin.ignore(1, '\n');

    for(auto _ = test_count; _--;) {
        std::string a, b;
        std::getline(std::cin, a);
        std::getline(std::cin, b);

        std::cout << a.size() + (b.size() - partial_subsequence_length(a, b)) << std::endl;
    }
}
