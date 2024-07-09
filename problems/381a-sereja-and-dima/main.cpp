#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>

enum Move {
    MOVE_SEREJA,
    MOVE_DIMA,
};

int main() {
    unsigned card_count;
    std::cin >> card_count;

    std::deque<unsigned> cards;
    std::copy_n(std::istream_iterator<unsigned>(std::cin), card_count,
                std::back_inserter(cards));


    Move move = MOVE_SEREJA;
    unsigned points_sereja = 0;
    unsigned points_dima = 0;
    while(cards.size() > 0) {   
        unsigned card;
        if(cards.back() > cards.front()) {
            card = cards.back();
            cards.pop_back();
        }
        else {
            card = cards.front();
            cards.pop_front();
        }
        if(move == MOVE_SEREJA) {
            points_sereja += card;
            move = MOVE_DIMA;
        }
        else { 
            points_dima += card;
            move = MOVE_SEREJA;
        }
    }
    std::cout << points_sereja << " " << points_dima << std::endl;
}
