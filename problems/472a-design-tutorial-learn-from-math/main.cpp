// Problem: 472A. Design Tutorial: Learn from Math
// Problem statement: https://codeforces.com/problemset/problem/472/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>

template<typename T>
auto from_istream(std::istream& ins) 
{
    T res;
    ins >> res;
    return res;
}

int main() {
    unsigned number = from_istream<unsigned>(std::cin);
    if(number % 2 == 0) std::cout << 4 << " " << number - 4 << std::endl;
    else std::cout << 9 << " " << number - 9 << std::endl;
}
