// Problem: 43A. Football
// Problem statement: https://codeforces.com/problemset/problem/43/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    unsigned goal_count;
    std::cin >> goal_count;
    std::cin.ignore(1, '\n');

    std::unordered_map<std::string, unsigned> goals;
    while(goal_count--) {
        std::string team;
        std::getline(std::cin, team);
        goals[team]++;
    }
    auto max_goals = std::ranges::max_element(goals, [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    std::cout << max_goals->first << std::endl;
}
