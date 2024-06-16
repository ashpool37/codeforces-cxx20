#include <iostream>

int main() {
    unsigned station_count;
    std::cin >> station_count;

    unsigned capacity = 0;
    unsigned passengers_now = 0;
    for(unsigned _ = station_count; _--;) {
        unsigned passengers_exited, passengers_entered;
        std::cin >> passengers_exited >> passengers_entered;

        passengers_now -= passengers_exited;
        passengers_now += passengers_entered;

        capacity = std::max(capacity, passengers_now);
    }

    std::cout << capacity << std::endl;
}
