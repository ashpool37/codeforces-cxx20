#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

unsigned const dragons_hit_method_count = 4;

template<typename T>
T lcm(std::initializer_list<T> values) {
    T init = *values.begin();
    return std::accumulate(values.begin() + 1, values.end(), init, std::lcm<T, T>);
}

int main() {
    std::vector<unsigned> dragon_hit_methods;
    unsigned dragons_total;

    std::copy_n(std::istream_iterator<unsigned>(std::cin),
                dragons_hit_method_count,
                std::back_inserter(dragon_hit_methods));
    std::cin >> dragons_total;

    unsigned dragon_hit_count = 0;
    dragon_hit_count += dragons_total / dragon_hit_methods[0];
    dragon_hit_count += dragons_total / dragon_hit_methods[1];
    dragon_hit_count += dragons_total / dragon_hit_methods[2];
    dragon_hit_count += dragons_total / dragon_hit_methods[3];
    dragon_hit_count -= dragons_total / lcm({dragon_hit_methods[0], dragon_hit_methods[1]});
    dragon_hit_count -= dragons_total / lcm({dragon_hit_methods[0], dragon_hit_methods[2]});
    dragon_hit_count -= dragons_total / lcm({dragon_hit_methods[0], dragon_hit_methods[3]});
    dragon_hit_count -= dragons_total / lcm({dragon_hit_methods[1], dragon_hit_methods[2]});
    dragon_hit_count -= dragons_total / lcm({dragon_hit_methods[1], dragon_hit_methods[3]});
    dragon_hit_count -= dragons_total / lcm({dragon_hit_methods[2], dragon_hit_methods[3]});
    dragon_hit_count += dragons_total / lcm({dragon_hit_methods[0], dragon_hit_methods[1],
                                             dragon_hit_methods[2]});
    dragon_hit_count += dragons_total / lcm({dragon_hit_methods[0], dragon_hit_methods[1],
                                             dragon_hit_methods[3]});
    dragon_hit_count += dragons_total / lcm({dragon_hit_methods[0], dragon_hit_methods[2],
                                             dragon_hit_methods[3]});
    dragon_hit_count += dragons_total / lcm({dragon_hit_methods[1], dragon_hit_methods[2],
                                             dragon_hit_methods[3]});
    dragon_hit_count -= dragons_total / lcm({dragon_hit_methods[0], dragon_hit_methods[1],
                                             dragon_hit_methods[2], dragon_hit_methods[3]});
    std::cout << dragon_hit_count << std::endl;
    return 0;
}
