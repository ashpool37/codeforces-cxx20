// Problem: 489C. Given Length and Sum of Digits...
// Problem statement: https://codeforces.com/problemset/problem/489/C?locale=en
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

template<std::unsigned_integral T>
T ceil_div(T lhs, T rhs) {
    if(rhs == 0u) throw std::runtime_error("Division by zero");
    return (lhs + rhs - 1u) / rhs;
}

/* #endregion */

std::optional<std::vector<unsigned>> sum_to_digits
        (unsigned const number_length, unsigned const sum_of_digits) {
    if(number_length * 9u < sum_of_digits) return std::nullopt;
    if(sum_of_digits == 0u and number_length != 1u) return std::nullopt;

    std::vector<unsigned> result;
    result.reserve(number_length);
    for(unsigned i = 1; i * 9u <= sum_of_digits; i++) {
        result.push_back(9u);
    }
    if(result.size() < number_length) result.push_back(sum_of_digits % 9u);
    while(result.size() < number_length) result.push_back(0u);
    return result;
}

enum class MakeSmallestNumberResult {
    SUCCESS,
    FAILURE,
};

MakeSmallestNumberResult make_smallest_number(std::vector<unsigned>& digits) {
    std::ranges::sort(digits);
    if(digits[0] == 0u) {
        auto const non_zero_it = std::ranges::find_if(digits, [](unsigned x) { return x != 0u; });
        if(non_zero_it != digits.end()) {
            (*non_zero_it)--;
            digits[0] = 1u;
            return MakeSmallestNumberResult::SUCCESS;
        }
        else return MakeSmallestNumberResult::FAILURE;
    }
    return MakeSmallestNumberResult::SUCCESS;
}

std::string digits_to_string(std::vector<unsigned> const& digits) {
    return std::views::transform(digits, unsigned_to_digit) | std::ranges::to<std::string>();
}

int main() {
    unsigned const number_length = from_cin();
    unsigned const sum_of_digits = from_cin();

    auto const biggest_number_digits = sum_to_digits(number_length, sum_of_digits);
    if(not biggest_number_digits.has_value()) {
        std::cout << "-1 -1" << std::endl;
    }
    else {
        auto const [smallest_number_digits, make_smallest_number_result] =
                [&biggest_number_digits]() {
            std::vector<unsigned> smallest_number_digits_ = *biggest_number_digits;
            auto const make_smallest_number_result_ = make_smallest_number(smallest_number_digits_);
            return std::make_pair(smallest_number_digits_, make_smallest_number_result_);
        }();
        std::string biggest_number_str = digits_to_string(*biggest_number_digits);
        std::string smallest_number_str = make_smallest_number_result == MakeSmallestNumberResult::SUCCESS
            ? digits_to_string(smallest_number_digits)
            : biggest_number_str;
        std::cout << smallest_number_str << " " << biggest_number_str << std::endl;
    }
}
