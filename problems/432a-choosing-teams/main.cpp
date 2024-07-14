// Problem: 432A. Choosing Teams
// Problem statement: https://codeforces.com/problemset/problem/432/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

/* #region(collapsed) templates */

template <typename T>
concept ReadableFromIStream = requires(std::istream input_stream, T value) {
    { input_stream >> value };
};

template<ReadableFromIStream T>
auto from_istream(std::istream& input_stream) {
    T value;
    input_stream >> value;
    return value;
}

template<ReadableFromIStream T, size_t N>
auto array_from_istream(std::istream& input_stream) {
    std::array<T, N> values;
    std::copy_n(std::istream_iterator<T>(input_stream), N, values.begin());
    return values;
}

template<ReadableFromIStream T>
auto vector_from_istream(std::istream& input_stream, size_t count) {
    std::vector<T> values;
    values.reserve(count);
    std::copy_n(std::istream_iterator<T>(input_stream), count, std::back_inserter(values));
    return values;
}

template<ReadableFromIStream T>
auto list_from_istream(std::istream& input_stream, size_t count) {
    std::list<T> values;
    std::copy_n(std::istream_iterator<T>(input_stream), count, std::back_inserter(values));
    return values;
}

template<ReadableFromIStream T>
auto get() { 
    return from_istream<T>(std::cin);
}

template<ReadableFromIStream T>
auto get_vec(size_t count) { 
    return vector_from_istream<T>(std::cin, count);
}

template<ReadableFromIStream T>
auto get_list(size_t count) { 
    return list_from_istream<T>(std::cin, count);
}

template<ReadableFromIStream T, size_t N>
auto get_arr() { 
    return array_from_istream<T, N>(std::cin);
}

/* #endregion */

size_t const team_size = 3u;

int main() {
    auto student_count = get<unsigned>();
    auto target_participation_count = get<unsigned>();
    auto student_participation_counts = get_vec<unsigned>(student_count);

    auto is_student_eligible = [target_participation_count](auto student_participation_count) {
        return 5 - student_participation_count >= target_participation_count;
    };

    size_t eligible_student_count = std::ranges::count_if(student_participation_counts, is_student_eligible);
    std::cout << eligible_student_count / team_size << std::endl;
}
