#include <iostream>
#include <ranges>
#include <set>
#include <algorithm>

int main() {
    std::set<unsigned> horseshoe_colors;
    std::ranges::copy(std::ranges::istream_view<unsigned>(std::cin),
                      std::inserter(horseshoe_colors, horseshoe_colors.begin()));
    std::cout << 4u - horseshoe_colors.size() << std::endl;
}
