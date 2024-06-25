#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    unsigned column_count;
    std::cin >> column_count;

    std::vector<unsigned> columns;
    columns.reserve(column_count);
    std::ranges::copy(std::ranges::istream_view<unsigned>(std::cin),
                      std::back_inserter(columns));
    std::ranges::sort(columns);
    for(auto x : (columns | std::views::take(column_count - 1)))
        std::cout << x << " ";
    std::cout << columns[column_count - 1] << std::endl;
}
