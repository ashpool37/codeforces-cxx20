#include <iostream>
#include <sstream>

int main() {
    unsigned feeling_levels;
    std::cin >> feeling_levels;

    for(unsigned level = 0; level < feeling_levels - 1; level++) {
        if(level % 2 == 0)
            std::cout << "I hate that ";
        else
            std::cout << "I love that ";
    }

    if(feeling_levels % 2 == 1)
        std::cout << "I hate it";
    else
        std::cout << "I love it";

    std::cout << std::endl;
}
