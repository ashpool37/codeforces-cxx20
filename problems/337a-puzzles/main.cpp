#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main() {
    unsigned pupil_count, puzzle_count;
    std::cin >> pupil_count >> puzzle_count;

    std::vector<unsigned> puzzle_sizes;
    std::copy_n(std::istream_iterator<unsigned>(std::cin), puzzle_count,
                std::back_inserter(puzzle_sizes));
    
    std::ranges::sort(puzzle_sizes);

    std::deque<unsigned> gift_selection;
    std::copy_n(puzzle_sizes.begin(), pupil_count, std::back_inserter(gift_selection));

    unsigned min_difference = gift_selection.back() - gift_selection.front();
    for(auto puzzle_size : puzzle_sizes | std::ranges::views::drop(pupil_count)) {
        gift_selection.push_back(puzzle_size);
        gift_selection.pop_front();
        min_difference = std::min(min_difference, gift_selection.back() - gift_selection.front());
    }

    std::cout << min_difference << std::endl;
}
