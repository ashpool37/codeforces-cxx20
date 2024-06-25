#include <iostream>
#include <algorithm>

int main() {
    int m, n;
    std::cin >> m >> n;

    if(m % 2 == 0) {
        std::cout << m / 2 * n;
    }
    else if(n % 2 == 0) {
        std::cout << n / 2 * m;
    }
    else {
        if(n > m) std::swap(m, n);
        int vertical_dominoes = 0;
        if(m > 2)
            vertical_dominoes = m / 2 * n;
        int horizontal_dominoes = n / 2;
        std::cout << vertical_dominoes + horizontal_dominoes << std::endl;
    }
}
