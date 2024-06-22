#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include <format>

int main() {
    unsigned drink_count; 
    std::cin >> drink_count;
    
    std::vector<unsigned> mass_fractions;
    mass_fractions.reserve(drink_count);
    std::ranges::copy(std::ranges::istream_view<unsigned>(std::cin),
                      std::back_inserter(mass_fractions));
    
    double cocktail_mass_fraction = 
        static_cast<double>(std::accumulate(mass_fractions.begin(), mass_fractions.end(), 0u))
        / static_cast<double>(drink_count);
    
    std::cout << std::format("{}", cocktail_mass_fraction) << std::endl;
}
