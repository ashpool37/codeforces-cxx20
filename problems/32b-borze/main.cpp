// Problem: 32B. Borze
// Problem statement: https://codeforces.com/problemset/problem/32/B?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <sstream>

int main() {
    std::string borze_input;
    std::getline(std::cin, borze_input);
    std::istringstream borze_stream(borze_input);

    bool context = false;
    char next_char;
    while(borze_stream >> next_char) {
        switch(next_char) {
            case '.':
                if(!context) std::cout << "0";
                else {
                    context = false;
                    std::cout << "1";
                }
                break;
            case '-':
                if(!context) context = true;
                else {
                    context = false;
                    std::cout << "2";
                }
                break;
        }
    }
    std::cout << std::endl;
}
