#include <iostream>

int main() {
    unsigned red_sock_count, blue_sock_count;
    std::cin >> red_sock_count >> blue_sock_count;

    if(red_sock_count > blue_sock_count) std::swap(red_sock_count, blue_sock_count);

    std::cout << red_sock_count << " " << ((blue_sock_count - red_sock_count) / 2) << std::endl;
}
