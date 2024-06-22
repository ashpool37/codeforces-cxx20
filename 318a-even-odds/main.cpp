#include <iostream>
#include <cstdint>

int main() {
    std::uintmax_t n, k;
    std::cin >> n >> k;

    std::uintmax_t kth_number;
    if(n % 2 == 0) {
        if(k <= n / 2)
            kth_number = 2 * k - 1;
        else
            kth_number = 2 * k - n;
    }
    else {
        if(k <= n / 2 + 1)
            kth_number = 2 * k - 1;
        else
            kth_number = 2 * k - n - 1;
    }

    std::cout << kth_number << std::endl;
}
