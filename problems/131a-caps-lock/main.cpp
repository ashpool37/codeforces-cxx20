#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>

namespace r = std::ranges;
namespace v = r::views;

bool isupper_c(char c) {
    return static_cast<bool>(std::isupper(static_cast<int>(c)));
}
bool islower_c(char c) {
    return static_cast<bool>(std::islower(static_cast<int>(c)));
}
char tolower_c(char c) {
    return static_cast<char>(std::tolower(static_cast<int>(c)));
}
char toupper_c(char c) {
    return static_cast<char>(std::toupper(static_cast<int>(c)));
}

template<r::input_range R>
bool all_upper(R&& range) {
    return r::all_of(range, isupper_c);
}
template<r::input_range R>
bool all_lower(R&& range) {
    return r::all_of(range, islower_c);
}
char invert_case(char c) {
    if(isupper_c(c)) return tolower_c(c);
    else return toupper_c(c);
}

int main() {
    std::string word;
    std::getline(std::cin, word);

    auto head = word | v::take(1);
    auto tail = word | v::drop(1);

    std::string result;
    if((all_upper(head) and tail.empty())
       or all_upper(tail)) {
       r::transform(word, std::back_inserter(result), invert_case);
    }
    else result = word;

    std::cout << result << std::endl;
}
