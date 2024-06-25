#include <iostream>

int main() {
    unsigned game_count;
    std::cin >> game_count;
    std::cin.ignore(1, '\n');
    
    unsigned anton_win_count = 0, danik_win_count = 0;
    for(unsigned _ = game_count; _--;) {
        char win;
        std::cin >> win;

        if(win == 'A') anton_win_count++;
        else danik_win_count++;
    }
    if(anton_win_count > danik_win_count) std::cout << "Anton" << std::endl;
    else if (danik_win_count > anton_win_count) std::cout << "Danik" << std::endl;
    else std::cout << "Friendship" << std::endl;
}
