#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int solve_total = 0;
    for(auto _ = n; _--;) {
        int sure;
        int sure_total = 0;
        for (auto _ = 3; _--;) {
            std::cin >> sure;
            sure_total += sure;
        }
        if(sure_total >= 2) solve_total++;
    }

    std::cout << solve_total << std::endl;
}
