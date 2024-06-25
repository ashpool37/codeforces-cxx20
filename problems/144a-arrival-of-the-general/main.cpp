#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    unsigned soldier_count;
    std::cin >> soldier_count;

    std::vector<unsigned> soldier_heights;
    std::ranges::copy(std::ranges::istream_view<unsigned>(std::cin), std::back_inserter(soldier_heights));

    std::optional<unsigned> max_height = std::nullopt;
    std::optional<unsigned> min_height = std::nullopt;
    std::optional<unsigned> max_position = std::nullopt;
    std::optional<unsigned> min_position = std::nullopt;

    for(unsigned i = 0; i < soldier_count; i++) {
        unsigned height = soldier_heights[i];
        if(!max_height or *max_height < height) {
            max_height = height;
            max_position = i;
        }
        if(!min_height or *min_height >= height) {
            min_height = height;
            min_position = i;
        }
    }

    unsigned time_elapsed = *max_position + (soldier_count - *min_position - 1);
    if(max_position > min_position) time_elapsed -= 1;

    std::cout << time_elapsed << std::endl;
}
