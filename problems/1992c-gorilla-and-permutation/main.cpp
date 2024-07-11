#include <iostream>

int main() {
    unsigned test_count;
    std::cin >> test_count;

    while(test_count--) {
        unsigned permutation_size, g_top_bound;
        [[maybe_unused]] unsigned f_low_bound;
        std::cin >> permutation_size >> g_top_bound >> f_low_bound;

        // sum(f) - sum(g) -> max

        for(unsigned i = permutation_size; i > g_top_bound; i--) {
            std::cout << i << " ";
        }
        for(unsigned i = 1; i < g_top_bound; i++) {
            std::cout << i << " ";
        }
        std::cout << g_top_bound << std::endl;
    }
}
