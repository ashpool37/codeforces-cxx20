// Problem: 1367A. Short Substrings
// Problem statement: https://codeforces.com/problemset/problem/1367/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <string>

int main() {
    unsigned test_count;
    std::cin >> test_count;
    std::cin.ignore(1, '\n');

    while(test_count--) {
        std::string encoded_string;
        std::getline(std::cin, encoded_string);

        for(size_t i = 0; i < encoded_string.size(); i+=2) {
            std::cout << encoded_string.at(i);
        }
        std::cout << encoded_string.at(encoded_string.size() - 1) << std::endl;
    }
}
