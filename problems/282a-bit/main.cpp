#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(1, '\n');

    int x = 0;
    for(int _ = n; _--;) {
        std::string instruction;
        std::getline(std::cin, instruction);

        if(instruction == "X++" or instruction == "++X")
            x++;
        else
            x--;
    }

    std::cout << x << std::endl;
}
