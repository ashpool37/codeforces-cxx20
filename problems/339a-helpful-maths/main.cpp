#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <charconv>
#include <vector>
 
template <typename T>
bool vtonum(const std::string_view &view, T& value) {
    if (view.empty()) {
        return false;
    }
     
    const char* first = view.data();
    const char* last = view.data() + view.length();
     
    std::from_chars_result res = std::from_chars(first, last, value);
     
    if (res.ec != std::errc()) {
        return false;
    }
     
    if (res.ptr != last) {
        return false;
    }
     
    return true;
}

int main() {
    std::string expr;
    std::getline(std::cin, expr);

    auto split = expr | std::ranges::views::split('+')
                      | std::ranges::views::transform([](auto rng) {
                        int num;
                        vtonum(std::string_view(rng.data(), rng.size()), num);
                        return num;
                      });
    auto vec = std::vector(split.begin(), split.end());
    std::sort(vec.begin(), vec.end());
    
    std::cout << vec[0];
    for (auto i : vec | std::views::drop(1)) {
        std::cout << "+" << i;
    }
    std::cout << std::endl;
}
