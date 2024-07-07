#include <iostream>
#include <cstdint>

using uintmax_t  = std::uintmax_t;

int main() {
    unsigned house_count, activity_count;
    std::cin >> house_count >> activity_count;

    unsigned position = 1;
    uintmax_t time_elapsed = 0;
    while(activity_count--) {
        unsigned next_house;
        std::cin >> next_house;

        unsigned time_to_next_house = (next_house < position)
                                      ? house_count - position + next_house
                                      : next_house - position;
        time_elapsed += time_to_next_house;

        position = next_house;
    }

    std::cout << time_elapsed << std::endl;
}
