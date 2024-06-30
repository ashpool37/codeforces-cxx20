#include <iostream>

int main() {
    unsigned test_count;
    std::cin >> test_count;

    for(auto _ = test_count; _--;) {
        unsigned candy_count;
        std::cin >> candy_count;

        std::cout << (candy_count % 2 == 0 
                      ? candy_count / 2 - 1
                      : candy_count / 2)
                  << std::endl;
    }
}
