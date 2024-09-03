// Problem: 2009C. The Legend of Freya the Frog
// Problem statement: https://codeforces.com/problemset/problem/2009/C?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

/* #region templates */

#include <cstddef>
#include <iostream>
#include <charconv>
#include <ranges>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <limits>
#include <iterator>
#include <unordered_set>

using ll = long long;
using ull = unsigned long long;

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
auto counted(T start, std::size_t count, T step = 1) {
    using namespace std::ranges::views;
    return iota(0u, count) | transform([=](std::size_t i){ return start + step * static_cast<T>(i); });
}

auto counted(std::size_t count) {
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

bool space_p(char ch)
{
    return static_cast<bool>(std::isspace(static_cast<unsigned char>(ch)));
}

void istream_skip_ws(std::istream& input_stream) {
    while(space_p(input_stream.peek())) input_stream.get();
}

void cin_skip_ws() {
    istream_skip_ws(std::cin);
}

template<std::integral T, std::output_iterator<T> OutputIt>
void generate_multiples(T limit, T base, OutputIt it) {
    T multiple;
    for(T i = 2; (multiple = base * i) <= limit; i++) {
        *it = multiple;
        it++;
    }
}

template<std::integral T>
std::vector<T> multiples_to_vector(T limit, T base, bool include_base = true) {
    std::vector<T> result;
    if(include_base) result.push_back(base);
    generate_multiples(limit, base, std::back_inserter(result));
    return result;
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

template<std::integral T>
std::vector<T> primes_to_vector(T limit) {
    std::vector<T> result;
    generate_primes(limit, std::back_inserter(result));
    return result;
}

template <typename T>
concept Summable = requires(T lhs, T rhs) {
    { lhs + rhs };
};

template<std::ranges::range R>
requires Summable<std::ranges::range_value_t<R>>
auto sum(R const& range) {
    return std::ranges::fold_left(range, 0, std::plus());
}

/* #endregion */

#include <utility>

enum class Facing : bool {
    X,
    Y,
};

void turn(Facing& facing) {
    if(facing == Facing::X) facing = Facing::Y;
    else facing = Facing::X;
}

unsigned ceil_div(unsigned lhs, unsigned rhs) {
    if(rhs == 0u) throw std::runtime_error("Division by zero");
    return (lhs + rhs - 1u) / rhs;
}

int main() {
    unsigned const test_count = from_cin();
    for(auto const _ : counted(test_count)) {
        auto const [dest_x, dest_y, facing_start] = [](){
            unsigned dest_x_ = from_cin();
            unsigned dest_y_ = from_cin();
            Facing facing_start_ = Facing::X;
            if(dest_x_ > dest_y_) {
                std::swap(dest_x_, dest_y_);
                facing_start_ = Facing::Y;
            }
            return std::make_tuple(dest_x_, dest_y_, facing_start_);
        }();
        unsigned const max_jump = from_cin();

        unsigned const full_square_count = dest_x / max_jump;
        unsigned const total_moves = [=]() {
            unsigned result = full_square_count * 2u;
            unsigned x = full_square_count * max_jump;
            unsigned y = x;
            Facing facing = facing_start;
            auto const dx = [&x = std::as_const(x), dest_x]() { return dest_x - x; };
            auto const dy = [&y = std::as_const(y), dest_y]() { return dest_y - y; };

            // 0 <= dx < max_jump
            // 0 <= dx <= dy

            if(dx() != 0u) {
                if(facing == Facing::X) {
                    x = dest_x;
                    turn(facing);
                    result += 1u;
                }
                else {
                    y += std::min(dy(), max_jump);
                    x = dest_x;
                    result += 2u;
                }
            }

            // dx = 0

            if(dy() == 0u) return result;

            unsigned const y_jumps_remaining = ceil_div(dy(), max_jump);
            if(facing == Facing::X) result += y_jumps_remaining * 2u;
            else result += y_jumps_remaining * 2u - 1u;

            return result;
        }();

        std::cout << total_moves << std::endl;
    }
}
