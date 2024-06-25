#include <algorithm>
#include <iostream>
#include <ranges>
#include <set>

int main() {
    unsigned level_count;
    std::cin >> level_count;

    unsigned little_x_level_count;
    std::set<unsigned> little_x_levels;
    std::cin >> little_x_level_count;
    // std::ranges::copy(std::ranges::istream_view<unsigned>(std::cin) | std::views::take(little_x_level_count),
    //                   std::inserter(little_x_levels, little_x_levels.begin()));
    //// doesn't work correctly for some reason
    for(unsigned _ = little_x_level_count; _--;) {
        unsigned level;
        std::cin >> level;
        little_x_levels.insert(level);
    }

    unsigned little_y_level_count;
    std::set<unsigned> little_y_levels;
    std::cin >> little_y_level_count;
    // std::ranges::copy(std::ranges::istream_view<unsigned>(std::cin) | std::views::take(little_y_level_count),
    //                   std::inserter(little_y_levels, little_y_levels.begin()));
    for(unsigned _ = little_y_level_count; _--;) {
        unsigned level;
        std::cin >> level;
        little_y_levels.insert(level);
    }

    std::set<unsigned> both_levels;
    std::ranges::set_union(little_x_levels, little_y_levels, std::inserter(both_levels, both_levels.begin()));

    std::cout << (both_levels.size() == level_count ? "I become the guy." : "Oh, my keyboard!") << std::endl;
}
