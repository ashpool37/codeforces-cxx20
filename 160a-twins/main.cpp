#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main() {
    unsigned coin_count;
    std::cin >> coin_count;

    std::vector<unsigned> coins;
    coins.reserve(coin_count);
    std::ranges::copy(std::ranges::istream_view<unsigned>(std::cin),
                      std::back_inserter(coins));
    std::ranges::sort(coins, std::ranges::greater());
    unsigned coin_sum = std::accumulate(coins.begin(), coins.end(), 0u);
    unsigned take_sum = 0;
    unsigned take_count = 0;
    for(unsigned coin : coins) {
        take_sum += coin;
        take_count++;
        if(take_sum > coin_sum - take_sum) break;
    }

    std::cout << take_count << std::endl;
}
