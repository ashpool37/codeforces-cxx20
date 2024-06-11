#include <iostream>

int main() {
    int w;
    std::cin >> w;
    if(w >= 4 and w % 2 == 0)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}
