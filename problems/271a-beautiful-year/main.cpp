#include <iostream>
#include <string>
#include <set>

bool is_beautiful_year(unsigned year) {
    std::string digits_string = std::to_string(year);
    std::set digits = std::set(digits_string.begin(), digits_string.end());
    return digits.size() == digits_string.size();
}

int main() {
    unsigned year;
    std::cin >> year;
    
    unsigned next_beautiful_year = year + 1;
    while(!is_beautiful_year(next_beautiful_year))
        next_beautiful_year++;

    std::cout << next_beautiful_year << std::endl;
}
