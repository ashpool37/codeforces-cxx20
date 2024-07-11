#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

int main() {
    unsigned test_count;
    std::cin >> test_count;

    while(test_count--) {
        unsigned casserole_length, piece_count;
        std::cin >> casserole_length >> piece_count;

        std::list<unsigned> pieces;
        unsigned biggest_piece_size = 0;
        auto biggest_piece = pieces.end();
        while(piece_count--) {
            unsigned piece;
            std::cin >> piece;
            pieces.push_back(piece);

            if(biggest_piece_size < piece) {
                biggest_piece = std::prev(pieces.end());
                biggest_piece_size = piece;
            }
        }

        unsigned operation_count = 0;
        for(auto piece = pieces.begin(); piece != pieces.end(); piece++) {
            if(piece != biggest_piece)
                operation_count += *piece * 2 - 1;
        }

        std::cout << operation_count << std::endl;
    }
}
