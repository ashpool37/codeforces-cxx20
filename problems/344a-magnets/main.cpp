#include <iostream>

int main() {
    unsigned magnet_count;
    std::cin >> magnet_count;
    std::cin.ignore(1, '\n');

    std::string last_magnet = "";
    unsigned group_count = 0;
    for(unsigned _ = magnet_count; _--;) {
        std::string magnet;
        std::getline(std::cin, magnet);
        if(magnet != last_magnet) group_count++;
        last_magnet = magnet;
    }

    std::cout << group_count << std::endl;
}
