#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

bool isupper_wrapper(char c) {
    return std::isupper(static_cast<int>(c)) != 0;
}

char toupper_wrapper(char const& c) {
    return static_cast<unsigned char>(std::toupper(c));
}

char tolower_wrapper(char const& c) {
    return static_cast<unsigned char>(std::tolower(c));
}

int main() {
    std::string word;
    std::getline(std::cin, word);
    
    std::string transformed_word;
    
    size_t upper_count = std::count_if(word.begin(), word.end(), isupper_wrapper);
    if(upper_count == 0 or word.size() / upper_count >= 2) {
        std::transform(word.begin(), word.end(), std::back_inserter(transformed_word), tolower_wrapper);
    }
    else {
        std::transform(word.begin(), word.end(), std::back_inserter(transformed_word), toupper_wrapper);
    }

    std::cout << transformed_word << std::endl;
}
