#include <iostream>

unsigned const time_left = 240u;

int main() {
    unsigned problem_count, travel_time;
    std::cin >> problem_count >> travel_time;

    unsigned solve_time = 0, solve_count = 0;
    for(unsigned problem = 1; problem <= problem_count; problem++) {
        solve_time += 5 * problem;
        if (solve_time + travel_time <= time_left) solve_count++;
        else break;
    }

    std::cout << solve_count << std::endl;
}
