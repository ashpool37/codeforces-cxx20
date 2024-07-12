// Problem: 1512A. Spy Detected!
// Problem statement: https://codeforces.com/problemset/problem/1512/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <optional>
#include <utility>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
#include <unordered_map>

template<typename T>
void get_from_cin(std::vector<T>& vec, size_t count) {
    std::copy_n(std::istream_iterator<T>(std::cin), count, std::back_inserter(vec));
}

template<typename T, size_t n>
void get_from_cin(std::array<T, n>& arr) {
    std::copy_n(std::istream_iterator<T>(std::cin), n, arr.begin());
}

struct NumberInfo {
    unsigned count;
    size_t last_seen_position;
};

int main() {
    unsigned test_count = 1;
    std::cin >> test_count;
    while(test_count--) {
        unsigned array_length; 
        std::cin >> array_length;

        std::unordered_map<unsigned, NumberInfo> number_stats;
        auto find_spy = [&number_stats = std::as_const(number_stats)]() -> std::optional<size_t> {
            std::optional<size_t> loner_position;
            bool seen_a_non_loner = false;
            for(auto [_, info] : number_stats) {
                if(info.count == 1) loner_position = info.last_seen_position;
                else if(info.count > 1) seen_a_non_loner = true;
            }
            if(seen_a_non_loner) return loner_position;
            else return std::nullopt;
        };

        auto add_number = [&number_stats](unsigned number, size_t position) -> void {
            auto number_it = number_stats.find(number);
            if(number_it != number_stats.end()) {
                number_it->second.count++;
                number_it->second.last_seen_position = position;
            }
            else number_stats.insert({number, {.count = 1, .last_seen_position = position}});
        };

        std::vector<unsigned> numbers;
        get_from_cin(numbers, array_length);

        for(size_t position = 1; position <= array_length; position++) {
            unsigned number = numbers.at(position - 1);
            add_number(number, position);
            auto spy = find_spy();
            if(spy) {
                std::cout << spy.value() << std::endl;
                break;
            }
        }
    }
}
