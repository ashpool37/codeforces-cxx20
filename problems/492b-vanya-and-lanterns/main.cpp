#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    unsigned lantern_count, street_length;
    std::cin >> lantern_count >> street_length;

    std::vector<unsigned> lanterns;
    std::copy_n(std::istream_iterator<unsigned>(std::cin), lantern_count, std::back_inserter(lanterns));

    std::ranges::sort(lanterns);

    double max_unlit_distance = 0.0;
    max_unlit_distance = static_cast<double>(std::max(max_unlit_distance,
                                             static_cast<double>(lanterns.at(0) - 0u)));
    max_unlit_distance = static_cast<double>(std::max(max_unlit_distance,
                                             static_cast<double>(street_length - lanterns[lanterns.size() - 1u])));

    for(auto lantern = lanterns.begin() + 1; lantern != lanterns.end(); lantern++) {
        max_unlit_distance = std::max(max_unlit_distance, static_cast<double>(*lantern - *(lantern-1)) / 2.0);
    }

    std::cout << std::fixed << max_unlit_distance << std::endl;
}
