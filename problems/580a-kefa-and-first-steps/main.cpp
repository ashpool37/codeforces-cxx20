#include <iostream>
#include <sys/types.h>

int main() {
    unsigned day_count;
    std::cin >> day_count;

    unsigned max_nodecrese_segment_length = 1;
    unsigned nodecrease_segment_length = 1;
    unsigned last_profit;
    std::cin >> last_profit;

    for(auto _ = day_count - 1; _--;) {
        unsigned profit;
        std::cin >> profit;

        if(profit >= last_profit) {
            nodecrease_segment_length++;
            max_nodecrese_segment_length = std::max(max_nodecrese_segment_length, 
                                                    nodecrease_segment_length);
        }
        else {
            nodecrease_segment_length = 1;
        }
        
        last_profit = profit;
    }

    std::cout << max_nodecrese_segment_length << std::endl;
}
