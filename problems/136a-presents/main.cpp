#include <iostream>
#include <ranges>
#include <vector>

int main() {
    unsigned guest_count;
    std::cin >> guest_count;

    std::vector<std::optional<unsigned>> gift_receivers(guest_count, std::nullopt);

    for(unsigned gift_giver = 1; gift_giver <= guest_count; gift_giver++) {
        unsigned gift_receiver;
        std::cin >> gift_receiver;
        gift_receivers[gift_receiver - 1] = gift_giver;
    }

    std::cout << gift_receivers[0].value();
    for(auto gift_receiver : gift_receivers | std::views::drop(1)) {
        std::cout << " ";
        std::cout << gift_receiver.value();
    }
    std::cout << std::endl;
}
