#include <iostream>

void print_line(unsigned m) {
    std::cout << std::string(m, '#') << std::endl;
}

void print_right_bend(unsigned m) {
    std::cout << std::string(m-1, '.') << "#" << std::endl;
}

void print_left_bend(unsigned m) {
    std::cout << "#" << std::string(m-1, '.') << std::endl;
}

template<typename T>
T sub2(T& n) {
    T temp = n; // Store the current value of n
    n -= 2;       // Subtract 2 from n
    return temp;  // Return the original value of n
}

int main() {
    unsigned n, m;
    std::cin >> n >> m;

    print_line(m);
    bool bend_right = true;
    while(sub2(n) > 1) {
        if(bend_right) print_right_bend(m);
        else print_left_bend(m);
        bend_right = !bend_right;
        print_line(m);
    }
}
