#include <iostream>
#include <utility>

int main() {
    unsigned test_count;
    std::cin >> test_count;

    for(unsigned _ = test_count; _--;) {
        std::pair<unsigned, unsigned> score_before;
        std::pair<unsigned, unsigned> score_after;

        std::cin >> score_before.first >> score_before.second;
        std::cin >> score_after.first >> score_after.second;

        if((score_before.first < score_before.second and score_after.first > score_after.second)
           or (score_before.first > score_before.second and score_after.first < score_after.second))
           std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;
    }
}
