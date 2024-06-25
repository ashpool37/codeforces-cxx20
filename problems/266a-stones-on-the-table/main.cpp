#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(1, '\n');

    std::string colours;
    std::getline(std::cin, colours);

    unsigned char last_colour = '\0';
    int stones_removed = 0;
    for(unsigned char colour : colours) {
        if(last_colour == colour) 
            stones_removed++;
        last_colour = colour;
    }

    std::cout << stones_removed << std::endl;
}
