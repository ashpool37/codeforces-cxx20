// Problem: 490A. Team Olympiad
// Problem statement: https://codeforces.com/problemset/problem/490/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>
#include <stack>
#include <algorithm>

int main() {
    unsigned pupil_count;
    std::cin >> pupil_count;

    std::stack<unsigned> programmers;
    std::stack<unsigned> mathematicians;
    std::stack<unsigned> sportspeople;

    for(unsigned pupil_id = 1; pupil_id <= pupil_count; pupil_id++) {
        unsigned pupil;
        std::cin >> pupil;

        switch(pupil) {
            case 1:
                programmers.push(pupil_id);
                break;
            case 2:
                mathematicians.push(pupil_id);
                break;
            case 3:
                sportspeople.push(pupil_id);
                break;
        }
    }

    size_t team_count = std::min({programmers.size(), mathematicians.size(), sportspeople.size()});
    std::cout << team_count << std::endl;

    while(team_count--) {
        std::cout << programmers.top() << " "
                  << mathematicians.top() << " "
                  << sportspeople.top() << std::endl;
        
        programmers.pop();
        mathematicians.pop();
        sportspeople.pop();
    }
}
