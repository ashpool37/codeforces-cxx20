#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string remix;
    std::getline(std::cin, remix);

    remix = std::regex_replace(remix, std::regex("^(WUB)*"), "");
    remix = std::regex_replace(remix, std::regex("(WUB)*$"), "");
    remix = std::regex_replace(remix, std::regex("(WUB)+"), " ");

    std::cout << remix << std::endl;
}
