#include <iostream>

int main() {
    int force_count;
    std::cin >> force_count;

    int x_sum = 0, y_sum = 0, z_sum = 0;
    for(int _ = force_count; _--;) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x_sum += x;
        y_sum += y;
        z_sum += z;
    }
    if(x_sum == 0 and y_sum == 0 and z_sum == 0)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}
