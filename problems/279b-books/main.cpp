// Problem: 279B. Books
// Problem statement: https://codeforces.com/problemset/problem/279/B?locale=en
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
#include <utility>

class ReadQueue {
    std::queue<unsigned> read_times;
    unsigned total_read_time = 0;

public:
    void push(unsigned read_time) {
        read_times.push(read_time);
        total_read_time += read_time;
    }

    unsigned pop() {
        unsigned result = read_times.front();
        read_times.pop();
        total_read_time -= result;
        return result;
    }

    unsigned read_time() const {
        return total_read_time;
    }

    std::size_t size() const {
        return read_times.size();
    }
};

int main() {
    unsigned book_count = from_cin();
    unsigned time_total = from_cin();
    std::vector<unsigned> read_times = from_cin(book_count);

    ReadQueue read_queue;
    unsigned book_number = 0;
    auto fill_read_queue = [book_count, time_total,
                            &read_queue, &book_number,
                            &read_times = std::as_const(read_times)]() {
        bool any_books_added = false;
        for(; book_number < book_count; book_number++) {
            if(read_queue.read_time() + read_times[book_number] > time_total)
                break;

            any_books_added = true;
            read_queue.push(read_times[book_number]);
        }
        return any_books_added;
    };
    auto any_books_left = [&book_number = std::as_const(book_number), book_count]() {
        return book_number < book_count;
    };

    fill_read_queue();
    size_t read_count_max = read_queue.size();
    while(any_books_left()) {
        if(read_queue.size() > 0) read_queue.pop();
        bool any_books_added = fill_read_queue();
        read_count_max = std::max(read_count_max, read_queue.size());

        if(read_queue.size() == 0 and not any_books_added and any_books_left()) book_number++;
    }

    std::cout << read_count_max << std::endl;
}
