// Problem: 2000D. Right Left Wrong
// Problem statement: https://codeforces.com/problemset/problem/2000/D?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

/* #region templates */

#include <iostream>
#include <charconv>
#include <ranges>
#include <stdexcept>
#include <type_traits>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <limits>
#include <iterator>
#include <unordered_set>

using umax = std::uintmax_t;

unsigned digit_to_unsigned(char c) {
    char cs[2] = "\0";
    cs[0] = c;
    unsigned result;
    std::from_chars(cs, cs+1, result);
    return result;
}

char unsigned_to_digit(unsigned n) {
    char cs[2] = "\0";
    std::to_chars(cs, cs+1, n);
    return cs[0];
}

template<std::integral T>
auto counted(T start, size_t count, T step = 1) {
    using namespace std::ranges::views;
    return iota(0u, count) | transform([=](size_t i){ return start + step * static_cast<T>(i); });
}

auto counted(size_t count) {
    return counted(0ull, count, 1ull);
}

template<std::integral BaseT, std::integral ExponentT>
auto power(BaseT base, ExponentT exponent) {
    std::common_type_t<BaseT, ExponentT> result = 1;
    while(exponent--) result *= base;
    return result;
}

template <typename T>
concept ReadableFromStream = requires(std::istream is, T value) {
    { is >> value };
};

class FromIstreamHelper {
    std::istream& input_stream;
    std::optional<std::size_t> count;

    FromIstreamHelper(FromIstreamHelper const&) = delete;
    FromIstreamHelper(FromIstreamHelper&&) = delete;
    FromIstreamHelper& operator=(FromIstreamHelper const&) = delete;
    FromIstreamHelper& operator=(FromIstreamHelper&&) = delete;

    FromIstreamHelper(std::istream& input_stream, std::size_t count)
        : input_stream(input_stream), count(count)
    {}
    FromIstreamHelper(std::istream& input_stream)
        : input_stream(input_stream), count(std::nullopt)
    {}

    friend auto from_istream(std::istream& input_stream);
    friend auto from_istream(std::istream& input_stream, std::size_t count);

public:
    template<ReadableFromStream T>
    operator T() && {
        T result;
        input_stream >> result;
        return result;
    }

    template<ReadableFromStream T>
    operator std::vector<T>() && {
        std::vector<T> result;
        if(count) {
            result.reserve(*count);
            std::copy_n(std::istream_iterator<T>(input_stream), *count, std::back_inserter(result));
        }
        return result;
    }

    template<ReadableFromStream T>
    operator std::list<T>() && {
        std::list<T> result;
        if(count) {
            std::copy_n(std::istream_iterator<T>(input_stream), *count, std::back_inserter(result));
        }
        return result;
    }

    template<ReadableFromStream T, std::size_t array_size>
    operator std::array<T, array_size>() && {
        std::array<T, array_size> result;
        std::copy_n(std::istream_iterator<T>(input_stream), array_size, std::begin(result));
        return result;
    }
};

auto from_istream(std::istream& input_stream) {
    return FromIstreamHelper(input_stream);
}

auto from_istream(std::istream& input_stream, std::size_t count) {
    return FromIstreamHelper(input_stream, count);
}

auto from_cin() {
    return from_istream(std::cin);
}

auto from_cin(std::size_t count) {
    return from_istream(std::cin, count);
}

std::string line_from_istream(std::istream& input_stream) {
    std::string result;
    std::getline(input_stream, result);
    return result;
}

std::string line_from_cin() {
    return line_from_istream(std::cin);
}

