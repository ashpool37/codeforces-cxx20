#include <cmath>
#include <iostream>

double hard_ceil(double x) {
    double ceil = std::ceil(x);
    double floor = std::floor(x);
    if(floor == ceil)
        return ceil + 1;
    else
        return ceil;
}

int main() {
    double a, b;
    std::cin >> a >> b;

    std::cout << static_cast<int>(hard_ceil(std::log(b/a)/std::log(1.5)));
}
