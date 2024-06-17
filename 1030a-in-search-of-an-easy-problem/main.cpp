#include <iostream>
#include <algorithm>
#include <iterator>

int main() {
    unsigned respondent_count;
    std::cin >> respondent_count;

    bool all_easy = std::ranges::none_of(std::istream_iterator<unsigned>(std::cin),
                                         std::istream_iterator<unsigned>(),
                                         [](unsigned x) { return x == 1; });
    std::cout << (all_easy? "EASY" : "HARD") << std::endl;
}
