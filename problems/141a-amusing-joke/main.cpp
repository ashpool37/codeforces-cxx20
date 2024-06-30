#include <algorithm>
#include <iostream>

int main() {
    std::string host_name;
    std::string guest_name;
    std::string letters;

    std::getline(std::cin, host_name);
    std::getline(std::cin, guest_name);
    std::getline(std::cin, letters);

    std::string original_letters = host_name + guest_name;

    std::cout << (std::ranges::is_permutation(original_letters, letters) ? "YES" : "NO")
              << std::endl;
}
