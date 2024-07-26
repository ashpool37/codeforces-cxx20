// Problem: 520B. Two Buttons
// Problem statement: https://codeforces.com/problemset/problem/520/B?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

/* #region templates */

#include <iostream>
#include <charconv>
#include <ranges>
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

    operator std::string() && {
        std::string result;
        std::getline(input_stream, result);
        return result;
    }

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

#include <queue>
#include <set>

template<typename T>
concept Hashable = requires(T object1, T object2) {
    { std::hash<T>{}(object1) };
    { object1 == object2 };
};

std::size_t hash_combine() {
    return 0;
}

template<Hashable T1, Hashable... Ts>
std::size_t hash_combine(T1 const& a, Ts const&... args) {
    std::size_t combined_hash = std::hash<T1>{}(a);
    if constexpr (sizeof...(args) > 0) {
        combined_hash += (hash_combine(args...) << 1);
    }
    return combined_hash;
}

struct State {
    unsigned press_count;
    unsigned value_displayed;

    bool operator==(State const& other) const {
        return press_count == other.press_count
               and value_displayed == other.value_displayed;
    }
};

template<>
struct std::hash<State> {
    std::size_t operator() (State const& state) const noexcept {
        return hash_combine(state.press_count, state.value_displayed);
    }
};

template<Hashable T>
class BFS {
    std::queue<T> states;
    std::unordered_set<T> visited;
public:
    void enqueue_unless_visited(T const& state) {
        if(not visited.contains(state)) {
            states.push(state);
            visited.insert(state);
        }
    }

    T dequeue() {
        T result = states.front();
        states.pop();
        return result;
    }

    bool done() const {
        return states.empty();
    }
};

int main() {
    unsigned const initial_value = from_cin();
    unsigned const target_value = from_cin();

    BFS<State> bfs;
    bfs.enqueue_unless_visited({.press_count = 0, .value_displayed = initial_value});
    unsigned press_count_min = std::numeric_limits<unsigned>::max();
    while(not bfs.done()) {
        State state = bfs.dequeue();
        if(state.value_displayed == target_value)
            press_count_min = std::min(press_count_min, state.press_count);
        else if (state.press_count < press_count_min) {
            if(state.value_displayed > target_value)
                bfs.enqueue_unless_visited({.press_count = state.press_count + (state.value_displayed - target_value),
                                            .value_displayed = target_value});
            else {
                if(state.value_displayed > 1)
                    bfs.enqueue_unless_visited({.press_count = state.press_count + 1u,
                                                .value_displayed = state.value_displayed - 1u});
                bfs.enqueue_unless_visited({.press_count = state.press_count + 1u,
                                            .value_displayed = state.value_displayed * 2u});
            }
        }
    }

    std::cout << press_count_min << std::endl;
}
