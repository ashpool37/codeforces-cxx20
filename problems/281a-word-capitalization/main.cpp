#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);

    std::cout << static_cast<char>(std::toupper(str[0]))
              << std::string_view(str).substr(1, str.size() - 1)
              << std::endl;
}
