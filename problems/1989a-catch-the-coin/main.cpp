#include <iostream>

int main() {
    unsigned coin_count;
    std::cin >> coin_count;

    for(auto _ = coin_count; _--;) {
        int x, y;
        std::cin >> x >> y;

        std::cout << (y >= -1 ? "YES" : "NO") << std::endl;
    }
}
