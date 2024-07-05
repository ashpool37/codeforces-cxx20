#include <iostream>
#include <algorithm>

int main() {
    unsigned friend_count;
    unsigned bottle_count, bottle_volume;
    unsigned lime_count, lime_slices;
    unsigned salt_total;
    unsigned drink_required, salt_required;

    std::cin >> friend_count
             >> bottle_count >> bottle_volume
             >> lime_count >> lime_slices
             >> salt_total
             >> drink_required >> salt_required;
    
    unsigned drink_total = bottle_count * bottle_volume;
    unsigned lime_total = lime_count * lime_slices;

    std::cout << std::min({
        drink_total / drink_required / friend_count,
        salt_total / salt_required / friend_count,
        lime_total / friend_count,
    }) << std::endl;
}
