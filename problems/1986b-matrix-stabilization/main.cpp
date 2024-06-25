#include <iostream>
#include <optional>
#include <vector>
#include <algorithm>

using Matrix = std::vector<std::vector<unsigned>>;
using FindUnstableResult = std::optional<std::tuple<size_t, size_t, unsigned>>;

FindUnstableResult find_unstable(Matrix const& matrix, size_t n, size_t m) {
    for(size_t i = 0; i < n; i++) {
        for(size_t j = 0; j < m; j++) {
            unsigned max_neighbor = 0;
            if(i > 0) max_neighbor = std::max(max_neighbor, matrix[i - 1][j]);
            if(j > 0) max_neighbor = std::max(max_neighbor, matrix[i][j - 1]);
            if(i < n - 1) max_neighbor = std::max(max_neighbor, matrix[i + 1][j]);
            if(j < m - 1) max_neighbor = std::max(max_neighbor, matrix[i][j + 1]);

            if(max_neighbor < matrix[i][j])
                return std::optional(std::tuple{i, j, matrix[i][j] - max_neighbor});
        }
    }
    return std::nullopt;
}

int main() {
    unsigned test_count;
    std::cin >> test_count;
    for(auto _ = test_count; _--;) {
        size_t n, m;
        Matrix matrix;
        std::cin >> n >> m;
        for(size_t i = 0; i < n; i++) {
            matrix.emplace_back();
            for(size_t j = 0; j < m; j++) {
                unsigned a_ij;
                std::cin >> a_ij;
                matrix[i].push_back(a_ij);
            }
        }

        FindUnstableResult unstable;
        while((unstable = find_unstable(matrix, n, m))) {
            size_t i, j;
            unsigned amount;
            std::tie(i, j, amount) = *unstable;
            matrix[i][j] -= amount;
        }

        for(size_t i = 0; i < n; i++) {
            for(size_t j = 0; j < m-1; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << matrix[i][m-1] << std::endl;
        }
    }
}
