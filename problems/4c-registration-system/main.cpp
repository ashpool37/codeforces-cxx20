#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, unsigned> name_db;
    unsigned name_count;
    std::cin >> name_count;
    std::cin.ignore(1, '\n');

    for(auto _ = name_count; _--;) {
        std::string name;
        std::getline(std::cin, name);

        auto db_it = name_db.find(name);
        if(db_it == name_db.end()) {
            name_db.insert({name, 0});
            std::cout << "OK" << std::endl;
        }
        else {
            db_it->second++;
            std::cout << name + std::to_string(db_it->second) << std::endl;
        }
    }
}
