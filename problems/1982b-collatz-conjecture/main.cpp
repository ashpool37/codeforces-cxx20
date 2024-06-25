#include <iostream>
#include <cmath>

unsigned modified_collatz(unsigned x, unsigned y) {
    x += 1;
    while(x % y == 0) x = x / y;
    return x;
}

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
            else if(x < y) {
                unsigned di = std::min(y - x, k - i);
                x += di;
                if(x == y) x = 1;
                i += di;
            }
            else {
                x = modified_collatz(x, y);
                i++;
            }
        }

        std::cout << x << std::endl;
    }
}
