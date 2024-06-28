#include <iostream>

int main() {
    unsigned group_count;
    std::cin >> group_count;

    unsigned quadruplet_count = 0;
    unsigned triplet_count = 0;
    unsigned pair_count = 0;
    unsigned singleton_count = 0;

    for(auto _ = group_count; _--;) {
        unsigned group_size;
        std::cin >> group_size;

        switch(group_size) {
            case 4:
                quadruplet_count++;
                break;
            case 3:
                triplet_count++;
                break;
            case 2:
                pair_count++;
                break;
            case 1:
                singleton_count++;
                break;
        }
    }

    unsigned car_count = 0;

    car_count += quadruplet_count;
    quadruplet_count = 0u;
    car_count += triplet_count;
    singleton_count -= std::min(triplet_count, singleton_count);
    triplet_count = 0u;
    car_count += pair_count / 2u;
    pair_count = pair_count % 2u;
    if(pair_count == 1u) {
        car_count += 1u;
        singleton_count -= std::min(2u, singleton_count);
        pair_count = 0;
    }
    car_count += singleton_count / 4u;
    singleton_count = singleton_count % 4u;
    if(singleton_count != 0)
        car_count += 1u;

    std::cout << car_count << std::endl;
}
