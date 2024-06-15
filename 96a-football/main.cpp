#include <iostream>
#include <string>

int main() {
    std::string positions;
    std::getline(std::cin, positions);

    int contiguous_players = 0;
    char contiguous_team = '\0';
    bool dangerous = false;
    for(char c : positions) {
        if(c == contiguous_team) {
            contiguous_players++;
            if(contiguous_players >= 7) {
                dangerous = true;
                break;
            }
        }
        else {
            contiguous_team = c;
            contiguous_players = 1;
        }
    }
    std::cout << (dangerous ? "YES" : "NO") << std::endl;
}
