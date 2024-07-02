#include <iostream>

int main() {
    unsigned competition_count;
    std::cin >> competition_count;

    unsigned competition_score;
    std::cin >> competition_score;
    unsigned min_score = competition_score;
    unsigned max_score = competition_score;
    competition_count--;
    unsigned notable_count = 0;
    while(competition_count--) {
        std::cin >> competition_score;
        if(competition_score > max_score) {
            notable_count++;
            max_score = competition_score;
        }
        else if(competition_score < min_score) {
            notable_count++;
            min_score = competition_score;
        }
    }
    std::cout << notable_count << std::endl;
}
