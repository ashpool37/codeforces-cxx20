#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    unsigned test_count;
    std::cin >> test_count;

    for(unsigned _ = test_count; _--;) {
        unsigned book_count;
        std::cin >> book_count;
        std::vector<unsigned> page_counts;
        page_counts.reserve(book_count);

        for(unsigned _ = book_count; _--;) {
            unsigned page_count;
            std::cin >> page_count;
            page_counts.push_back(page_count);
        }

        std::reverse(page_counts.begin(), page_counts.end());
        std::cout << page_counts[0] + std::ranges::max(page_counts | std::ranges::views::drop(1)) << std::endl;
    }
}
