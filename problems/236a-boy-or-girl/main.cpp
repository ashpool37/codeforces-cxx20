#include <iostream>
#include <set>

int main() {
    std::string username;
    std::getline(std::cin, username);

    auto username_symbols = std::set<unsigned char>(username.begin(), username.end());
    std::cout << (username_symbols.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << std::endl;
}
