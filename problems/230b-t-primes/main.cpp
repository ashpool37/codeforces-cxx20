#include <iostream>
#include <cstdint>
#include <unordered_set>
#include <iterator>

using ull = std::uintmax_t;

template<std::output_iterator<ull> OutputIt>
void generate_multiples(ull limit, ull base, OutputIt it) {
    ull multiple;
    for(ull i = 2; (multiple = base * i) <= limit; i++) {
        *it = multiple;
        it++;
    }
}

template<std::output_iterator<ull> OutputIt>
void generate_prime_squares(ull limit, OutputIt it) {
    std::unordered_set<ull> composite;
    for(ull i = 2; i <= limit; i++) {
        if(not composite.contains(i)) {
            *it = i * i;
            it++;
            if(i * i <= limit) generate_multiples(limit, i, std::inserter(composite, composite.begin()));
        }
    }
}

int main() {
    unsigned test_count;
    std::cin >> test_count;

    std::unordered_set<ull> prime_squares;
    generate_prime_squares(1000000, std::inserter(prime_squares, prime_squares.begin()));

    while(test_count--) {
        ull number;
        std::cin >> number;
        std::cout << (prime_squares.contains(number) ? "YES" : "NO") << std::endl;
    }
}
