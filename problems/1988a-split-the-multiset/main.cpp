// Problem: 1988A. Split the Multiset
// Problem statement: https://codeforces.com/problemset/problem/1988/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <cmath>
#include <iostream>

int main() {
    unsigned test_count;
    std::cin >> test_count;
    while(test_count--) {
        unsigned target_multiset_size, insert_count;
        std::cin >> target_multiset_size >> insert_count;

        unsigned ones_created_per_turn = insert_count - 1;
        unsigned ones_to_create = target_multiset_size - 1;
        unsigned turns = static_cast<unsigned>(std::ceil(static_cast<double>(ones_to_create) 
                                                         / static_cast<double>(ones_created_per_turn)));
        
        std::cout << turns << std::endl;
    }
}
