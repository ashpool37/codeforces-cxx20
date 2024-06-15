#include <iostream>

int tanya_sub1 (int x) {
    if(x % 10 == 0) {
        return x / 10;
    }
    else [[likely]] return x - 1;
}

int main() {
    int number, sub_count;
    std::cin >> number >> sub_count;
    for(int _ = sub_count; _--;) {
        number = tanya_sub1(number);
    }
    std::cout << number << std::endl;
}
