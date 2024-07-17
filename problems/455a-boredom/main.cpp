// Problem: 455A. Boredom
// Problem statement: https://codeforces.com/problemset/problem/455/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <cstdint>

template<typename KeyT, typename ValueT>
class DefaultUnorderedMap : public std::unordered_map<KeyT, ValueT> {
public:
    ValueT at_or(KeyT const& key, ValueT const& default_value) {
        auto found_it = this->find(key);
        if(found_it != this->end()) return found_it->second;
        else return default_value;
    }
};

using umap = DefaultUnorderedMap<unsigned, std::uintmax_t>;
using umax = std::uintmax_t;

class GameSolver {
    umap number_counts;
    umax max_number = 0;
    std::unordered_map<size_t, umax> cached_results;

    umax solve_game_internal(size_t different_numbers_left) {
        if(different_numbers_left == 0) return 0;
        if(different_numbers_left == 1) return number_counts.at_or(1, 0);
        auto cached_it = cached_results.find(different_numbers_left);
        if(cached_it != cached_results.end()) return cached_it->second;

        umax try1 = solve_game_internal(different_numbers_left - 1);
        umax try2 = solve_game_internal(different_numbers_left - 2)
                    + number_counts.at_or(different_numbers_left, 0) * different_numbers_left;
        umax result = std::max(try1, try2);
        cached_results.insert(cached_it, std::make_pair(different_numbers_left, result));
        return result;
    }

public:
    GameSolver(std::istream& input_stream, size_t total_number_count)
        : max_number(0)
    {
        while(total_number_count--) {
            umax number;
            input_stream >> number;
            number_counts[number]++;
            if(number > max_number) max_number = number;
        }
    }

    umax solve_game() {
        return solve_game_internal(max_number);
    }
};

int main() {
    size_t number_count;
    std::cin >> number_count;

    GameSolver solver(std::cin, number_count);
    umax result = solver.solve_game();
    std::cout << result;
}
