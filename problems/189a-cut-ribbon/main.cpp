#include <algorithm>
#include <iostream>
#include <array>
#include <unordered_map>
#include <iterator>
#include <optional>

unsigned const allowed_piece_length_count = 3;

class RibbonCutFinder {
    std::array<unsigned, allowed_piece_length_count> const allowed_piece_lengths;
    std::unordered_map<unsigned, std::optional<unsigned>> cached_results;
public:
    RibbonCutFinder(std::array<unsigned, allowed_piece_length_count> allowed_piece_lengths)
        : allowed_piece_lengths(allowed_piece_lengths)
    {}

    std::optional<unsigned> maximize_pieces(unsigned ribbon_length) {
        if(ribbon_length == 0u) return 0u;

        auto cached_result_it = cached_results.find(ribbon_length);
        if(cached_result_it != cached_results.end()) 
            return cached_result_it->second;
        
        std::array<std::optional<unsigned>, allowed_piece_length_count> try_cut_results;
        try_cut_results.fill(std::nullopt);
        auto result_it = try_cut_results.begin();

        for(unsigned piece_length : allowed_piece_lengths) {
            if(piece_length <= ribbon_length) {
                auto try_cut_result = maximize_pieces(ribbon_length - piece_length);
                if(try_cut_result) {
                    *result_it = 1 + try_cut_result.value();
                    result_it++;
                }
            }
        }

        std::optional<unsigned> result = std::nullopt;
        if(std::ranges::any_of(try_cut_results, [](auto v) { return v.has_value(); })) {
            result = std::ranges::max(try_cut_results);
        }
        cached_results.insert({ribbon_length, result});
        return result;
    }
};

int main() {
    unsigned ribbon_length;
    std::cin >> ribbon_length;

    std::array<unsigned, allowed_piece_length_count> allowed_piece_lengths;
    std::copy_n(std::istream_iterator<unsigned>(std::cin), allowed_piece_length_count,
                allowed_piece_lengths.begin());
    
    RibbonCutFinder cut_finder(allowed_piece_lengths);
    unsigned max_pieces = cut_finder.maximize_pieces(ribbon_length).value();
    
    std::cout << max_pieces << std::endl;
}
