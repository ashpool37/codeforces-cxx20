#include <iostream>

int main() {
    unsigned room_count [[maybe_unused]];
    std::cin >> room_count;

    unsigned suitable_room_count = 0;
    for(unsigned _ = room_count; _--;) {
        unsigned occupied, capacity;
        std::cin >> occupied >> capacity;
        if(capacity - occupied >= 2)
            suitable_room_count++;
    }

    std::cout << suitable_room_count << std::endl;
}
