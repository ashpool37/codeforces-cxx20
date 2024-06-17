#include <iostream>

void do_swaps(std::string& positions) {
    if(positions.size() == 0) return;
    for(unsigned i = 0; i < positions.size() - 1; i++) {
        if(positions[i] == 'B' and positions[i+1] == 'G') {
            std::swap(positions[i], positions[i+1]);
            i++;
        }
    }
}

int main() {
    unsigned student_count [[maybe_unused]], seconds_elapsed;
    std::string positions;
    std::cin >> student_count >> seconds_elapsed;
    std::cin.ignore(1, '\n');
    std::getline(std::cin, positions);
    
    for(unsigned _ = seconds_elapsed; _--;)
        do_swaps(positions);

    std::cout << positions << std::endl;
}
