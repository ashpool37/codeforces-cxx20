#include <algorithm>
#include <iostream>
#include <set>
#include <string>

int main() {
    std::string letters_written_down;
    std::getline(std::cin, letters_written_down);

    std::set<char> letters;
    std::ranges::copy_if(letters_written_down, std::inserter(letters, letters.begin()),
                         [](char c) { return static_cast<bool>(std::isalpha(static_cast<int>(c))); });

    std::cout << letters.size() << std::endl;
}
