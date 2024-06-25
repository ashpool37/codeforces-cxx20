#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cin.ignore(1, '\n');

    int players_passed = 0;
    int kth_player_points;
    while(players_passed < n) {
        int this_player_number = players_passed + 1;
        int this_player_points;
        std::cin >> this_player_points;

        if(this_player_points == 0) break;

        if(this_player_number < k) {
            players_passed++;
            continue;
        }
        if(this_player_number == k) {
            players_passed++;
            kth_player_points = this_player_points;
            continue;
        }

        if(this_player_points < kth_player_points) break;
        
        players_passed++;
    }

    std::cout << players_passed << std::endl;
}
