#include <algorithm>
#include <iostream>
#include <set>
#include <string>

int main() {
    unsigned sentence_length;
    std::cin >> sentence_length;
    std::cin.ignore(1, '\n');

    std::string sentence;
    std::set<char> sentence_chars;
    std::getline(std::cin, sentence);

    std::ranges::transform(sentence, std::inserter(sentence_chars, sentence_chars.begin()),
                           [](char c) { return static_cast<char>(std::tolower(static_cast<int>(c))); });
    
    std::cout << (sentence_chars.size() == 26 ? "YES" : "NO") << std::endl;
}
