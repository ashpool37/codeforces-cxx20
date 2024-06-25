#include <iostream>
#include <cstdint>

int main() {
    uintmax_t n, m, a;
    std::cin >> n >> m >> a;

    uintmax_t x_tiles = (n - 1) / a + 1;
    uintmax_t z_tiles = (m - 1) / a + 1;

    std::cout << x_tiles * z_tiles << std::endl;
}
