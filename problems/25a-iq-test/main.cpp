#include <iostream>
#include <optional>

int main() {
    unsigned number_count;
    std::cin >> number_count;

    unsigned odd_count = 0;
    unsigned even_count = 0;
    std::optional<unsigned> last_odd_pos;
    std::optional<unsigned> last_even_pos;
    unsigned i = 1;
    for(; i <= number_count; i++) {
        unsigned number;
        std::cin >> number;

        if(number % 2 == 0) {
            even_count++;
            last_even_pos = i;
        }
        else {
            odd_count++;
            last_odd_pos = i;
        }

        if((odd_count == 1 and odd_count < even_count)) {
            std::cout << last_odd_pos.value() << std::endl;
            break;
        }
        else if((even_count == 1 and even_count < odd_count)) {
            std::cout << last_even_pos.value() << std::endl;
            break;
        }   
    }
}
