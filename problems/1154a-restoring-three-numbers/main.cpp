#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<unsigned> sums;
    std::copy_n(std::istream_iterator<unsigned>(std::cin), 4, std::back_inserter(sums));

    std::ranges::sort(sums, std::greater());

    unsigned sum_ab, sum_ac, sum_bc, sum_abc;
    sum_abc = sums[0];
    sum_ab = sums[1];
    sum_ac = sums[2];
    sum_bc = sums[3];

    unsigned a = sum_abc - sum_bc;
    unsigned b = sum_abc - sum_ac;
    unsigned c = sum_abc - sum_ab;

    std::cout << a << " " << b << " " << c << std::endl;
}
