// Problem: 1791B. Following Directions
// Problem statement: https://codeforces.com/problemset/problem/1791/B?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

/* #region templates */

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

enum class Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT,
};

class Vec2D {
    static std::pair<int, int> xy_components(Direction direction) {
        switch(direction) {
            case Direction::UP: return {0, 1}; break;
            case Direction::RIGHT: return {1, 0}; break;
            case Direction::DOWN: return {0, -1}; break;
            case Direction::LEFT: return {-1, 0}; break;
        }
    }
public:
    int x;
    int y;

    Vec2D(int x, int y)
        : x(x), y(y)
    {}

    Vec2D(std::pair<int, int> components)
        : x(components.first), y(components.second)
    {}

    Vec2D(Direction const& direction)
        : Vec2D(xy_components(direction))
    {}

    Vec2D operator+(Vec2D const& rhs) const {
        return Vec2D(x + rhs.x, y + rhs.y);
    }

    Vec2D operator+=(Vec2D const& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    bool operator==(Vec2D const& rhs) const {
        return x == rhs.x and y == rhs.y;
    }
};

std::istream& operator>>(std::istream& input_stream, Direction& direction) {
    istream_skip_ws(input_stream);
    switch(input_stream.peek()) {
        case 'U':
            direction = Direction::UP;
            input_stream.get();
            break;
        case 'R':
            direction = Direction::RIGHT;
            input_stream.get();
            break;
        case 'D':
            direction = Direction::DOWN;
            input_stream.get();
            break;
        case 'L':
            direction = Direction::LEFT;
            input_stream.get();
            break;
        default:
            input_stream.setstate(std::ios::failbit);
            break;
    }
    return input_stream;
}

int main() {
    unsigned const test_count = from_cin();
    for(auto const _ : counted(test_count)) {
        unsigned const move_count = from_cin();
        Vec2D position(0, 0);
        Vec2D const candy_position(1, 1);
        bool const candy_reached = [&position, move_count, candy_position]() {
            for(auto const _ : counted(move_count)) {
                Direction dir = from_cin();
                Vec2D vec = Vec2D(dir);
                position += vec;
                if(position == candy_position) return true;
            }
            return false;
        }();
        cin_skip_line();
        std::cout << (candy_reached ? "YES" : "NO") << std::endl;
    }
}