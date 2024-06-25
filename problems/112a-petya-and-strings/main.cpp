#include <algorithm>
#include <compare>
#include <iostream>
#include <string>

std::weak_ordering cmp_icase(unsigned char a, unsigned char b) {
    return std::tolower(a) <=> std::tolower(b);
}

int ordering_to_int(std::weak_ordering cmp) {
    if(std::is_gt(cmp))
        return 1;
    else if(std::is_lt(cmp))
        return -1;
    else
        return 0;
}

int main() {
    std::string first_string;
    std::string second_string;

    std::getline(std::cin, first_string);
    std::getline(std::cin, second_string);

    std::cout << ordering_to_int(std::lexicographical_compare_three_way(first_string.begin(), first_string.end(),
        second_string.begin(), second_string.end(), cmp_icase))
        << std::endl;
}
