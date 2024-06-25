#include <iostream>

int main() {
    unsigned friend_count, fence_height;
    std::cin >> friend_count >> fence_height;

    unsigned road_capacity = 0;
    for(unsigned _ = friend_count; _--;) {
        unsigned friend_height;
        std::cin >> friend_height;

        road_capacity += (friend_height > fence_height ? 2 : 1);
    }

    std::cout << road_capacity << std::endl;
}
