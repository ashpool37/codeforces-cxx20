// Problem: 703A. Mishka and Game
// Problem statement: https://codeforces.com/problemset/problem/703/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>

int main() {
    unsigned round_count;
    std::cin >> round_count;

    unsigned mishka_wins = 0, chris_wins = 0;
    while(round_count--) {
        unsigned mishka_points, chris_points;
        std::cin >> mishka_points >> chris_points;

        if(mishka_points > chris_points) mishka_wins++;
        else if(chris_points > mishka_points) chris_wins++;
    }
    if(mishka_wins > chris_wins) std::cout << "Mishka" << std::endl;
    else if(chris_wins > mishka_wins) std::cout << "Chris" << std::endl;
    else std::cout << "Friendship is magic!^^" << std::endl;
}
