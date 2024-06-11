#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(1, '\n');

    for(int i = 0; i < n; i++) {
        std::string str;
        std::getline(std::cin, str);
        if(str.size() <= 10)
            std::cout << str
                      << std::endl;
        else 
            std::cout << str[0]
                      << str.size() - 2
                      << str[str.size() - 1]
                      << std::endl;
    }
}
