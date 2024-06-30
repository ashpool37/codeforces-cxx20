#include <iostream>
#include <vector>

struct Team {
    unsigned home_uniform;
    unsigned guest_uniform;
};

int main() {
    unsigned team_count;
    std::cin >> team_count;

    std::vector<Team> teams;
    for(unsigned _ = team_count; _--;) {
        Team team;
        std::cin >> team.home_uniform >> team.guest_uniform;
        teams.push_back(team);
    }

    unsigned conflict_count = 0;
    for(auto host = teams.begin(); host != teams.end(); host++) {
        for(auto guest = teams.begin(); guest != teams.end(); guest++) {
            if(host != guest) {
                [[likely]]
                if(host->home_uniform == guest->guest_uniform) conflict_count++;
            }
        }
    }

    std::cout << conflict_count << std::endl;
}
