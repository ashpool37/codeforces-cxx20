#include <iostream>

int main() {
    unsigned test_count;
    std::cin >> test_count;

    for(unsigned _ = test_count; _--;) {
        unsigned x, y, k;
        std::cin >> x >> y >> k;

        for(unsigned i = 0; i < k;) {
            if (x == 1) {
                x += (k - i) % (y - 1);
                i = k;
            }
            else {
                unsigned di = std::min((x / y + 1) * y - x, k - i);
                x += di;
                i += di;
                while(x % y == 0) x = x / y;
            }
        }

        std::cout << x << std::endl;
    }
}
