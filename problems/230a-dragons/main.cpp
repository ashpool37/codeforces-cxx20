#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

struct Dragon {
    unsigned strength;
    unsigned reward;

    bool operator<(Dragon const& other) {
        return strength < other.strength;
    }
};

std::istream& operator>>(std::istream& in, Dragon& dragon) {
    in >> dragon.strength >> dragon.reward;
    return in;
}

int main() {
    unsigned strength, dragon_count;
    std::cin >> strength >> dragon_count;

    std::vector<Dragon> dragons;
    std::copy_n(std::istream_iterator<Dragon>(std::cin), dragon_count, std::back_inserter(dragons));
    std::ranges::sort(dragons, std::less());

    bool lost = false;
    for(Dragon const& dragon : dragons) {
        if(strength <= dragon.strength) {
            lost = true;
            break;
        }
        else strength += dragon.reward;
    }
    std::cout << (lost ? "NO" : "YES") << std::endl;
}
