#include <iostream>

int main() {
    unsigned event_count;
    std::cin >> event_count;

    unsigned unsolved_count = 0;
    unsigned free_policemen = 0;

    while(event_count--) {
        int event;
        std::cin >> event;

        if(event == -1) {
            if(free_policemen == 0) unsolved_count++;
            else free_policemen--;
        }
        else free_policemen += event;
    }

    std::cout << unsolved_count << std::endl;
}
