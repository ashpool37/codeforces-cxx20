// Problem: 579A. Raising Bacteria
// Problem statement: https://codeforces.com/problemset/problem/579/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <bitset>
#include <climits>

int main() {
    unsigned final_bacterium_count;
    size_t const bit_count = sizeof(unsigned) * CHAR_BIT;
    std::cin >> final_bacterium_count;

    std::bitset<bit_count> bits(final_bacterium_count);
    unsigned bits_on = 0;
    for(size_t i = 0; i < bit_count; i++) {
        if(bits.test(i)) bits_on++;
    }

    std::cout << bits_on << std::endl;
}
