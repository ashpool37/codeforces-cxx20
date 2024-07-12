// Problem: 1692A. Marathon
// Problem statement: https://codeforces.com/problemset/problem/1692/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>

template<typename T>
void get_from_cin(std::vector<T>& vec, size_t count) {
    std::copy_n(std::istream_iterator<T>(std::cin), count, std::back_inserter(vec));
}

template<typename T, size_t n>
void get_from_cin(std::array<T, n>& arr) {
    std::copy_n(std::istream_iterator<T>(std::cin), n, arr.begin());
}

int main() {
    unsigned test_count = 1;
    std::cin >> test_count;
    while(test_count--) {
        unsigned timur_distance;
        std::cin >> timur_distance;

        std::array<unsigned, 3> participant_distances;
        get_from_cin(participant_distances);

        unsigned ran_more_than_timur_count = 0;
        for(unsigned distance : participant_distances) {
            if(distance > timur_distance) ran_more_than_timur_count++;
        }

        std::cout << ran_more_than_timur_count << std::endl;
    }
}
