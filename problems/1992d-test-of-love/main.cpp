#include <iostream>
#include <unordered_map>
#include <vector>

enum SectionType {
    LOG_OR_GROUND,
    WATER,
    CROCODILE,
};

struct State {
    size_t position;
    unsigned swim_remaining;

    bool operator==(State const& other) const {
        return position == other.position and swim_remaining == other.swim_remaining;
    }
};

template<>
struct std::hash<State> {
    std::size_t operator()(State const& s) const {
        return std::hash<unsigned>()(s.position) ^ (std::hash<unsigned>()(s.swim_remaining) << 1);
    }
};

class PathFinder {
    std::vector<SectionType> const river;
    unsigned const max_jump_length;
    std::unordered_map<State, bool> cached_results;
public:
    PathFinder(std::vector<SectionType>&& river, unsigned max_jump_length) 
        : river(river), max_jump_length(max_jump_length)
    {};

    bool find_path(State state) {
        auto cached_result_it = cached_results.find(state);
        if(cached_result_it != cached_results.end())
            return cached_result_it->second;

        if(state.position >= river.size() - 1) return true;
        
        SectionType section = river.at(state.position);
        
        bool result = false;
        if(section == CROCODILE)
            result = false;
        else if(section == WATER)
            result = state.swim_remaining > 0 
                     and find_path({.position = state.position + 1,
                                    .swim_remaining = state.swim_remaining - 1});
        else {
            for(unsigned jump_length = max_jump_length; jump_length >= 1; jump_length--) {
                if(find_path({.position = state.position + jump_length,
                              .swim_remaining = state.swim_remaining})) {
                    result = true;
                    break;
                }
            }
        }
        cached_results.insert({state, result});
        return result;
    }
};


int main() {
    unsigned test_count;
    std::cin >> test_count;

    while(test_count--) {
        unsigned river_length, max_jump_length, total_swim_length;
        std::cin >> river_length >> max_jump_length >> total_swim_length;
        std::cin.ignore(1, '\n');

        std::vector<SectionType> river;
        river.push_back(LOG_OR_GROUND);
        while(river_length--) {
            char river_section;
            std::cin >> river_section;
            if(river_section == 'W') river.push_back(WATER);
            else if (river_section == 'C') river.push_back(CROCODILE);
            else river.push_back(LOG_OR_GROUND);
        }
        river.push_back(LOG_OR_GROUND);

        PathFinder path_finder(std::move(river), max_jump_length);
        bool result = path_finder.find_path({.position = 0, .swim_remaining = total_swim_length});
        std::cout << (result ? "YES" : "NO") << std::endl;
    }
}
