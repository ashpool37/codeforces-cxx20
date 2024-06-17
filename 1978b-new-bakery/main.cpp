#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

intmax_t profit(intmax_t promo_bun_count, intmax_t bun_count,
                 intmax_t usual_price, intmax_t promo_price_base) {
    return promo_bun_count * (promo_price_base - usual_price) - (promo_bun_count * (promo_bun_count - 1) / 2)
           + bun_count * usual_price;
}

int main() {
    unsigned test_count;
    std::cin >> test_count;

    for(unsigned _ = test_count; _--;) {
        intmax_t bun_count, usual_price, promo_price_base;
        std::cin >> bun_count >> usual_price >> promo_price_base;

        std::vector<intmax_t> potential_profits;
        potential_profits.reserve(4);

        potential_profits.push_back(profit(0, bun_count, usual_price, promo_price_base));
        potential_profits.push_back(profit(std::min(bun_count, promo_price_base),
                                    bun_count, usual_price, promo_price_base));
        intmax_t vertex_floor = static_cast<intmax_t>(std::floor(promo_price_base - usual_price + 0.5L));
        intmax_t vertex_ceil = static_cast<intmax_t>(std::ceil(promo_price_base - usual_price + 0.5L));

        if(0 < vertex_floor and vertex_floor < std::min(bun_count, promo_price_base)) {
            potential_profits.push_back(profit(vertex_floor, bun_count, usual_price, promo_price_base));
        }
        if(0 < vertex_ceil and vertex_ceil < std::min(bun_count, promo_price_base)) {
            potential_profits.push_back(profit(vertex_ceil, bun_count, usual_price, promo_price_base));
        }

        std::cout << std::ranges::max(potential_profits) << std::endl;
    }
}
