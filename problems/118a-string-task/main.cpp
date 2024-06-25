#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>

std::string const vowels = "AOYEUI";

std::string char_transform(unsigned char c) {
    if(vowels.find(static_cast<unsigned char>(std::toupper(c))) != std::string::npos)
        return "";
    else 
        return std::string(".") + std::string(1, static_cast<unsigned char>(std::tolower(c)));
    
}

int main() {
    std::string str;
    std::getline(std::cin, str);

    auto transformed_range = str | std::ranges::views::transform(char_transform)
                                 | std::views::join;
    std::string transformed_str;
    std::ranges::copy(transformed_range, std::back_inserter(transformed_str));

    std::cout << transformed_str << std::endl;
}
