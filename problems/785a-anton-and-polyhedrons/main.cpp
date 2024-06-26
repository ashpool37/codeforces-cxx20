#include <iostream>
#include <iterator>
#include <map>

std::map<std::string, unsigned> const face_counts = {
    {"Tetrahedron", 4},
    {"Cube", 6},
    {"Octahedron", 8},
    {"Dodecahedron", 12},
    {"Icosahedron", 20},
};

int main() {
    unsigned polyhedron_count;
    std::cin >> polyhedron_count;
    std::cin.ignore(1, '\n');

    unsigned total_faces = 0;
    for(auto _ = polyhedron_count; _--;) {
        std::string polyhedron_name;
        std::getline(std::cin, polyhedron_name);
    
        total_faces += face_counts.at(polyhedron_name);
    }

    std::cout << total_faces << std::endl;
}
