#include <iostream>
#include <string>

int simulate_ball(std::string strip, int start_pos) {
    int position = start_pos;
    int seconds_elapsed = 0;
    while(position >= 0 and position < static_cast<int>(strip.size())) {
        if(strip[position] == '<') {
            strip[position] = '>';
            position--;
        }
        else {
            strip[position] = '<';
            position++;
        }
        seconds_elapsed++;
    }
    return seconds_elapsed;
}

int main() {
    int strips_count;
    std::cin >> strips_count;
    for(int _ = strips_count; _--;) {
        int strip_length;
        std::cin >> strip_length;
        std::cin.ignore(1, '\n');

        std::string strip;
        std::getline(std::cin, strip);

        for(int i = 0; i < strip_length; i++) {
            std::cout << simulate_ball(strip, i);
            if(i + 1 == strip_length)
                std::cout << std::endl;
            else
                [[likely]] std::cout << " ";
        }
    }
}
