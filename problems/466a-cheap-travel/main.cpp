// Problem: 466A. Cheap Travel
// Problem statement: https://codeforces.com/problemset/problem/466/A?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

#include <iostream>

int main() {
    unsigned test_count = 1;
    // std::cin >> test_count;
    while(test_count--) {
        unsigned ride_count, subscription_ride_count, ride_price, subscription_price;
        std::cin >> ride_count >> subscription_ride_count >> ride_price >> subscription_price;

        bool subscription_makes_sense = ride_price * subscription_ride_count > subscription_price;
        if(subscription_makes_sense) {
            unsigned result = (ride_count / subscription_ride_count * subscription_price);
            result += std::min(ride_price * (ride_count % subscription_ride_count),
                               subscription_price);
            std::cout << result << std::endl;
        }
        else std::cout << ride_count * ride_price << std::endl;
    }
}
