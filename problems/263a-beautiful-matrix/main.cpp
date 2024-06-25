#include <iostream>
#include <cmath>

int main() {
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; j++) {
            int element;
            std::cin >> element;
            if(element == 1) {
                std::cout << std::abs(i - 2) + std::abs(j - 2) << std::endl;
                goto done;
            }
        }
    }
done:
    return 0;
}