void istream_skip_line(std::istream& input_stream) {
    input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void cin_skip_line() {
    istream_skip_line(std::cin);
}

template<std::integral T, std::output_iterator<T> OutputIt>
void generate_multiples(T limit, T base, OutputIt it) {
    T multiple;
    for(T i = 2; (multiple = base * i) <= limit; i++) {
        *it = multiple;
        it++;
    }
}

template<std::integral T, std::output_iterator<T> OutputIt>
void generate_primes(T limit, OutputIt it) {
    std::unordered_set<T> composite;
    for(T i = 2; i <= limit; i++) {
        if(not composite.contains(i)) {
            *it = i;
            it++;
            if(i * i <= limit) generate_multiples(limit, i, std::inserter(composite, composite.begin()));
        }
    }
}

/* #endregion */

enum class Marker {
    LEFT,
    RIGHT,
    USED,
};

std::vector<Marker> get_markers(std::istream& input_stream, std::size_t count) {
    std::vector<Marker> result;
    result.reserve(count);
    auto const char_to_marker = [](char ch) {
        switch(ch) {
            case 'L': return Marker::LEFT; break;
            case 'R': return Marker::RIGHT; break;
            case '.': return Marker::USED; break;
        }
        throw std::runtime_error("Bad char for marker");
    };
    for(auto _ : counted(count)) {
        char const ch = from_istream(input_stream);
        result.push_back(char_to_marker(ch));
    }
    return result;
}

// a STRETCH is a segment simultaneously in points and markers
// a stretch is denoted inclusively as [left_bound; right_bound]
// a stretch A is SANE iff A.left_bound < A.right_bound
// a stretch A is VALID iff A is sane
//                          and markers[A.left_bound] == Marker::Left
//                          and markers[A.right_bound] == Marker::Right
// a stretch A is a PROPER SUBSTRETCH of a stretch B iff
//      stretch A is sane
//      and A.left_bound >= B.left_bound + 1
//      and A.right_bound <= B.right_bound - 1
struct Stretch {
    std::size_t left_bound;
    std::size_t right_bound;

    enum class Sanity {
        SANE,
        NOT_SANE,
    };
    Sanity get_sanity() const {
        return (left_bound < right_bound ? Sanity::SANE : Sanity::NOT_SANE);
    };
    std::optional<Stretch> get_largest_proper_substretch() const {
        if(get_sanity() != Sanity::SANE
           or right_bound - left_bound < 3u)
            return std::nullopt;
        return Stretch{left_bound + 1u, right_bound - 1u};
    };
};

int main() {
    unsigned test_count = from_cin();
    for(auto _ : counted(test_count)) {
        std::size_t const strip_length = from_cin();
        std::vector<umax> const points = from_cin(strip_length);
        cin_skip_line();
        std::vector<Marker> const markers = get_markers(std::cin, strip_length);
        cin_skip_line();

        auto const get_largest_valid_substretch = [&markers](Stretch const& parent_stretch)
                -> std::optional<Stretch> {
            Stretch result = parent_stretch;
            enum class ShrinkResult {
                OK,
                FAILED,
            };
            auto const shrink_left = [&markers, &result] () {
                while(result.get_sanity() == Stretch::Sanity::SANE
                      and result.right_bound - result.left_bound >= 1u) {
                    if(markers[result.left_bound] == Marker::LEFT) return ShrinkResult::OK;
                    else result.left_bound++;
                }
                return ShrinkResult::FAILED;
            };
            auto const shrink_right = [&markers, &result] () {
                while(result.get_sanity() == Stretch::Sanity::SANE
                      and result.right_bound - result.left_bound >= 1u) {
                    if(markers[result.right_bound] == Marker::RIGHT) return ShrinkResult::OK;
                    else result.right_bound--;
                }
                return ShrinkResult::FAILED;
            };

            if(shrink_left() != ShrinkResult::OK) return std::nullopt;
            if(shrink_right() != ShrinkResult::OK) return std::nullopt;
            return result;
        };

        std::vector<umax> const prefix_sums = [&points]() {
            std::vector<umax> result;
            result.reserve(points.size());
            umax running_sum = 0;
            for(std::size_t i : counted(points.size())) {
                running_sum += points[i];
                result[i] = running_sum;
            }
            return result;
        }();
        auto const sum_over_stretch = [&prefix_sums](Stretch const& stretch) {
            return prefix_sums[stretch.right_bound]
                   - (stretch.left_bound == 0uz
                        ? 0ul
                        : prefix_sums[stretch.left_bound - 1uz]);
        };

        umax point_count = 0;
        auto const get_max_points_and_shrink_stretch =
                [&get_largest_valid_substretch, &sum_over_stretch, &point_count]
                (Stretch const& stretch)
                -> std::optional<Stretch> {
            auto valid_substretch = get_largest_valid_substretch(stretch);
            if(valid_substretch.has_value()) {
                point_count += sum_over_stretch(*valid_substretch);
                return valid_substretch->get_largest_proper_substretch();
            }
            else return std::nullopt;
        };

        std::optional<Stretch> stretch = Stretch{0u, strip_length - 1u};
        while((stretch = get_max_points_and_shrink_stretch(*stretch)).has_value());

        std::cout << point_count << std::endl;
    }
}
