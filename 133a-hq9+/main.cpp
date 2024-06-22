#include <algorithm>
#include <iostream>
#include <ranges>
#include <set>

std::set<char> const printing_chars = {'H', 'Q', '9'};

int main() {
    std::set<char> code_chars;
    std::ranges::copy(std::ranges::istream_view<char>(std::cin),
                      std::inserter(code_chars, code_chars.begin()));
    
    std::set<char> intersection;
    std::ranges::set_intersection(code_chars, printing_chars, 
                                  std::inserter(intersection, intersection.begin()));
    
    std::cout << (intersection.size() != 0 ? "YES" : "NO") << std::endl;
}
