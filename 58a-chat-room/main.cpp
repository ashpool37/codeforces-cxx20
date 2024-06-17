#include <iostream>

// check if r2 is a subsequence of r1.
// the subsequence need not be contiguous.
template<std::ranges::input_range R1, std::ranges::input_range R2>
bool includes_spliced(R1 r1, R2 r2) {
    auto r2_it = r2.begin();
    for(auto r1_el : r1) {
        if(r1_el == *r2_it) r2_it++;
    }
    return r2_it == r2.end();
}

std::string greeting_ideal = "hello";

int main() {
    std::string greeting;
    std::getline(std::cin, greeting);
    bool greeting_success = includes_spliced(greeting, greeting_ideal);
    std::cout << (greeting_success ? "YES" : "NO") << std::endl;
}
